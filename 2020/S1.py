# ccc senior s1 2020 - https://dmoj.ca/problem/ccc20s1

n = int (input ())
stats = {}

for _ in range (n):
  time, pos = [int (i) for i in input ().split ()]
  stats [time] = pos

stats = dict (sorted (stats.items ()))

times = []
positions = []

for i in stats:
  times.append (i)
  positions.append (stats [i])

max_speed = 0

for i in range (n - 1):
  cur_time = times [i]
  next_time = times [i + 1]
  cur_pos = positions [i]
  next_pos = positions [i + 1]
  speed = abs (next_pos - cur_pos) / abs (next_time - cur_time)
  max_speed = max (max_speed, speed)

print (max_speed)
