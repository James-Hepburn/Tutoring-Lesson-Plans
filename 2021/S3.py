# ccc senior s3 2021 - https://dmoj.ca/problem/ccc21s3

n = int (input ())

friends = []
min_pos = 1000000000
max_pos = 0

for _ in range (n):
  p, w, d = [int (i) for i in input ().split ()]
  min_pos = min (min_pos, p)
  max_pos = max (max_pos, p)
  friends.append ([p, w, d])

minimum_time = 1000000000

for i in range (min_pos, max_pos + 1):
  total_time = 0
  for j in friends:
    distance = abs (j [0] - i)
    if distance > j [2]:
      move = distance - j [2]
      total_time += move * j [1]
  minimum_time = min (minimum_time, total_time)

print (minimum_time)
