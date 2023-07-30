points = 0
questions = 4

print ("Welcome to the Superhero Quiz!")

print("\n1. Who is the alter ego of the superhero Spider-Man?")
print("  a) Bruce Wayne")
print("  b) Peter Parker")
print("  c) Clark Kent")
print("  d) Tony Stark")

q1 = input("\nWhich answer is correct? ")

if q1.lower() == "b":
  print("Great job!")
  points += 1
else:
  print("Sorry, the answer was b) Peter Parker.")

print("\n2. What is the name of the fictional city where Batman operates?")
print("  a) Gotham City")
print("  b) Metropolis")
print("  c) Star City")
print("  d) Central City")

q2 = input("\nWhich answer is correct? ")

if q2.lower() == "a":
  print("Great job!")
  points += 1
else:
  print("Sorry, the answer was a) Gotham City.")

print("\n3. Which superhero is known as the 'Man of Steel'?")
print("  a) Spider-Man")
print("  b) Iron Man")
print("  c) Superman")
print("  d) The Flash")

q3 = input("\nWhich answer is correct? ")

if q3.lower() == "c":
  print("Great job!")
  points += 1
else:
  print("Sorry, the answer was c) Superman.")

print("\n4. Who is the arch-nemesis of Spider-Man?")
print("  a) The Green Goblin")
print("  b) The Joker")
print("  c) Lex Luthor")
print("  d) Doctor Octopus")

q4 = input("\nWhich answer is correct? ")

if q4.lower() == "a":
  print("Great job!")
  points += 1
else:
  print("Sorry, the answer was a) The Green Goblin.")

print ("\nYou answered", points, "out of", questions, "questions correctly.")

if points / questions > 0.75:
  print ("Great job!")
elif points / questions > 0.5:
  print ("Nice!")
elif points / questions > 0.25:
  print ("Better luck next time.")
else:
  print ("Sorry. Try again.")
  
