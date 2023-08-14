paragraph = input("Enter a paragraph: ")

num_sentences = 0
num_words = 1
num_characters = 0
num_spaces = 0

for i in paragraph:
  num_characters += 1
  if i == ' ':
    num_spaces += 1
    num_words += 1
  elif i in ".!?":
    num_sentences += 1

print(f"\nSentences: {num_sentences}")
print(f"Words: {num_words}")
print(f"Characters: {num_characters}")
print(f"Spaces: {num_spaces}")
