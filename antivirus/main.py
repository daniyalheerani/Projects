from scanner import scan_file, load_signatures  # Import the functions from scanner.py
import os  # To browse files and folders

# This function goes through each file in a folder and checks if it's infected
def scan_folder(folder_path):
    signatures = load_signatures()  # Get the virus signatures
    for root, dirs, files in os.walk(folder_path):  # Walk through all folders and files
        for file in files:
            file_path = os.path.join(root, file)  # Make full path of each file
            infected, file_hash = scan_file(file_path, signatures)  # Scan the file
            if infected:
                print(f"[!!] Infected: {file_path} (Hash: {file_hash})")  # Show red alert
            else:
                print(f"[OK] Clean: {file_path}")  # File is safe

# This runs when you open the file (starts the scan)
if __name__ == "__main__":
    folder_to_scan = input("Enter folder path to scan: ")  # Ask user to give folder path
    scan_folder(folder_to_scan)  # Start scanning that folder
