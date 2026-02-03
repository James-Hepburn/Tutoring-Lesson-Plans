month = int (input())
day = int (input())

if day == 18 and month == 2:
  print ("Special")
elif (day <= 18 and month == 2) or month == 1:
  print ("Before")
else:
  print ("After")
  
