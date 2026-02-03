def count_divisors (number):
  count = 0
  for i in range (1, number + 1):
    if number % i == 0:
      count += 1
  return count

low = int (input())
high = int (input())

count = 0

for i in range (low, high + 1):
  if count_divisors (i) == 4:
    count += 1
    
print ("The number of RSA numbers between", low, "and", high, "is", count)
