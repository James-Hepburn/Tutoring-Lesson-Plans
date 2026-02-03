# USACO 2016 January - Bronze Level - Problem 2. Angry Cows - http://www.usaco.org/index.php?page=viewproblem2&cpid=592

n = int (input ())
positions = [int (input ()) for _ in range (n)]

positions.sort ()
max_count = 0

for i in range (n):
  hay_bale = positions [i]
  exploded = [hay_bale]
  left = hay_bale
  right = hay_bale
  radius = 1
  count = 0
  while True:
    found = False
    new_left = left
    new_right = right
    for j in range (n):
      new_hay_bale = positions [j]
      x_start_1 = left - radius
      x_end_1 = left + radius
      x_start_2 = right - radius
      x_end_2 = right + radius
      condition_1 = x_start_1 <= new_hay_bale <= x_end_1
      condition_2 = x_start_2 <= new_hay_bale <= x_end_2
      if new_hay_bale not in exploded and (condition_1 or condition_2):
        exploded.append (new_hay_bale)
        new_right = max (new_right, x_end_1)
        new_right = max (new_right, x_end_2)
        new_left = min (new_left, x_start_1)
        new_left = min (new_left, x_start_2)
        found = True
        count += 1
    max_count = max (max_count, count)
    right = new_right
    left = new_left
    radius += 1
    if not found:
      break

print (max_count)
