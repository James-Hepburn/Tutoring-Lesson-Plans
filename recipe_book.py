import time, os

while True:
  print ("Recipe Book!\n")
  
  print ("(1) Add a new recipe")
  print ("(2) Delete a recipe")
  print ("(3) Find a recipe")
  print ("(4) Exit recipe book")
  
  option = int (input ("\nOption? "))
  print ()
  
  if option == 1:
    recipe_name = input ("Recipe name? ").lower ()
    file_name = "-".join (recipe_name.split (" ")) + ".txt"
    file = open (file_name, "w")
  
    file.write (recipe_name + "\n\n")
    print ()
  
    while True:
      ingredient = input ("Enter an ingredient or 'exit': ").lower ()
      if ingredient == "exit":
        break
      file.write ("- " + ingredient + "\n")
  
    file.write ("\n")
    counter = 1
    print ()
    
    while True:
      instruction = input ("Enter an instruction or 'exit': ").lower ()
      if instruction == "exit":
        break
      file.write (str (counter) + ". " + instruction + "\n")
      counter += 1
  
  elif option == 2:
    recipe_name = input ("Recipe name? ").lower ()
    file_name = "-".join (recipe_name.split (" ")) + ".txt"
    try:
      os.remove (file_name)
    except FileNotFoundError:
      print ("\nRecipe not found.")
  
  elif option == 3:
    recipe_name = input ("Recipe name? ").lower ()
    file_name = "-".join (recipe_name.split (" ")) + ".txt"
    try:
      print ()
      file = open (file_name, "r")
      for i in file:
        i = i.strip ()
        print (i)
      time.sleep (8)
    except FileNotFoundError:
      print ("\nRecipe not found.")
  
  elif option == 4:
    print ("Goodbye.")
    break
  
  else:
    print ("Invalid option.")

  time.sleep (2)
  os.system ("clear")
  
