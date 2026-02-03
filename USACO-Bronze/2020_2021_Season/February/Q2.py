# USACO 2021 February - Bronze Level - Problem 2. Comfortable Cows - https://usaco.org/index.php?page=viewproblem2&cpid=1108

n = int (input ())
cows = [[int (i) for i in input ().split ()] for _ in range (n)]

def count_comfortable_cows (index):
  current_cows = cows [0 : index + 1]
  total_comfortable = 0
  for i in current_cows:
    directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    count_surrounding = 0
    for j in directions:
      if [i [0] + j [0], i [1] + j [1]] in current_cows:
        count_surrounding += 1
    if count_surrounding == 3:
      total_comfortable += 1
  return total_comfortable

for i in range (n):
  print (count_comfortable_cows (i))
