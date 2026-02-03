def add_room_numbers (i, j, room_number):
  global house, r, c
  if i >= 0 and i < r and j >= 0 and j < c and house [i][j] == ".":
    house [i][j] = str (room_number)
    add_room_numbers (i + 1, j, room_number)
    add_room_numbers (i - 1, j, room_number)
    add_room_numbers (i, j + 1, room_number)
    add_room_numbers (i, j - 1, room_number)

flooring = int (input ())
r = int (input ())
c = int (input ())
house = [list (input ()) for _ in range (r)]

room_number = 1

for i in range (r):
  for j in range (c):
    if house [i][j] == ".":
      add_room_numbers (i, j, room_number)
      room_number += 1

rooms = {}

for i in range (1, room_number):
  rooms [str (i)] = 0

for i in range (r):
  for j in range (c):
    if house [i][j] in rooms:
      rooms [house [i][j]] += 1

rooms = sorted (rooms.items (), key = lambda x : [- x [1]])
counter = 0

while len (rooms) != 0:
  number, area = rooms.pop (0)
  if flooring - area >= 0:
    flooring -= area
    counter += 1
  else:
    break

if counter != 1:
  print (counter, "rooms,", flooring, "square metre(s) left over")
else:
  print (counter, "room,", flooring, "square metre(s) left over")
