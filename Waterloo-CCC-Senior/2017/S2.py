# ccc senior s2 2017 - https://dmoj.ca/problem/ccc17s2

n = int (input ())
tides = [int (i) for i in input ().split ()]

tides.sort ()

low = n // 2 - 1
high = n // 2

if n % 2 != 0:
  low += 1
  high += 1

original = []

while low >= 0 and high <= n - 1:
  original.append (str (tides [low]))
  original.append (str (tides [high]))
  low -= 1
  high += 1

if n % 2 != 0:
  original.append (str (tides [0]))

print (" ".join (original))
