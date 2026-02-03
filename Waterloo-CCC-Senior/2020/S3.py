# ccc s3 2020 - https://dmoj.ca/problem/ccc20s3

from itertools import permutations

n = input ()
h = input ()

distinct = set (permutations (n))
counter = 0

for i in distinct:
  if "".join (i) in h:
    counter += 1

print (counter)
