# http://www.usaco.org/index.php?page=viewproblem2&cpid=205

b, e = [int (i) for i in input().split()]
b_values = [input().split() for _ in range (b)]
e_values = [input().split() for _ in range (e)]

b_pos = [0] * 1000001
b_steps = 0
index = 1

for i in b_values:
  dx = 1
  if i[1] == "L":
    dx = -1
  b_steps += int (i[0])
  for _ in range (int (i[0])):
    b_pos[index] = b_pos[index - 1] + dx
    index += 1

for i in range (b_steps + 1, len (b_pos)):
  b_pos[i] = b_pos[b_steps]

e_pos = [0] * 1000001
e_steps = 0
index = 1

for i in e_values:
  dx = 1
  if i[1] == "L":
    dx = -1
  e_steps += int (i[0])
  for _ in range (int (i[0])):
    e_pos[index] = e_pos[index - 1] + dx
    index += 1

for i in range (e_steps + 1, len (e_pos)):
  e_pos[i] = e_pos[b_steps]

count = 0

for i in range (1, max (e_steps, b_steps) + 1):
  if b_pos[i-1] != e_pos[i-1] and b_pos[i] == e_pos[i]:
    count += 1

print (count)
