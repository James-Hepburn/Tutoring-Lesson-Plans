# USACO 2015 December - Bronze Level - Problem 2. Speeding Ticket - http://www.usaco.org/index.php?page=viewproblem2&cpid=568

n, m = [int (i) for i in input ().split ()]
road_info = [[int (i) for i in input ().split ()] for _ in range (n)]
cow_info = [[int (i) for i in input ().split ()] for _ in range (m)]

max_speed = 0

for i in range (1, 101):
  road_pos = 1
  road_speed = -1
  for j in road_info:
    if road_pos <= i < j [0] + road_pos:
      road_speed = j [1]
      break
    road_pos += j [0]

  cow_pos = 1
  cow_speed = -1
  for j in cow_info:
    if cow_pos <= i < j [0] + cow_pos:
      cow_speed = j [1]
      break
    cow_pos += j [0]

  speed = max (0, cow_speed - road_speed)
  max_speed = max (speed, max_speed)

print (max_speed)
