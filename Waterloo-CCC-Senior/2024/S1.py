# ccc senior s1 2024 - https://dmoj.ca/problem/ccc24s1

n = int (input ())
hats = [int (input ()) for _ in range (n)]

count = 0

for i in range (n):
  if hats [i] == hats [(i + n // 2) % n]:
     count += 1

print (count)
