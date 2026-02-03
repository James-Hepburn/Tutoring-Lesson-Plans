n = int (input())

briefcases = {1:100, 2:500, 3:1000, 4:5000, 5:10000, 6:25000, 7:50000, 8:100000, 9:500000, 10:1000000}

for i in range (n):
  eliminated = int (input())
  del briefcases[eliminated]
  
average = 0

for i in briefcases:
  average += briefcases[i]
  
average /= len (briefcases)

bank_offer = int (input())

if average <= bank_offer:
  print ("deal")
else:
  print ("no deal")
  
