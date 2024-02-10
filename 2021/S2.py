# ccc senior s2 2021 - https://dmoj.ca/problem/ccc21s2

M = int (input())
N = int (input())
K = int (input())
rows = [0] * M
cols = [0] * N

for i in range (K):
  art = input().split()
  if art [0] == 'R':
    rows [int (art[1]) - 1] += 1
  else:
    cols [int (art[1]) - 1] += 1

gold = 0
for i in range (M):
  for j in range (N):
    if (rows [i] + cols [j]) % 2 == 1: # an odd number of instructions
      gold += 1
print(gold)
