# ccc senior s2 2023 - https://dmoj.ca/problem/ccc23s2

n = int (input ())
heights = [int (i) for i in input ().split ()]
output = []

for i in range (1, n + 1):
  min_total = 10 ** 5
  for j in range (n - i + 1):
    photo = heights [j : j + i]
    left = 0
    right = len (photo) - 1
    total = 0
    while left <= right:
      total += abs (photo [left] - photo [right])
      left += 1
      right -= 1
    min_total = min (total, min_total)
  output.append (str (min_total))

print (" ".join (output))
