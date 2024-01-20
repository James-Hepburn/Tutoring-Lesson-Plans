# ccc senior s1 2012 - https://dmoj.ca/problem/ccc12s1

j = int (input ())

count = 0

for a in range (1, j):
  for b in range (a + 1, j):
    for c in range (b + 1, j):
      count += 1
        
print (count)
