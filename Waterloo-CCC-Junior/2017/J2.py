N = int (input())
k = int (input())

total = N

for i in range (k):
  total += int(str (N) + ("0" * (i + 1)))
  
print (total)  
  
