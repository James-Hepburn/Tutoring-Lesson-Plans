import random
import time
import os

def print_board ():
  line = ""
  for i in range(size):
    line += board[i] + " "
    if (i + 1) % 5 == 0:
      print(line)
      line = ""
  if line != "":
    print(line)

print ("\nWelcome to Concentration! \n")

size = int (input("How many total symbols will be on the board? "))

symbols = ['!', '@', '#', '$', '%']
board = []

for _ in range (size):
  index = random.randint (0, 4)
  board.append (symbols[index])

print ("\nYou have 10 seconds to memorize the following board: \n")
print_board ()

time.sleep (10)
os.system ('clear')

print ("\nResults: \n")
exclamation_marks = int (input ("How many '!' did you see on the board? "))
at_signs = int (input ("How many '@' did you see on the board? "))
hashtags = int (input ("How many '#' did you see on the board? "))
dollar_signs = int (input ("How many '$' did you see on the board? "))
percentage_signs = int (input ("How many '%' did you see on the board? "))

print ("\nAmount of ! =", board.count ("!"))
print ("Amount of @ =", board.count ("@"))
print ("Amount of # =", board.count ("#"))
print ("Amount of $ =", board.count ("$"))
print ("Amount of % =", board.count ("%"))
