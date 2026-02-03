def degree_of_separation (people, x, y):
  visited = set ()
  queue = [[x, 0]]
  visited.add (x)
  while len (queue) != 0:
    current, degree = queue.pop (0)
    if current == y:
      return degree
    for i in people[current]:
      if i not in visited:
        visited.add (i)
        queue.append ([i, degree + 1])
  return "Not connected"

people = {
  1: [6],
  2: [6],
  3: [4, 5, 6, 15],
  4: [3, 5, 6],
  5: [3, 4, 6],
  6: [1, 2, 3, 4, 5, 7],
  7: [6, 8],
  8: [7, 9],
  9: [8, 10, 12],
  10: [9, 11],
  11: [10, 12],
  12: [9, 11, 13],
  13: [12, 14, 15],
  14: [13],
  15: [3,13],
  16: [17,18],
  17: [16,18],
  18: [16,17],
}

while True:
  instruction = input ()

  if instruction == "q":
    break

  elif instruction == "i":
    x = int (input())
    y = int (input())
    if x not in people:
      people[x] = [y]
    if y not in people:
      people[y] = [x]
    if y not in people[x]:
      people[x].append (y)
    if x not in people[y]:
      people[y].append (x)

  elif instruction == "d":
    x = int (input())
    y = int (input())
    if x in people and y in people[x]:
      people[x].remove (y)
    if y in people and x in people[y]:
      people[y].remove (x)

  elif instruction == "n":
    x = int (input())
    if x in people:
      print (len (people[x]))
    else:
      print (0)

  elif instruction == "f":
    x = int (input())
    friends = []
    if x in people:
      for i in people[x]:
        for j in people[i]:
          if j not in friends and j != x and j not in people[x]:
            friends.append (j)
    print (len (friends))
        
  elif instruction == "s":
    x = int (input())
    y = int (input())
    print (degree_of_separation (people, x, y))
