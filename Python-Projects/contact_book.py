import os, time

names = []
phone_numbers = []
emails = []

while True:
  os.system ("clear")
  print ("Welcome to your Contact Book!")
  
  print ("\nWhat would you like to do? \n")
  print ("1) Add a new contact")
  print ("2) Find a contact")
  print ("3) Remove a contact")
  print ("4) View all contacts")
  print ("5) Exit")
  
  option = int (input ("\nOption: "))
  
  if option == 1:
    print ("\nPlease enter the following information for your new contact: \n")
    name = input ("Name: ")
    names.append (name)
    phone_number = input ("Phone number: ")
    phone_numbers.append (phone_number)
    email = input ("Email: ")
    emails.append (email)
    print ("\nContact successfully added.")
    time.sleep (2)
  
  elif option == 2:
    print ("\nHow do you want to search your contact book? \n")
    print ("1) By name")
    print ("2) By phone number")
    print ("3) By email")
    choice = int (input ("\nOption: "))
    index = -1
    if choice == 1:
      information = input ("\nName: ")
    elif choice == 2:
      information = input ("\nPhone number: ")
    else:
      information = input ("\nEmail: ")
    for i in range (len (names)):
      if (names [i] == information and choice == 1) or (phone_numbers [i] == information and choice == 2) or (emails [i] == information and choice != 1 and choice != 2):
        index = i
        break
    if index == -1:
      print ("\nSorry, no contact with that information could be found.")
    else:
      print ("\nHere is your contact:\n")
      print ("Name:", names [index])
      print ("Phone number:", phone_numbers [index])
      print ("Email:", emails [index])
    time.sleep (2)
  
  elif option == 3:
    name = input ("\nWhat is the name of the contact you want to remove? ")
    index = -1
    for i in range (len (names)):
      if names [i] == name:
        index = i
        break
    if index == -1:
      print ("\nSorry, no contact with that information could be found.")
    else:
      names.pop (index)
      phone_numbers.pop (index)
      emails.pop (index)
      print ("\nYour contact has been successfully removed.")
    time.sleep (2)
  
  elif option == 4:
    print ("\nHere are all of your contacts: \n")
    for i in range (len (names)):
      print ("\nContact # " + str (i + 1) + ": ")
      print ("Name:", names [i])
      print ("Phone number:", phone_numbers [i])
      print ("Email:", emails [i])
    time.sleep (5)
  
  else:
    print ("\nGoodbye.")
    break
