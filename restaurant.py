breakfast_menu = {
  'Pancakes': 5.99,
  'Oatmeal': 3.99,
  'Fruit Salad': 6.99,
  'French Toast': 7.49,
}

lunch_menu = {
  'Chicken Caesar Salad': 9.99,
  'Grilled Chicken Sandwich': 10.79,
  'Turkey Club Wrap': 9.29,
  'Shrimp Tacos': 13.99,
}

dinner_menu = {
  'Beef Tenderloin Steak': 18.49,
  'Chicken Alfredo Pasta': 14.79,
  'Mushroom Risotto': 13.49,
  'Lobster Ravioli': 17.99,
}

drinks_menu = {
  'Coffee': 2.19,
  'Soda': 1.49,
  'Orange Juice': 3.49,
  'Tea': 2.19
}

def print_menu (menu):
  print ()
  for i in menu:
    spaces = 28 - len (i) 
    print (i, spaces * " ", menu[i])

def print_bill (food_menu, food, drink_menu, drink):
  spaces = 28 - len (food)
  print (food, spaces * " ", food_menu[food])
  spaces = 28 - len (drink)
  print (drink, spaces * " ", drink_menu[drink])
  print ("Your total is $", food_menu[food] + drink_menu[drink])

print ("Welcome to the restaurant!\n")

print ("Please select a menu:")
print ("1. Breakfast")
print ("2. Lunch")
print ("3. Dinner")
menu = int (input ("Which menu? "))

if menu == 1:
  menu = breakfast_menu
elif menu == 2:
  menu = lunch_menu
elif menu == 3:
  menu = dinner_menu

print_menu (menu)
food = input ("\nWhat would you like to eat? ").title ()

print_menu (drinks_menu)
drink = input ("\nWhat would you like to drink? ").title ()

print ("\nHere is your bill:")
print_bill (menu, food, drinks_menu, drink)
