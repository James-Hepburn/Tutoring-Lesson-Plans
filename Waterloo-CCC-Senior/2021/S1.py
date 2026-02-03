# ccc senior s1 2021 - https://dmoj.ca/problem/ccc21s1

n = int (input ())
heights = [int (i) for i in input ().split ()]
widths = [int (i) for i in input ().split ()]

area = 0

for i in range (n):
  side = min (heights[i], heights[i+1])
  base = widths[i]
  height = max (heights[i], heights[i+1]) - side
  area += side * base
  area += (base * height) / 2

print (area)
