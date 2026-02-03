t = int (input())
c = int (input())

chores = []
for i in range (c):
  chores.append (int (input()))
  
chores.sort()  

total = 0
count = 0

for i in chores:
  if total + i <= t:
    total += i
    count += 1
  else:
    print (count)
    break
