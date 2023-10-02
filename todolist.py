import time
import os

todo = []

while True:
  time.sleep (3)
  os.system ('clear')
  
  print ("Welcome to the Todo List! \n")
  
  print ("1) Add item to list")
  print ("2) Remove item from list")
  print ("3) View entire list")
  print ("4) Exit")
  
  option = int (input("\nWhich option? "))
  print ()

  if option == 1:
    item = input ("What would you like to add to your todo list? ")
    todo.append (item)
  elif option == 2:
    item = input ("What would you like to remove from your todo list? ")
    todo.remove (item)
  elif option == 3:
    for i in range (len (todo)):
      print (str(i + 1) + ") " + todo[i])
  elif option == 4:
    print ("Goodbye.")
    break
  else:
    print ("Invalid option.")
    
