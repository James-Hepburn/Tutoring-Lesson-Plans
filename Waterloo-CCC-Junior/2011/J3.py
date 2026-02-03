t1 = int (input())
t2 = int (input())

count = 2

while True:
  temp = t1 - t2
  if temp < 0:
    print (count)
    break
  t1 = t2
  t2 = temp
  count += 1
