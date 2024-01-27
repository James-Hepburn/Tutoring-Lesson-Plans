# ccc senior s1 2010 - https://dmoj.ca/problem/ccc10s1

n = int (input ())
computers = {}

for _ in range (n):
  information = input ().split ()
  r = int (information [1])
  s = int (information [2])
  d = int (information [3])
  computers [information [0]] = (2 * r) + (3 * s) + d

computers = dict (sorted (computers.items (), key = lambda x : (-x [1], x [0])))
names = list (computers.keys ())

if len (names) == 1:
  print (names [0])
elif len (names) >= 2:
  print (names [0])
  print (names [1])
  
