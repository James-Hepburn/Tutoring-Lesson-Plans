# ccc s2 2004 - https://dmoj.ca/problem/ccc04s2

n, k = [int (i) for i in input ().split ()]

yodellers = {}
for i in range (1, n + 1):
  yodellers [i] = [0, 0]

for _ in range (k):
  round = [int (i) for i in input ().split ()]
  for j in range (n):
    yodellers [j + 1][0] += round [j]
  for j in range (1, n + 1):
    rank = 1
    for k in range (1, n + 1):
      if j != k and yodellers [j][0] < yodellers [k][0]:
        rank += 1
    yodellers [j][1] = max (rank, yodellers [j][1])

yodellers = sorted (yodellers.items (), key = lambda x : (- x [1][0], x [0]))
score = yodellers [0][1][0]

for i in yodellers:
  if i [1][0] == score:
    print ("Yodeller", i [0], "is the TopYodeller: score " + str (i [1][0]) + ", worst rank", i [1][1])
