import os

# Get all directories that start with "DAY_"
folders = sorted(
    [f for f in os.listdir() if f.startswith("DAY_") and os.path.isdir(f)],
    # Extract only the number for sorting
    key=lambda x: int(x.split("_")[1].split()[0])
)

# Generate markdown content
lines = []

# Section: Practice Days
lines.append("## 📅 Practice Days")  # Make it a header
lines.append("🔹 Click on any Day to explore the problems!\n")  # Description
lines.append("| 📅 Day | 🔗 Link |")
lines.append("|---|---|")

for folder in folders:
    parts = folder.split("_", 1)  # Splitting at first "_"
    day_number = parts[1].split()[0]  # Extract just the number
    day_name = parts[1]  # Keep full folder name for display

    # Show full name but keep clean link
    lines.append(f"| 🟢 {day_name} | [{day_number}]({folder}) |")

# Section: Signing Off
lines.append("\n## ✍️ Signing Off")  # Now "Signing Off" is also a header
lines.append(
    "Thanks for stopping by! 😃 This repository is my journey through DSA—learning, practicing, "
    "and improving one problem at a time. If you found this helpful, consider starring ⭐ the repo, "
    "sharing it, or contributing.\n"
)
lines.append("Until next time, happy coding & keep solving! 🚀\n")
lines.append("~ RYEMBER07")

# Write to README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write("\n".join(lines))
