def rotate (matrix, size):
  rotated_matrix = []
  for i in range (size):
    rotated_matrix.append([0] * size)

  for i in range (size):
    for j in range (size):
      rotated_matrix[j][size - 1 - i] = matrix[i][j]

  return rotated_matrix

def valid_grid (grid):
  for i in grid:
    for j in range (len (grid) - 1):
      if i[j] >= i[j+1]:
        return False
  for i in range (len (grid[0])):
    for j in range (len (grid) - 1):
      if grid[j][i] >= grid[j+1][i]:
        return False
  return True

N = int (input())
grid = []

for i in range (N):
  grid.append ([int (i) for i in input().split()])
  
while not valid_grid (grid):
  grid = rotate (grid, N)
   
for i in grid:
  str_i = [str(j) for j in i]
  print (" ".join (str_i))
