# ccc senior s1 2013 - https://dmoj.ca/problem/ccc13s1

y = int (input ()) + 1

def is_distinct (y):
  s = set (y)
  return len (s) == len (y)

while not is_distinct (str (y)):
  y += 1

print (y)
