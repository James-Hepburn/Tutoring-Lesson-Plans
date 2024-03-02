# ccc senior s2 2004 - https://dmoj.ca/problem/ccc04s2

n, k = [int (i) for i in input ().split ()]

yodellers = {}
for i in range (1, n + 1):
  yodellers [i] = [0, 0]

for _ in range (k):
  round = [int (i) for i in input ().split ()]
  for i in range (n):
    yodellers [i + 1][0] += round [i]
    rank = 0
    for j in round:
      if j > round [i]:
        rank += 1
    yodellers [i + 1][1] = rank + 1

winner = score = worst = 0
for i in yodellers:
  if yodellers [i][0] > score:
    score = yodellers [i][0]
    worst = yodellers [i][1]
    winner = i

print ("Yodeller", winner, "is the TopYodeller: score", score, "worst rank", worst)
