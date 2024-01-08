# USACO 2015 February - Bronze Level - Problem 2. COW - http://www.usaco.org/index.php?page=viewproblem2&cpid=527

n = int (input ())
word = input ()

count = 0

for i in range (n):
  for j in range (i + 1, n):
    for k in range (j + 1, n):
      temp = word [i] + word [j] + word [k]
      if temp == "COW":
        count += 1

print (count)
