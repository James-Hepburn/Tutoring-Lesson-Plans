# ccc senior s1 2020 - https://dmoj.ca/problem/ccc20s1

n = int (input ())
stats = []

for _ in range (n):
  time, pos = [int (i) for i in input ().split ()]
  stats.append ([time, pos])

stats = sorted (stats, key = lambda x : x [0])

max_speed = 0

for i in range (n - 1):
  cur_time = stats [i][0]
  next_time = stats [i + 1][0]
  cur_pos = stats [i][1]
  next_pos = stats [i + 1][1]
  speed = abs (next_pos - cur_pos) / abs (next_time - cur_time)
  max_speed = max (max_speed, speed)

print (max_speed)
