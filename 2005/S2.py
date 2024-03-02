# ccc senior s2 2005 - https://dmoj.ca/problem/ccc05s2

c, r = [int (i) for i in input ().split ()]
x = y = 0

while True:
  dx, dy = [int (i) for i in input ().split ()]
  if dx == dy == 0:
    break
  x = min (c, x + dx) if dx > 0 else max (0, x + dx)
  y = min (r, y + dy) if dy > 0 else max (0, y + dy)
  print (x, y)
