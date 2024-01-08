# USACO 2013 November - Bronze Level - Problem 2. Goldilocks and the N Cows - http://www.usaco.org/index.php?page=viewproblem2&cpid=341

line1 = input().split()

n = int (line1[0])
x = int (line1[1])
y = int (line1[2])
z = int (line1[3])

best_total = 0
minimum = 1000000000
maximum = 0
cows = []

for _ in range (n):
  temp = input ().split ()
  low = int (temp[0])
  high = int (temp[1])
  minimum = min (minimum, low)
  maximum = max (maximum, high)
  cows.append ([low, high])

for i in range (minimum, maximum + 1):
  current_total = 0
  for j in cows:
    if j[0] <= i <= j[1]:
      current_total += y
    elif i < j[0]:
      current_total += x
    else:
      current_total += z
  best_total = max (best_total, current_total)

print (best_total)
