# ccc senior s3 2015 - https://dmoj.ca/problem/ccc15s3

g = int (input ())
p = int (input ())

planes = [0] * g
outcome = 0

for _ in range (p):
  gate = int (input ()) - 1
  while gate >= 0:
    if planes [gate] == 0:
      planes [gate] = 1
      outcome += 1
      break
    gate -= 1
  if gate < 0:
    break

print (outcome)
