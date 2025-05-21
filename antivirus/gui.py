import tkinter as tk
from tkinter import filedialog, messagebox
from scanner import scan_file, load_signatures
from utils import quarantine_file, log_result
import os
import matplotlib.pyplot as plt

# ====================
# 📁 Folder selection
# ====================
def browse_folder():
    folder = filedialog.askdirectory()
    if folder:
        folder_entry.delete(0, tk.END)
        folder_entry.insert(0, folder)

# ====================
# 🚨 Scan logic
# ====================
def start_scan():
    folder = folder_entry.get()

    if not os.path.exists(folder):
        messagebox.showerror("Error", "Folder not found!")
        return

    results_box.delete("1.0", tk.END)

    signatures = load_signatures()
    infected_count = 0
    clean_count = 0

    infected_files = []

    for root, dirs, files in os.walk(folder):
        for file in files:
            file_path = os.path.join(root, file)
            infected, file_hash = scan_file(file_path, signatures)
            if infected:
                infected_count += 1
                infected_files.append(file_path)
                result_msg = f"[!!] Infected: {file_path}\n"
                quarantine_file(file_path)
                log_result(f"Infected: {file_path} (hash: {file_hash})")
                results_box.insert(tk.END, result_msg)
            else:
                clean_count += 1
                log_result(f"Clean: {file_path}")

    if infected_count == 0:
        results_box.insert(tk.END, "✅ No infections found.\n")

    show_graph(infected_count, clean_count)

# ============================
# 📊 Show graph with Matplotlib
# ============================
def show_graph(infected, clean):
    labels = ['Infected', 'Clean']
    values = [infected, clean]
    colors = ['red', 'green']

    plt.bar(labels, values, color=colors)
    plt.title("Scan Results")
    plt.ylabel("Number of Files")
    plt.xlabel("Status")
    plt.tight_layout()
    plt.show()

# ====================
# 🖼️ GUI Layout
# ====================
window = tk.Tk()
window.title("Beginner Antivirus Scanner")
window.geometry("600x500")

tk.Label(window, text="Select a folder to scan for viruses:", font=("Arial", 12)).pack(pady=5)

folder_entry = tk.Entry(window, width=60)
folder_entry.pack(pady=5)

browse_button = tk.Button(window, text="Browse", command=browse_folder)
browse_button.pack(pady=5)

scan_button = tk.Button(window, text="Start Scan", command=start_scan, bg="red", fg="white")
scan_button.pack(pady=10)

results_box = tk.Text(window, height=20, width=70)
results_box.pack(pady=10)

window.mainloop()
# This is a simple GUI for the antivirus scanner using Tkinter.
# It allows users to select a folder, scan for viruses, and view results.