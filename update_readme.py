import os
import re

# Constants
README_FILE = "README.md"
HEADER = """# 🚀 DSA Practice Repository
Welcome to my DSA Practice Repository! 🎯 This is where I store my daily practice problems for Data Structures and Algorithms (DSA). Each day contains 2-3 coding problems with solutions.

📂 **Folder Structure**
Each folder represents a day of practice and contains coding problems along with solutions.

📅 **Practice Days**
🔹 Click on any Day to explore the problems!

| 📅 Day | 🔗 Link |
|--------|---------|
"""

FOOTER = """\n✍️ **Signing Off**
Thanks for stopping by! 😃 This repository is my journey through DSA—learning, practicing, and improving one problem at a time. If you found this helpful, consider starring ⭐ the repo, sharing it, or contributing.

Until next time, happy coding & keep solving! 🚀

~ RYEMBER07
"""

# Get all folders that start with "DAY_"
folders = [f for f in os.listdir() if f.startswith("DAY_")
           and os.path.isdir(f)]

# Extract numeric day values safely


def extract_day_number(folder_name):
    match = re.search(r"DAY_(\d+)", folder_name)  # Extracts only the number
    # Default to inf if no number
    return int(match.group(1)) if match else float('inf')


# Sort folders by their extracted numeric day
folders = sorted(folders, key=extract_day_number)

# Generate table rows
rows = [
    f"| 🟢 {folder.replace('_', ' ')} | [{folder}]({folder}) |" for folder in folders]

# Write to README.md
with open(README_FILE, "w", encoding="utf-8") as f:
    f.write(HEADER + "\n".join(rows) + FOOTER)

print("✅ README.md updated successfully!")
