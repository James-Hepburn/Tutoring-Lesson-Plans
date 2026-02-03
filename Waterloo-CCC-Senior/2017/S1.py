# ccc senior s1 2017 - https://dmoj.ca/problem/ccc17s1

n = int (input ())
swifts = [int (i) for i in input ().split ()]
semaphores = [int (i) for i in input ().split ()]

total_swifts = 0
total_semaphores = 0
total_days = 0

for i in range (n):
  total_swifts += swifts [i]
  total_semaphores += semaphores [i]
  if total_swifts == total_semaphores:
    total_days = i + 1

print (total_days)
