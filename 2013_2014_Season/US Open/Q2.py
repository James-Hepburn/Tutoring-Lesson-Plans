# USACO 2014 US Open - Bronze Level - Problem 2. Fair Photography - http://www.usaco.org/index.php?page=viewproblem2&cpid=431

n = int (input ())
cows = {}

for _ in range (n):
  info = input ().split ()
  cows [int (info [0])] = info [1]

cows = dict (sorted (cows.items ()))
breeds = []

for i in cows:
  breeds.append (cows [i])

def get_size (i, j, cows):
  index = 0
  min_pos = 1000000000
  max_pos = 0
  for k in cows:
    if i <= index < j:
      min_pos = min (min_pos, k)
      max_pos = max (max_pos, k)
    index += 1
  return max_pos - min_pos

max_size = 0

for i in range (n):
  for j in range (i + 1, n):
    photo = breeds [i : j]
    size = get_size (i, j, cows)
    if photo.count ("G") == photo.count ("H"):
      max_size = max (size, max_size)

print (max_size)
