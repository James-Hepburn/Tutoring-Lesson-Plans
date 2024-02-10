# ccc senior s2 2019 - https://dmoj.ca/problem/ccc19s2

def is_prime (n):
  if n < 2:
    return False
  elif n == 2:
    return True
  elif n % 2 == 0:
    return False
  for i in range (3, int (n ** 0.5) + 1, 2):
    if n % i == 0:
      return False
  return True

t = int (input ())

for _ in range (t):
  n = int (input ())
  for i in range (3, n):
    a = i
    b = 2 * n - i
    if is_prime (a) and is_prime (b):
      print (a, b)
      break
  
