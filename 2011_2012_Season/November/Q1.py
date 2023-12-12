# http://www.usaco.org/index.php?page=viewproblem2&cpid=84

d, h, m = [int (i) for i in input().split()]

start_minutes = (11 * 24 * 60) + (11 * 60) + 11
end_minutes = (d * 24 * 60) + (h * 60) + m

difference = end_minutes - start_minutes

if difference < 0:
  print (-1)
else:
  print (difference)
