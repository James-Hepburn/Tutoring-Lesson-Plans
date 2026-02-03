def get_coordinates (grid, char):
  for i in range (len (grid)):
    for j in range (len (grid[i])):
      if grid[i][j] == char:
        return i, j

characters = 'A' + input() + '*'

grid = [
  ['A', 'B', 'C', 'D', 'E', 'F'],
  ['G', 'H', 'I', 'J', 'K', 'L'],
  ['M', 'N', 'O', 'P', 'Q', 'R'],
  ['S', 'T', 'U', 'V', 'W', 'X'],
  ['Y', 'Z', ' ', '-', '.', '*']
]

total = 0
current_row = 0
current_column = 0

for i in range (1, len(characters)):
  next_row, next_column = get_coordinates (grid, characters[i])
  total += abs (next_row - current_row) + abs (next_column - current_column)
  current_row = next_row
  current_column = next_column
      
print (total)
