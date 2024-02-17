# ccc senior s2 2013 - https://dmoj.ca/problem/ccc13s2

w = int (input ())
n = int (input ())
weights = [int (input ()) for _ in range (n)]

weights = [0, 0, 0] + weights + [w + 1]

i = 3
total_trains = 0
total_weight = weights [i - 3] + weights [i - 2] + weights [i - 1] + weights [i]

while total_weight <= w:
  i += 1
  total_trains += 1
  total_weight = weights [i - 3] + weights [i - 2] + weights [i - 1] + weights [i]

print (total_trains)
