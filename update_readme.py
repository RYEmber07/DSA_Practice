import os
import re
from urllib.parse import quote  # Encode folder names for GitHub links

README_FILE = "README.md"


def detect_existing_folders():
    folders = []
    for folder in sorted(os.listdir()):
        if os.path.isdir(folder):  # Ensure it's a folder
            match = re.match(r"DAY_(\d{2})", folder)  # Extract day number
            if match:
                day_num = match.group(1)
                topic_match = re.search(r"\(([^)]+)\)", folder)
                topic = f" ({topic_match.group(1)})" if topic_match else ""
                folders.append((day_num, folder, topic))
    return folders


def update_readme():
    if not os.path.exists(README_FILE):
        print("README.md not found. Exiting.")
        return

    with open(README_FILE, "r", encoding="utf-8") as file:
        lines = file.readlines()

    start_index = None
    end_index = None
    for i, line in enumerate(lines):
        if "📅 Practice Days" in line:
            start_index = i + 2  # Start after header
        if "✍️ Signing Off" in line:
            end_index = i
            break

    if start_index is None or end_index is None:
        print("Practice Days section not found. Exiting.")
        return

    folders = detect_existing_folders()
    new_practice_days = "| 📅 Day | 🔗 Link |\n|--------|---------|\n"
    for day_num, folder_name, topic in folders:
        # Encode folder name for GitHub links
        encoded_link = quote(folder_name)
        new_practice_days += f"| 🟢 DAY {day_num}{topic} | [{folder_name}]({encoded_link}) |\n"

    updated_lines = lines[:start_index] + \
        [new_practice_days] + lines[end_index:]

    with open(README_FILE, "w", encoding="utf-8") as file:
        file.writelines(updated_lines)

    print("✅ README.md updated successfully!")


if __name__ == "__main__":
    update_readme()
