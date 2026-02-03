# USACO 2020 December - Bronze Level - Problem 2. Daisy Chains - https://usaco.org/index.php?page=viewproblem2&cpid=1060

n = int (input ())
flowers = [int (i) for i in input ().split ()]

average_flowers = 0

for i in range (n):
  for j in range (i + 1, n + 1):
    petals = flowers [i : j]
    average = sum (petals) / len (petals)
    if average in petals:
      average_flowers += 1

print (average_flowers)
