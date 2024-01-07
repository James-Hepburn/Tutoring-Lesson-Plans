import requests

print ("Let's play trivia!\n")

questions = int (input ("How many questions do you want? "))

print ("\nNow pick a category:")
print ("1. Mythology")
print ("2. Sports")
print ("3. History")
print ("4. Art")
category = int (input ("Which category? "))

print ("\nPerfect. Time to select a difficulty:")
print ("1. Easy")
print ("2. Medium")
print ("3. Hard")
difficulty = int (input ("Which difficulty? "))

categories = {1:"20", 2:"21", 3:"23", 4:"25"}
category = categories [category]

difficulties = {1:"easy", 2:"medium", 3:"hard"}
difficulty = difficulties [difficulty]

link = "https://opentdb.com/api.php?amount=" + str(questions) + "&category=" + category + "&difficulty=" + difficulty + "&type=boolean"
response = requests.get (link)
data = response.json ()
questions = data ["results"]

correct = 0

for i in range (len (questions)):
  print ("\n" + str (i + 1) + ". " + questions[i]["question"])
  answer = input ("True or False? ")
  if answer == questions[i]["correct_answer"]:
    correct += 1
    print ("Correct!")
  else:
    print ("Incorrect.")

print ("\nYou scored", correct, "out of " + str (len (questions)) + "!")
