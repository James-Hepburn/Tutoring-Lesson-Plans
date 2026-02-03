X = int (input())
Y = int (input())

years = []

for i in range (X, Y + 1):
  years_passed = i - X
  if (years_passed % 4 == 0) and (years_passed % 2 == 0) and (years_passed % 3 == 0) and (years_passed % 5 == 0):
    years.append (i)
  
for i in years:
  print ("All positions change in year", i)
  
