# ccc senior s2 2011 - https://dmoj.ca/problem/ccc11s2

n = int (input ())
student = [input () for _ in range (n)]
answer = [input () for _ in range (n)]

correct = 0

for i in range (n):
  if student [i] == answer [i]:
    correct += 1

print (correct)
