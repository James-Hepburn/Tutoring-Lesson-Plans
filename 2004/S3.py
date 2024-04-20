# ccc senior s3 2004 - https://dmoj.ca/problem/ccc04s3

def get_value (s):
  if 'A' <= s [0] <= 'J':
    row = ord (s [0]) - ord ('A')
    col = int (s [1]) - 1
    return values [row][col]
  else:
    return int (s)

def calculate_value (s):
  v = 0
  for i in s.split ("+"):
    x = get_value (i)
    if x == -1:
      v = -1
      break
    else:
      v += x
  return v

formula = [input ().split () for _ in range (10)]
values = [[-1 for _ in range (9)] for _ in range (10)]

while True:
  continue_running = False
  for i in range (10):
    for j in range (9):
      v = calculate_value (formula [i][j])
      if values [i][j] != v:
        values [i][j] = v
        continue_running = True
  if not continue_running:
    break

for i in range (10):
  for j in range (9):
    if values [i][j] == -1:
      print ("*", end = " ")
    else:
      print (values [i][j], end = " ")
  print ()
