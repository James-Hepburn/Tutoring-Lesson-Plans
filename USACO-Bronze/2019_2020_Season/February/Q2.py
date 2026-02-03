# USACO 2020 February - Bronze Level - Problem 2. Mad Scientist - http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

n = int (input ())
a = input ()
b = input ()

counter = 0
i = 0

while i < n:
  if a [i] != b [i]:
    for j in range (i + 1, n):
      if a [j] == b [j]:
        i = j
        counter += 1
        break
  i += 1

print (counter)
