# ccc senior s2 2024 - https://dmoj.ca/problem/ccc24s2

t, n = [int (i) for i in input ().split ()]

for _ in range (t):
  string = input ()
  valid = True
  for i in range (n - 1):
    if string.count (string [i]) == string.count (string [i + 1]) == 1:
      valid = False
      break
    elif string.count (string [i]) > 1 and string.count (string [i + 1]) > 1:
      valid = False
      break
  if valid:
    print ("T")
  else:
    print ("F")
