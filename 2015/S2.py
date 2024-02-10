# ccc senior s2 2015 - https://dmoj.ca/problem/ccc15s2

j = int (input ())
a = int (input ())
size_chart = {'S':1, 'M':2, 'L':3}

jersey_sizes = {}
for i in range (j):
  jersey_sizes [i + 1] = size_chart [input ()]

athlete_sizes = []
for _ in range (a):
  size, number = input ().split ()
  athlete_sizes.append ([size_chart [size], int (number)])
  
athlete_sizes = sorted (athlete_sizes, key = lambda x : x [0], reverse = True)

satisfied = 0

for i in athlete_sizes:
  if i [1] in jersey_sizes:
    if i [0] <= jersey_sizes [i [1]]:
      satisfied += 1
      del jersey_sizes [i [1]]

print (satisfied)
