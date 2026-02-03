adjacent = {
  "A":[], 
  "B":[], 
  "C":[], 
  "D":[], 
  "E":[], 
  "F":[], 
  "G":[], 
  "H":[], 
  "I":[], 
  "J":[], 
  "K":[], 
  "L":[], 
  "M":[], 
  "N":[], 
  "O":[], 
  "P":[], 
  "Q":[], 
  "R":[], 
  "S":[], 
  "T":[], 
  "U":[], 
  "V":[], 
  "W":[],
  "X":[], 
  "Y":[], 
  "Z":[]
}

copy = {
  "A":[], 
  "B":[], 
  "C":[], 
  "D":[], 
  "E":[], 
  "F":[], 
  "G":[], 
  "H":[], 
  "I":[], 
  "J":[], 
  "K":[], 
  "L":[], 
  "M":[], 
  "N":[], 
  "O":[], 
  "P":[], 
  "Q":[], 
  "R":[], 
  "S":[], 
  "T":[], 
  "U":[], 
  "V":[], 
  "W":[],
  "X":[], 
  "Y":[], 
  "Z":[]
}

roads = []
while True:
  info = input ()
  if info == "**":
    break
  roads.append (info)
  adjacent [info [0]].append (info [1])
  adjacent [info [1]].append (info [0])

def bfs (start, end, map):
  queue = [start]
  visited = [start]
  while len (queue) != 0:
    current = queue.pop (0)
    for i in map [current]:
      if i == end:
        return True
      elif i not in visited:
        queue.append (i)
        visited.append (i)
  return False

count = 0
for i in roads:
  for j in adjacent:
    connections = []
    for k in adjacent[j]:
      connections.append (k)
    copy [j] = connections
  copy [i [0]].remove (i [1])
  copy [i [1]].remove (i [0])
  if bfs ("A", "B", copy) == False:
    count += 1
    print (i)

print ("There are", count, "disconnecting roads.")
