# http://www.usaco.org/index.php?page=viewproblem2&cpid=94

n = int (input ())
haybales = [int (input ()) for _ in range (n)]

height = sum (haybales) // n
count = 0

for i in haybales:
  count += abs (i - height)

print (count // 2)
