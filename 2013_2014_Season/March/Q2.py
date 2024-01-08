# USACO 2014 March - Bronze Level - Problem 2. The Lazy Cow - http://www.usaco.org/index.php?page=viewproblem2&cpid=413

n, k = [int (i) for i in input ().split ()]
grass = [[int (i) for i in input ().split ()] for _ in range (n)]

grass.sort (key = lambda x : x[1])

max_x = grass[-1][1]
most_grass = 0

for i in range (1, max_x + 1):
  current_grass = 0
  for j in grass:
    if j[1] - k <= i <= j[1] + k:
      current_grass += j[0]
  most_grass = max (most_grass, current_grass)

print (most_grass)
