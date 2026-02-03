# ccc senior s1 2015 - https://dmoj.ca/problem/ccc15s1

k = int (input ())
numbers = [int (input ()) for _ in range (k)]

digits = []

for i in numbers:
  if i == 0:
    digits.pop (-1)
  else:
    digits.append (i)

print (sum (digits))
