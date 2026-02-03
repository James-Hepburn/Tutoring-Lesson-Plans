# USACO 2013 December - Bronze Level - Problem 2. Cow Baseball - http://www.usaco.org/index.php?page=viewproblem2&cpid=359

n = int (input ())

cows = []
count = 0

for _ in range (n):
  cows.append (int (input ()))

cows.sort ()

for i in range (n - 2):
  for j in range (i + 1, n - 1):
    xy = cows[j] - cows[i]
    for k in range (j + 1, n):
      yz = cows[k] - cows[j]
      if yz >= xy and yz <= 2 * xy:
        count += 1

print (count)
