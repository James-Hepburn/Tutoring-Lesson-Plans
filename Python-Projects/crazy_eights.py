import random
import time
import os

def deal_card ():
  suits = ["Hearts", "Diamonds", "Clubs", "Spades"]
  values = ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"]
  return values[random.randint (0, 12)] + " of " + suits[random.randint (0, 3)]

def create_hand ():
  hand = []
  for i in range (5):
    hand.append (deal_card ())
  return hand

def show_hand (turn, hand, deck):
  time.sleep (3)
  os.system ("clear")
  print ("Current turn:", turn, "\n")
  print ("Card on deck:", deck, "\n")
  for i in range (len (hand)):
    print (str(i+1) + ") " + hand[i])
  print ()

def take_turn (hand):
  global card_on_deck
  print ("1) Put down card from hand")
  print ("2) Pick up card from deck")
  option = int (input ("\nWhich option? "))
  
  if option == 1:
    card = int (input ("Which card? "))
    
    if card > len (hand) or card < 1:
      print ("\nInvalid card. A card was automatically drawn for you and placed into your hand.")
      card_drawn = deal_card ()
      print ("\nCard drawn:", card_drawn)
      hand.append (card_drawn)
      
    else:
      deck_info = card_on_deck.split (" of ")
      card_info = hand[card - 1].split (" of ")
      
      if deck_info[0] == card_info[0] or deck_info[1] == card_info[1]:
        card_on_deck = hand[card - 1]
        hand.remove (card_on_deck)
        
      else:
        print ("\nInvalid card. A card was automatically drawn for you and placed into your hand.")
        card_drawn = deal_card ()
        print ("\nCard drawn:", card_drawn)
        hand.append (card_drawn)
        
  elif option == 2:
    card_drawn = deal_card ()
    print ("\nCard drawn:", card_drawn)
    hand.append (card_drawn)
    
  else:
    print ("\nInvalid card. A card was automatically drawn for you and placed into your hand.")
    card_drawn = deal_card ()
    print ("\nCard drawn:", card_drawn)
    hand.append (card_drawn)

  return hand
  
card_on_deck = deal_card ()
player1_hand = create_hand ()
player2_hand = create_hand ()

os.system ("clear")

print ("Welcome to Crazy Eights! \n")
print ("Please enter the following information: \n")

player1_name = input("Player one's name: ")
player2_name = input("Player two's name: ")

print ("\nGreat! Let's begin!")

while True:
  show_hand (player1_name, player1_hand, card_on_deck)
  player1_hand = take_turn (player1_hand)
  if len (player1_hand) == 0:
    print (player1_name, "wins!")
    break

  show_hand (player2_name, player2_hand, card_on_deck)
  player2_hand = take_turn (player2_hand)
  if len (player2_hand) == 0:
    print (player2_name, "wins!")
    break
