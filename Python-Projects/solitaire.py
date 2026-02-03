import random
import time
import os

class Card:
  
  def __init__ (self, suit, value):
    self.suit = suit
    self.value = value
    self.faceUp = False

  def get_suit (self):
    return self.suit

  def get_value (self):
    return self.value

  def get_flip (self):
    return self.faceUp

  def flip (self):
    self.faceUp = not self.faceUp
    
  def display (self):
    if self.faceUp:
      suitSymbol = self.get_suit_symbol ()
      valueSymbol = self.get_value_symbol ()
      print ("[" + valueSymbol + " " + suitSymbol + "]", end=" ")
    else:
      print ("[xxx]", end=" ")

  def get_suit_symbol (self):
    if self.suit == "Hearts":
      return "♡"
    elif self.suit == "Diamonds":
      return "♢"
    elif self.suit == "Spades":
      return "♠️"
    else:
      return "♣️"

  def get_value_symbol (self):
    if 2 <= self.value <= 10:
      return str (self.value)
    elif self.value == 11:
      return "J"
    elif self.value == 12:
      return "Q"
    elif self.value == 13:
      return "K"
    else:
      return "A"
  
class Deck:

  def __init__ (self):
    self.cards = []
    self.create_deck ()
    self.shuffle ()

  def create_deck (self):
    suits = ["Hearts", "Clubs", "Diamonds", "Spades"]
    values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
    for i in suits:
      for j in values:
        card = Card (i, j)
        self.cards.append (card)

  def shuffle (self):
    random.shuffle (self.cards)

  def deal_card (self):
    if not self.is_empty ():
      return self.cards.pop ()

  def is_empty (self):
    return len (self.cards) == 0

  def add_card (self, card):
    self.cards.insert (0, card)

class Pile:

  def __init__ (self):
    self.cards = []

  def add_card (self, card):
    self.cards.append (card)

  def get_cards (self):
    return self.cards

  def set_cards (self, cards):
    self.cards = cards

  def can_add_pile (self, source):
    if source.is_empty ():
      return False
    else:
      index = 0
      cards = source.get_cards ()
      while index < len (cards) and not cards[index].get_flip ():
        index += 1
      if index == len (cards):
        return False
      card = cards[index]
      if self.is_empty ():
        amount = len (cards) - index - 1
        for _ in range (amount):
          add = cards.pop (index)
          self.add_card (add)
        source.set_cards (cards)
        return True
      top_card = self.cards[-1]
      red = ["Hearts", "Diamonds"]
      black = ["Spades", "Clubs"]
      condition1 = top_card.get_value () == card.get_value () + 1
      condition2 = top_card.get_suit () in red and card.get_suit () in black
      condition3 = top_card.get_suit () in black and card.get_suit () in red
      if condition1 and (condition2 or condition3):
        amount = len (cards) - index - 1
        for _ in range (amount):
          add = cards.pop (index)
          self.add_card (add)
        source.set_cards (cards)
        return True
      else:
        return False
  
  def can_add_card (self, card):
    if len (self.cards) == 0:
      return card.get_value () == 13
    else:
      top_card = self.cards[-1]
      red = ["Hearts", "Diamonds"]
      black = ["Spades", "Clubs"]
      condition1 = top_card.get_value () == card.get_value () + 1
      condition2 = top_card.get_suit () in red and card.get_suit () in black
      condition3 = top_card.get_suit () in black and card.get_suit () in red
      return condition1 and (condition2 or condition3)

  def display (self):
    for i in self.cards:
      i.display ()
    print(" ", end="")

  def is_empty (self):
    return len (self.cards) == 0

  def get_top (self):
    return self.cards[-1]

  def remove_top (self):
    top = self.cards.pop ()
    if not self.is_empty ():
      self.cards[-1].flip ()
    return top

deck = Deck ()

current_card = deck.deal_card ()
current_card.flip ()

piles = []
for _ in range (7):
  piles.append (Pile ())

for i in range (7):
  for j in range (i + 1):
    card = deck.deal_card ()
    if j == i:
      card.flip ()
    piles[i].add_card (card)

def display_pile (index):
  print (index + 1, "-", end=" ")
  print ("    " * index, end="")
  piles[index].display ()

def display_game ():
  global current_card
  print ()
  for i in range (7):
    display_pile (i)
    print ()
  print ()
  print ("\nCurrent card: ", end = " ")
  current_card.display ()
  print (end = "")
  print ()

def valid_move (source, destination):
  if source > 6 or source < 0:
    return False
  elif destination > 6 or destination < 0:
    return False
  else:
    source_pile = piles[source]
    destination_pile = piles[destination]
    if source_pile.is_empty ():
      return False
    elif not destination_pile.can_add_card (source_pile.get_top ()) and not destination_pile.can_add_pile (source_pile):
      return False
    else:
      return True

def valid_use_current (destination):
  global current_card
  if destination > 6 or destination < 0:
    return False
  else:
    destination_pile = piles[destination]
    if not destination_pile.can_add_card (current_card):
      return False
    else:
      return True

def has_won (deck):
  empty = 0
  for i in piles:
    if i.is_empty ():
      empty += 1
  return empty == 3 and deck.is_empty ()

while not has_won (deck):
  os.system ("clear")
  
  display_game ()

  option = int (input ("\n(1) Move card, (2) Use current card, (3) Draw new card or (4) End game? "))

  if option == 1:
    source = int (input ("\nEnter source pile (1-7): ")) - 1
    destination = int (input ("Enter destination pile (1-7): ")) - 1
    if valid_move (source, destination):
      card = piles[source].remove_top ()
      piles[destination].add_card (card)
    else:
      print ("\nInvalid move. Try again.")
      time.sleep (2)

  elif option == 2:
    destination = int (input ("\nEnter destination pile (1-7): ")) - 1
    if valid_use_current (destination):
      piles[destination].add_card (current_card)
      current_card = deck.deal_card ()
      current_card.flip ()
    else:
      print ("\nInvalid move. Try again.")
      time.sleep (2)

  elif option == 3:
    current_card.flip ()
    deck.add_card (current_card)
    current_card = deck.deal_card ()
    current_card.flip ()

  elif option == 4:
    break

  else:
    print ("\nInvalid move. Try again.")
    time.sleep (2)

if has_won (deck):
  print ("\nYou win!")
else:
  print ("\nGame over. You ran out of moves.")
  
