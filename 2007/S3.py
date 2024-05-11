# ccc senior s3 2007 - https://dmoj.ca/problem/ccc07s3 

def bfs (x, y):
  visited = [x]
  queue = [[x, -1]]

  while len (queue) != 0:
    current, degree = queue.pop (0)

    if current == y:
      return "Yes " + str (degree)
    elif friends [current] in visited:
      return "No"
    else:
      visited.append (friends [current])
      queue.append ([friends [current], degree + 1])
    
  return "No"

n = int (input ())

friends = {}

for _ in range (n):
  x, y = [int (i) for i in input ().split ()]
  friends [x] = y

while True:
  x, y = [int (i) for i in input ().split ()]

  if x == y == 0:
    break

  print (bfs (x, y))
  
