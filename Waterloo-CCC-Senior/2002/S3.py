# ccc senior s3 2002 - https://dmoj.ca/problem/ccc02s3

def is_valid(r, c, dir, by, moves):
  dir_changes = {"north":[-1, 0], "east":[0, 1], "south":[1, 0], "west":[0, -1]}
  right = {"north": "east", "east": "south", "south": "west", "west": "north"}
  left = {"north": "west", "east": "north", "south": "east", "west": "south"}
  for i in moves:
    if i == "F":
      dr, dc = dir_changes[dir]
      r += dr
      c += dc
    elif i == "R":
      dir = right[dir]
    else:
      dir = left[dir]
    if r < 1 or c < 1 or r > len(by) or c > len(by[0]) or by[r - 1][c - 1] == "X":
      return False
  return [r, c]

r = int (input())
c = int (input())
backyard = [list(input()) for _ in range(r)]
m = int (input())
moves = [input() for _ in range (m)]

directions = ["north", "east", "west", "south"]

for i in range (r):
  for j in range (c):
    if backyard[i][j] != "X":
      for k in directions:
        results = is_valid (i + 1, j + 1, k, backyard, moves)
        if results:
          backyard [results[0] - 1][results[1] - 1] = "*"
          break

for i in backyard:
  print ("".join (i))
