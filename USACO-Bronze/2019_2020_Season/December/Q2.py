# USACO 2019 December - Bronze Level - Problem 2. Where Am I? - http://www.usaco.org/index.php?page=viewproblem2&cpid=964

n = int (input ())
houses = input ()

min_length = n

for i in range (n + 1):
  substring = houses [0 : i]
  if houses.count (substring) == 1:
    min_length = min (min_length, len (substring))

print (min_length)
