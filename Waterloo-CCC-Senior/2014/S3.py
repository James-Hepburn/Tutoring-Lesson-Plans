# ccc senior s3 2014 - https://dmoj.ca/problem/ccc14s3

t = int (input ())

for _ in range (t):
  n = int (input ())

  mountain = [int (input ()) for _ in range (n)]
  branch = []
  order = 1

  while True:
    if len (mountain) != 0 and mountain [-1] == order:
      mountain.pop ()
      order += 1
    elif len (branch) != 0 and branch [-1] == order:
      branch.pop ()
      order += 1
    elif len (mountain) != 0:
      branch.append (mountain [-1])
      mountain.pop ()

    if len (mountain) == 0 and len (branch) == 0:
      print ("Y")
      break
    elif len (mountain) == 0 and branch [-1] != order:
      print ("N")
      break
