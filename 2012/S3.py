# ccc senior s3 2012 - https://dmoj.ca/problem/ccc12s3

n = int (input ())
frequency = {}

for _ in range (n):
  r = int (input ())
  if r in frequency:
    frequency [r] += 1
  else:
    frequency [r] = 1

frequency = sorted (frequency.items (), key = lambda x : [- x [1], - x [0]])
r1 = frequency [0]
r2 = frequency [1]
r3 = frequency [2]
answer = abs (r1 [0] - r2 [0])

if r1 [1] == r2 [1]:
  values = []
  for i in frequency:
    if i [1] == r1 [1]:
      values.append (i [0])
  min_value = min (values)
  max_value = max (values)
  answer = abs (max_value - min_value)

elif r2 [1] == r3 [1]:
  for i in frequency:
    if i [1] == r2 [1]:
      answer = max (answer, abs (r1 [0] - i [0]))
      
print (answer)
