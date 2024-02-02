class Ship:
  def __init__ (self, length):
    self.length = length
    self.coordinates = []
  
  def set_coordinates (self, coordinates):
    self.coordinates = coordinates

  def get_coordinates (self):
    return self.coordinates

  def get_length (self):
    return self.length

class Board:
  def __init__ (self):
    self.grid = [['~' for _ in range (10)] for _ in range (10)]

  def print_board (self, player):
    print ("Turn:", player, "\n")
    for i in self.grid:
      print (" ".join (i))

  def place_piece (self, r, c, piece):
    self.grid [r][c] = piece

  def get_piece (self, r, c):
    return self.grid [r][c]

class Player:
  def __init__ (self, name):
    self.name = name
    self.ships = []
    self.board = Board ()

  def get_board (self):
    return self.board

  def get_ships (self):
    return self.ships

  def place_ship (self, ship, num):
    self.board.print_board (self.name)
    print ("\nShip: length =", ship.get_length (), "\n")
    while True:
      r = int (input ("Which row? "))
      c = int (input ("Which column? "))
      o = input ("Which orientation (H or V)? ")
      condition1 = 1 <= r <= 10 and 1 <= c <= 10 and (o == "H" or o == "V")
      if condition1:
        condition2 = True
        coordinates = []
        if o == "H":
          for i in range(ship.length):
            if not (1 <= r <= 10) or not (1 <= c <= 10):
              condition2 = False
            coordinates.append([r, c + i])
        else:  
          for i in range(ship.length):
            coordinates.append([r + i, c])
        for i in self.ships:
          for j in i.get_coordinates ():
            if j in coordinates:
              condition2 = False
        if condition2:
          ship.set_coordinates (coordinates)
          self.ships.append (ship)
          for i in coordinates:
            self.board.place_piece (i [0] - 1, i [1] - 1, str (num))
          break
        print ("\nInvalid location. Try again.\n")
      else:
        print ("\nInvalid input. Try again.\n")
        

  def check_hit (self, r, c):
    for i in self.ships:
      for j in i.get_coordinates ():
        if r == j [0] and c == j [1]:
          return True
    return False

  def take_turn (self, other_player):
    self.board.print_board (self.name)
    while True:
      r = int (input ("\nWhich row? "))
      c = int (input ("Which column? "))
      if 1 <= r <= 10 and 1 <= c <= 10 and self.board.get_piece (r, c) == "~":
        break
      print ("\nInvalid input. Try again.\n")
    if other_player.check_hit (r - 1, c - 1):
      print ("\nHit!")
      other_player.get_board ().place_piece (r - 1, c - 1, "x")
    else:
      print ("\nMiss!")

  def check_win (self, other_player):
    counter = 0
    for i in other_player.get_board ():
      counter += i.count ("x")
    return counter == 17

import time, os

print ("Welcome to Battleship!\n")

name1 = input ("Player 1 name? ")
name2 = input ("Player 2 name? ")

player1 = Player (name1)
player2 = Player (name2)

time.sleep (2)
os.system ("clear")

ships1 = [Ship (2), Ship (3), Ship (3), Ship (4), Ship (5)]

for i in range (5):
  player1.place_ship (ships1 [i], i + 1)
  os.system ("clear")


player1.get_board ().print_board (name1)
time.sleep (2)
os.system ("clear")

ships2 = [Ship (2), Ship (3), Ship (3), Ship (4), Ship (5)]

for i in range (5):
  player2.place_ship (ships2 [i], i + 1)
  os.system ("clear")

player2.get_board ().print_board (name2)
time.sleep (2)
os.system ("clear")

while True:
  player1.take_turn (player2)
  if player1.check_win (player2):
    print ("\nYou hit all of the other player's ships!")
    break
  time.sleep (2)
  os.system ("clear")

  player2.take_turn (player1)
  if player2.check_win (player1):
    print ("\nYou hit all of the other player's ships!")
    break
  time.sleep (2)
  os.system ("clear")

