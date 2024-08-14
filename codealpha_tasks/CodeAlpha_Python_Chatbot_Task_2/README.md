# About Chat-Bot
This is a simple python informal chat bot. It will replay Questions based on predefine Questions and Answers.

# How This Code Works:
pairs: This is a list of tuples, where each tuple contains a user input pattern and a list of possible responses.
Chat: The nltk library provides a Chat class to manage the conversation. The pairs are passed to this class.
reflections: This is a predefined dictionary in nltk that maps pronouns (e.g., "I" to "you"). It is used to make responses more natural.
Chat Loop: The bot responds to user input until the user types "bye".

# Steps to Run:
1: Install NLTK: If not installed, run: pip install nltk.
2: Run the code in your Jupyter Notebook.