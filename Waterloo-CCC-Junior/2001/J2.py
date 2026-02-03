x = int (input())
m = int (input())

n = 1
count = 0

while n < m:
  if x * n % m == 1:
    print (n)
    count += 1
  n += 1
  
if count == 0:
  print ("No such integer exists.")
