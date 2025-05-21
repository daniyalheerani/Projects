import hashlib  # Used to create a unique fingerprint of a file
import os       # Helps us work with file paths and folders

# This function calculates the SHA-256 hash of a file.
def calculate_hash(file_path):
    sha256 = hashlib.sha256()  # Create a SHA-256 hash object
    try:
        with open(file_path, "rb") as f:  # Open the file in binary read mode
            for chunk in iter(lambda: f.read(4096), b""):  # Read file in chunks
                sha256.update(chunk)  # Update hash with each chunk
        return sha256.hexdigest()  # Return the full hash in hex form
    except Exception as e:
        print(f"Error hashing file {file_path}: {e}")
        return None  # If there's an error (like permission denied), return nothing

# This function reads a list of known virus hashes from the signatures.txt file
def load_signatures(signature_file="signatures.txt"):
    try:
        with open(signature_file, "r") as f:
            return set(line.strip() for line in f if line.strip())  # Store each line (hash) in a set
    except FileNotFoundError:
        print("Signature file not found.")
        return set()  # If the file is missing, return an empty set

# This checks if a file is a virus by comparing its hash with the list
def scan_file(file_path, signatures):
    file_hash = calculate_hash(file_path)  # Get the file's hash
    if file_hash and file_hash in signatures:  # Check if it matches a virus signature
        return True, file_hash  # It's a virus
    return False, file_hash  # It's clean
