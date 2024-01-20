# ccc senior s1 2018 - https://dmoj.ca/problem/ccc18s1

n = int (input ())
positions = [int (input ()) for _ in range (n)]

positions.sort ()

neighborhoods = []
current = positions [0]

for i in range (n - 1):
  half = (positions [i + 1] - positions [i]) / 2
  neighborhoods.append ([current, half + positions [i]])
  current = half + positions [i]

neighborhoods.pop (0)

smallest_distance = neighborhoods [0][1] - neighborhoods [0][0]

for i in neighborhoods:
  distance = i [1] - i [0]
  smallest_distance = min (smallest_distance, distance)

print (smallest_distance)
