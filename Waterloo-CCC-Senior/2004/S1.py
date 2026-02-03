# ccc senior s1 2004 - https://dmoj.ca/problem/ccc04s1

n = int (input ())

for _ in range (n):
  words = [input () for _ in range (3)]
  fix_free = True
  for i in range (len (words)):
    for j in range (len (words)):
      if i == j:
        pass
      elif words [i].startswith (words [j]) or words [i].endswith (words [j]):
        fix_free = False
  if fix_free:
    print ("Yes")
  else:
    print ("No")
