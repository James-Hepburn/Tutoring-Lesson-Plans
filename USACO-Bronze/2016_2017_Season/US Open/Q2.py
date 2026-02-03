# USACO 2017 US Open - Bronze Level - Problem 2. Bovine Genomics - http://www.usaco.org/index.php?page=viewproblem2&cpid=736

n, m = [int (i) for i in input ().split ()]
spotty_cows = [input () for _ in range (n)]
plain_cows = [input () for _ in range (n)]

count = 0

for i in range (m):
  valid = True
  for j in spotty_cows:
    spotty_value = j [i]
    for k in plain_cows:
      plain_value = k [i]
      if spotty_value == plain_value:
        valid = False
  if valid:
    count += 1

print (count)
