phrase1 = input().replace (" ", "")
phrase2 = input().replace (" ", "")
anagram = True

for i in phrase1:
  if phrase1.count(i) != phrase2.count(i):
    anagram = False
    break 

if anagram:
  print ("Is an anagram.")
else:
  print ("Is not an anagram.")
