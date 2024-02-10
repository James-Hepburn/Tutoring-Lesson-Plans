# ccc senior s2 2020 - https://dmoj.ca/problem/ccc20s2

def can_escape (m, n, room):
  visited = []
  queue = [[1, 1]]

  while len (queue) != 0:
    r, c = queue.pop(0)
    visited.append ([r, c])

    x = room [r - 1][c - 1]

    for a in range (1, int (x ** 0.5) + 1):
      if x % a == 0:
        b = x // a
        if a <= m and b <= n and [a, b] not in visited:
          queue.append ([a, b])
        if b <= m and a <= n and [b, a] not in visited:
          queue.append ([b, a])

  return [m, n] in visited

m = int (input())
n = int (input())
room = []

for i in range (m):
  row = [int (j) for j in input().split()]
  room.append (row)

if can_escape (m, n, room) == True:
  print ("yes")
else:
  print ("no")
