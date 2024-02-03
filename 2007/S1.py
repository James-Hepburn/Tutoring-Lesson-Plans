# ccc senior s1 2007 - https://dmoj.ca/problem/ccc07s1

n = int (input ())

for _ in range (n):
  year, month, day = [int (i) for i in input ().split ()]
  if 2007 - year > 18:
    print ("Yes")
  elif 2007 - year == 18 and month < 2:
    print ("Yes")
  elif 2007 - year == 18 and month == 2 and day <= 27:
    print ("Yes")
  else:
    print ("No")
    
