import random
import time
import os

class Pokemon:

  def __init__ (self, name, damage, health):
    self.name = name
    self.damage = damage
    self.health = health

  def display_pokemon (self):
    print ("\nPokemon:", self.name)
    print ("Damage:", self.damage)
    print ("Health:", self.health, "\n")

  def attack (self):
    print ("\n" + self.name, "attacks")
    print (self.name, "deals", self.damage, "damage")
    return self.damage

  def take_damage (self, amount):
    self.health -= amount

  def heal (self, amount):
    print ("\n" + self.name, "is healed by", amount, "points")
    self.health += amount 

class FireType (Pokemon):

  def __init__ (self, name, damage, health):
    super().__init__(name, damage, health)
    self.type = "Fire"

  def attack (self, other_type):
    amount = super().attack()
    if other_type == "Grass":
      print ("\nFire types do 2x damage to Grass types")
      print (self.name, "deals 2x damage")
      amount *= 2
    return amount

class WaterType (Pokemon):

  def __init__ (self, name, damage, health):
    super().__init__(name, damage, health)
    self.type = "Water"

  def attack (self, other_type):
    amount = super().attack()
    if other_type == "Fire":
      print ("\nWater types do 2x damage to Fire types")
      print (self.name, "deals 2x damage")
      amount *= 2
    return amount

class GrassType (Pokemon):

  def __init__ (self, name, damage, health):
    super().__init__(name, damage, health)
    self.type = "Grass"

  def attack (self, other_type):
    amount = super().attack()
    if other_type == "Water":
      print ("\nGrass types do 2x damage to Water types")
      print (self.name, "deals 2x damage")
      amount *= 2
    return amount

class Trainer:

  def __init__ (self, name, pokemon):
    self.name = name
    self.pokemon = pokemon

  def is_knocked_out (self):
    return self.pokemon.health <= 0

  def display_turn (self):
    print ("Trainer", self.name + "'s turn!")
    self.pokemon.display_pokemon ()
    print ("1) Attack")
    print ("2) Heal\n")
    move = int (input ("What do you want to do? "))
    return move

  def take_turn (self, move, other_type):
    if move == 1:
      amount = self.pokemon.attack (other_type)
      return amount
    else:
      amount = random.randint (3, 7)
      self.pokemon.heal (amount)
      return 0

charmander = FireType ("Charmander", 5, 100)
vulpix = FireType ("Vulpix", 4, 90)
squirtle = WaterType ("Squirtle", 5, 100)
psyduck = WaterType ("Psyduck", 3, 80)
bulbasaur = GrassType ("Bulbasaur", 6, 110)
oddish = GrassType ("Oddish", 3, 85)

def display_pokemon ():
  print ("\nGreat! Now, pick a pokemon:")
  print ("1) Charmander")
  print ("2) Vulpix")
  print ("3) Squirtle")
  print ("4) Psyduck")
  print ("5) Bulbasaur")
  print ("6) Oddish")

def get_pokemon (pokemon):
  options = {1:charmander, 2:vulpix, 3:squirtle, 4:psyduck, 5:bulbasaur, 6:oddish}
  return options[pokemon]

print ("Welcome to the Pokemon Battle!\n")
print ("Enter the following information to begin:\n")

name1 = input ("Trainer # 1, what is your name? ")
display_pokemon ()
pokemon1 = int (input ("Which pokemon do you want? "))
trainer1 = Trainer (name1, get_pokemon (pokemon1))

print ("\nAwesome!\n")

name2 = input ("Trainer # 2, what is your name? ")
display_pokemon ()
pokemon2 = int (input ("Which pokemon do you want? "))
trainer2 = Trainer (name2, get_pokemon (pokemon2))

print ("\nAll set!\n")

time.sleep (3)
os.system ("clear")

while True:
  move = trainer1.display_turn ()
  amount = trainer1.take_turn (move, trainer2.pokemon.type)
  trainer2.pokemon.take_damage (amount)

  if trainer2.is_knocked_out ():
    print ("\n" + trainer2.name, "and", trainer2.pokemon.name, "have been knocked out!")
    break

  time.sleep (3)
  os.system ("clear")

  move = trainer2.display_turn ()
  amount = trainer2.take_turn (move, trainer1.pokemon.type)
  trainer1.pokemon.take_damage (amount)

  if trainer1.is_knocked_out ():
    print ("\n" + trainer1.name, "and", trainer1.pokemon.name, "have been knocked out!")
    break

  time.sleep (3)
  os.system ("clear")
  
