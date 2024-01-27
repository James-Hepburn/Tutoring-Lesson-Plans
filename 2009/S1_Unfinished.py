# ccc senior s1 2009 - https://dmoj.ca/problem/ccc09s1

a = int (input ())
b = int (input ())

count = 0

for i in range (a, b + 1):
  power_2 = int (i ** 0.5)
  power_3 = int (i ** 0.3)
  if i == power_2 ** 2 and i == power_3 ** 3:
    count += 1

print (count)
