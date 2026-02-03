line = input()

happy = line.count (":-)")
sad = line.count (":-(")

if happy == sad == 0:
  print ("none")
elif happy > sad:
  print ("happy")
elif happy < sad:
  print ("sad")
else:
  print ("unsure")
  
