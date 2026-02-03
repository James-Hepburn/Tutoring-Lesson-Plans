# USACO 2018 January - Bronze Level - Problem 2. Lifeguards - http://www.usaco.org/index.php?page=viewproblem2&cpid=784

n = int (input ())
cows = [[int (i) for i in input ().split ()] for _ in range (n)]

def calculate_time (cows, avoid):
  time = set ()
  for i in range (len (cows)):
    if i != avoid:
      for j in range (cows [i][0], cows [i][1]):
        time.add (j)
  return len (time)

max_time = 0

for i in range (n):
  time = calculate_time (cows, i)
  max_time = max (max_time, time)

print (max_time)
