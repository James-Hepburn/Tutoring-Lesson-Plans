# ccc senior s1 2022 - https://dmoj.ca/problem/ccc22s1

n = int (input ())
count = 0

for i in range (1000000):
  fives = i * 5
  fours = n - fives
  if fours >= 0 and fours % 4 == 0:
    count += 1
  elif fives > n:
    break

print (count)
