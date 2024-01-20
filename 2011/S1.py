# ccc senior s1 2011 - https://dmoj.ca/problem/ccc11s1

n = int (input ())

s = 0
t = 0

for _ in range (n):
  text = input ().lower ()
  s += text.count ("s")
  t += text.count ("t")

if t > s:
  print ("English")
else:
  print ("French")
