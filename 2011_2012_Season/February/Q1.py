# http://www.usaco.org/index.php?page=viewproblem2&cpid=112

n, l = [int (i) for i in input ().split ()]
knots = [int (input ()) for _ in range (n)]

knots.sort ()
valid = 0

for i in range (1, n):
  mid = (knots[i - 1] + knots[i]) / 2
  if mid == int (mid) and 0 < mid < l:
    valid += 1

print (valid)
