print ("Please enter a paragraph below:\n\n")

paragraph = input ("Type here: ")

text = []
for i in paragraph.split ():
  i = i.lower ()
  i = i.replace (".", "")
  i = i.replace (",", "")
  i = i.replace ("!", "")
  text.append (i)

words = set ()
for i in text:
  words.add (i)

print ("\nWords:\n")
for i in words:
  print (i, "=", text.count (i))
