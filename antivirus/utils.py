import os
import shutil
from datetime import datetime

# Move infected file to quarantine folder
def quarantine_file(file_path, quarantine_folder="quarantine"):
    if not os.path.exists(quarantine_folder):
        os.makedirs(quarantine_folder)  # Create quarantine folder if it doesn't exist
    try:
        file_name = os.path.basename(file_path)
        new_path = os.path.join(quarantine_folder, file_name)
        shutil.move(file_path, new_path)
        print(f"[!] File moved to quarantine: {new_path}")
    except Exception as e:
        print(f"[Error] Could not quarantine file: {e}")

# Log scan result to a log file
def log_result(message, log_folder="logs"):
    if not os.path.exists(log_folder):
        os.makedirs(log_folder)  # Create logs folder if it doesn't exist
    log_file = os.path.join(log_folder, "scan_log.txt")
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    try:
        with open(log_file, "a") as f:
            f.write(f"[{timestamp}] {message}\n")
    except Exception as e:
        print(f"[Error] Could not write log: {e}")
