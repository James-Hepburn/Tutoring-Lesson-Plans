# ccc senior s1 2006 - https://dmoj.ca/problem/ccc06s1

mother = input ()
father = input ()
x = int (input ())

for _ in range (x):
  baby = input ()
  valid = True
  j = 0
  
  for i in range (5):
    # if baby gene is lower, both parents need to be lower
    if baby [i].islower ():
      if mother [j] + mother [j + 1] != baby [i] + baby [i]:
        valid = False
      elif father [j] + father [j + 1] != baby [i] + baby [i]:
        valid = False
    # if baby gene is upper, one parent needs at least one upper
    else:
      if mother [j].islower () and mother [j + 1].islower ():
        valid = False
      elif father [j].islower () and father [j + 1].islower ():
        valid = False
    j += 2

  if valid:
    print ("Possible baby.")
  else:
    print ("Not their baby!")
