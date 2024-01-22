# USACO 2018 December - Bronze Level - Problem 2. The Bucket List - http://www.usaco.org/index.php?page=viewproblem2&cpid=856

n = int (input ())
cows = [[int (i) for i in input ().split ()] for _ in range (n)]

min_time = cows [0][0]
max_time = cows [0][1]

for i in cows:
  min_time = min (min_time, i [0])
  max_time = max (max_time, i [1])

needed_buckets = 0

for i in range (min_time, max_time):
  buckets = 0
  for j in cows:
    if j [0] <= i <= j [1]:
      buckets += j [2]
  needed_buckets = max (needed_buckets, buckets)

print (needed_buckets)
