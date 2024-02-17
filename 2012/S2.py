# ccc senior s2 2012 - https://dmoj.ca/problem/ccc12s2

aromatic = input ()

roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
total = 0

for i in range (0, len (aromatic), 2):
  pair = int (aromatic [i]) * roman [aromatic [i + 1]]
  if i + 3 < len (aromatic) and roman [aromatic [i + 3]] > roman [aromatic [i + 1]]:
    total -= pair
  else:
    total += pair

print (total)
