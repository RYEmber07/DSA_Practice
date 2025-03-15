import os
import re

README_FILE = "README.md"


def extract_existing_sections():
    """Extracts the header, practice days section, and signing off sections."""
    if not os.path.exists(README_FILE):
        return None, None, None

    with open(README_FILE, "r", encoding="utf-8") as file:
        lines = file.readlines()

    header, practice_days, signing_off = [], [], []
    section = "header"

    for line in lines:
        if line.strip() == "## 📅 Practice Days":
            section = "practice_days"
            practice_days.append(line)
            continue
        elif line.strip() == "## ✍️ Signing Off":
            section = "signing_off"
            signing_off.append(line)
            continue

        if section == "header":
            header.append(line)
        elif section == "practice_days":
            practice_days.append(line)
        elif section == "signing_off":
            signing_off.append(line)

    return header, practice_days, signing_off


def extract_existing_topics(practice_days):
    """Extracts topics (like Binary Search, Linked List, etc.) from the existing table."""
    topic_pattern = re.compile(r"\|\s*🟢 DAY (\d{2})\s*(\(.*\))?\s*\|")
    topics = {}

    for line in practice_days:
        match = topic_pattern.search(line)
        if match:
            day = int(match.group(1))
            topic = match.group(2) if match.group(2) else ""
            topics[day] = topic.strip()

    return topics


def generate_practice_days_section(existing_topics):
    """Generates the Practice Days section dynamically while preserving topics."""
    num_days = max(existing_topics.keys(), default=-1) + \
        1  # Auto-detect max day
    new_days = num_days + 1  # Increment to add a new day

    practice_days = ["\n## 📅 Practice Days\n",
                     "🔹 Click on any Day to explore the problems!\n\n"]
    practice_days.append("| 📅 Day | 🔗 Link |\n|--------|---------|\n")

    for day in range(new_days):
        day_label = f"🟢 DAY {day:02d}"
        day_link = f"[DAY_{day:02d}](DAY_{day:02d})"

        # Preserve existing topics
        topic = existing_topics.get(day, "")
        if topic:
            day_label += f" {topic}"

        practice_days.append(f"| {day_label} | {day_link} |\n")

    return practice_days


def update_readme():
    """Updates README.md while preserving custom topics in the Practice Days section."""
    header, practice_days, signing_off = extract_existing_sections()

    if not header or not signing_off:
        print("Error: Could not parse existing README.md structure!")
        return

    existing_topics = extract_existing_topics(practice_days)
    updated_practice_days = generate_practice_days_section(existing_topics)

    new_readme_content = header + updated_practice_days + ["\n"] + signing_off

    with open(README_FILE, "w", encoding="utf-8") as file:
        file.writelines(new_readme_content)

    print("✅ README.md updated successfully!")


if __name__ == "__main__":
    update_readme()
