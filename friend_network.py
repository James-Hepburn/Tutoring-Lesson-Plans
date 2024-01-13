def degree_of_separation (friends, user1, user2):
  queue = [[user1, 0]]
  visited = {user1}
  while len (queue) != 0:
    current, degree = queue.pop (0)
    if current == user2:
      return degree
    for i in friends [current]:
      if i not in visited:
        visited.add (i)
        queue.append ([i, degree + 1])
  return "not connected"

friends = {
  "Sarah" : {"John", "Steve", "Madison"},
  "John" : {"Sarah", "Felix"},
  "Steve" : {"Sarah", "Felix"},
  "Madison" : {"Sarah"}, 
  "Felix" : {"John", "Steve"}
}

while True:
  print ("\nFriend Network!\n")
  print ("1. Add user")
  print ("2. Delete user")
  print ("3. Add friendship")
  print ("4. Delete friendship")
  print ("5. Find friends of friends")
  print ("6. Find degree of separation")
  print ("7. Show network")
  print ("8. Quit program")
  
  option = int (input ("\nSelect an option: "))
  print ()
  
  if option == 1:
    user = input ("What user would you like to add? ")
    if user not in friends:
      friends [user] = set ()
      print ("User successfully added.")
    else:
      print ("User already exists.")
  
  elif option == 2:
    user = input ("What user would you like to delete? ")
    if user not in friends:
      print ("User does not exist.")
    else:
      for i in friends [user]:
        friends [i].remove (user)
      del friends [user]
      print ("User successfully deleted.")
  
  elif option == 3:
    user1 = input ("Friend # 1: ")
    user2 = input ("Friend # 2: ")
    if user1 not in friends:
      friends [user1] = set ()
    if user2 not in friends:
      friends [user2] = set ()
    friends [user1].add (user2)
    friends [user2].add (user1)
    print ("Friendship successfully created.")
  
  elif option == 4:
    user1 = input ("Friend # 1: ")
    user2 = input ("Friend # 2: ")
    if user1 not in friends:
      print ("User", user1, "does not exist.")
    elif user2 not in friends:
      print ("User", user2, "does not exist.")
    elif user2 not in friends [user1]:
      print ("Friendship between", user1, "and", user2, "does not exist.")
    else:
      friends [user1].remove (user2)
      friends [user2].remove (user1)
      print ("Friendship successfully deleted.")
  
  elif option == 5:
    user = input ("What user would you like to find the friends of friends of? ")
    if user not in friends:
      print ("User does not exist.")
    else:
      fof = set ()
      for i in friends [user]:
        for j in friends [i]:
          if j != user and j not in friends [user]:
            fof.add (j)
      print ("\nHere are the friends of friends for", user + ":")
      for i in fof:
        print (i)
  
  elif option == 6:
    user1 = input ("Friend # 1: ")
    user2 = input ("Friend # 2: ")
    if user1 not in friends:
      print ("User", user1, "does not exist.")
    elif user2 not in friends:
      print ("User", user2, "does not exist.")
    else:
      print ("Degree of separation:", degree_of_separation (friends, user1, user2))
  
  elif option == 7:
    print ("\nHere is the network:")
    for i in friends:
      print (i, "-", ", ".join (list (friends [i])))
  
  elif option == 8:
    print ("Goodbye.")
    break
  
  else:
    print ("Invalid option. Try again.")
