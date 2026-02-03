# ccc senior s3 2008 - https://dmoj.ca/problem/ccc08s3 

def bfs (grid, r, c):
  visited = [[0, 0]]
  queue = [[0, 0, 1]]

  while len (queue) != 0:
    x, y, distance = queue.pop (0)

    if x == r - 1 and y == c - 1:
      return distance

    if (grid [x][y] == "+" or grid [x][y] == "|") and x > 0 and grid [x - 1][y] != "*" and [x - 1, y] not in visited:
      visited.append ([x - 1, y])
      queue.append ([x - 1, y, distance + 1])

    if (grid [x][y] == "+" or grid [x][y] == "|") and x < r - 1 and grid [x + 1][y] != "*" and [x + 1, y] not in visited:
      visited.append ([x + 1, y])
      queue.append ([x + 1, y, distance + 1])

    if (grid [x][y] == "+" or grid [x][y] == "-") and y > 0 and grid [x][y - 1] != "*" and [x, y - 1] not in visited:
      visited.append ([x, y - 1])
      queue.append ([x, y - 1, distance + 1])

    if (grid [x][y] == "+" or grid [x][y] == "-") and y < c - 1 and grid [x][y + 1] != "*" and [x, y + 1] not in visited:
      visited.append ([x, y + 1])
      queue.append ([x, y + 1, distance + 1])

  return -1

t = int (input ())

for _ in range (t):
  r = int (input ())
  c = int (input ())
  
  grid = []

  for _ in range (r):
    grid.append (list (input ()))

  print (bfs (grid, r, c))
