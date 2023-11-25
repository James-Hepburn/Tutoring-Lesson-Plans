line1 = input().split()
line2 = input().split()

x1 = int (line1[0])
y1 = int (line1[1])

x2 = int (line2[0])
y2 = int (line2[1])

board = [
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999],
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999], 
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999],
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999],
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999],
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999],
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999],
  [99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999]
]

def move_knight (x, y, steps):
  global board
  if 1 <= x <= 8 and 1 <= y <= 8 and steps < board[x - 1][y - 1]:
    board[x - 1][y - 1] = steps
    move_knight (x - 1, y + 2, steps + 1)
    move_knight (x - 1, y - 2, steps + 1)
    move_knight (x + 1, y + 2, steps + 1)
    move_knight (x + 1, y - 2, steps + 1)
    move_knight (x - 2, y + 1, steps + 1)
    move_knight (x - 2, y - 1, steps + 1)
    move_knight (x + 2, y + 1, steps + 1)
    move_knight (x + 2, y - 1, steps + 1)

move_knight (x1, y1, 0)

print (board[x2 - 1][y2 - 1])
