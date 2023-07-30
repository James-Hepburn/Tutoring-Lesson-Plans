import random

def get_computer_move ():
  computer_move = random.randint (1, 3)
  if computer_move == 1:
    return "rock"
  elif computer_move == 2:
    return "paper"
  else:
    return "scissors"

def check_player_win (computer, player):
  if computer == "rock" and player == "paper":
    return True
  elif computer == "paper" and player == "scissors":
    return True
  elif computer == "scissors" and player == "rock":
    return True
  else:
    return False

def check_player_loss (computer, player):
  if computer == "rock" and player == "scissors":
    return True
  elif computer == "paper" and player == "rock":
    return True
  elif computer == "scissors" and player == "paper":
    return True
  else:
    return False

def check_player_tie (computer, player):
  if computer == player:
    return True 
  else:
    return False 

print ("Rock, Paper, Scissors! \n")

player_move = input ("What is your move? ").lower()
computer_move = get_computer_move()

print ("\nYour move:", player_move)
print ("Computer move:", computer_move)

if check_player_win (computer_move, player_move) == True:
  print ("\nYou win!")
elif check_player_loss (computer_move, player_move) == True:
  print ("\nComputer wins!")
elif check_player_tie (computer_move, player_move) == True:
  print ("\nTie!")
else:
  print ("\nInvalid answer.")
  
