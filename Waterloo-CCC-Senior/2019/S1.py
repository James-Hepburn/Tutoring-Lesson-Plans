# ccc senior s1 2019 - https://dmoj.ca/problem/ccc19s1

instructions = input ()
grid = [[1, 2], [3, 4]]

for i in instructions:
  if i == 'H':
    grid [0][0], grid [1][0] = grid [1][0], grid [0][0]
    grid [0][1], grid [1][1] = grid [1][1], grid [0][1]
  else:
    grid [0][0], grid [0][1] = grid [0][1], grid [0][0]
    grid [1][0], grid [1][1] = grid [1][1], grid [1][0]

print (grid [0][0], grid [0][1])
print (grid [1][0], grid [1][1])
