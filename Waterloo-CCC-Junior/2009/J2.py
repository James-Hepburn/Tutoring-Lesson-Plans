trout = int (input())
pike = int (input())
pickerel = int (input())
total = int (input())

max_trout = total // trout
max_pike = total // pike
max_pickerel = total // pickerel

count = 0

for i in range (0, max_trout + 1):
  for j in range (0, max_pike + 1):
    for k in range (0, max_pickerel + 1):
      current_total = (i * trout) + (j * pike) + (k * pickerel)
      if current_total <= total and current_total != 0:
        print (i, "Brown Trout,", j, "Northern Pike,", k, "Yellow Pickerel")
        count += 1
        
print ("Number of ways to catch fish:", count)
