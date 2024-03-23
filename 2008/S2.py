# ccc senior s2 2008 - https://dmoj.ca/problem/ccc08s2

def calculate_pennies (radius):
  pennies = 0
  for i in range (1, radius + 1):
    for j in range (0, radius + 1):
      point = (i * i) + (j * j)
      if point <= radius * radius:
        pennies += 1
      else:
        break
  return int ((pennies * 4) + 1) # split circle into 4 quadrants + center penny

while True:
  radius = int (input ())
  if radius == 0:
    break
  print (calculate_pennies (radius))
