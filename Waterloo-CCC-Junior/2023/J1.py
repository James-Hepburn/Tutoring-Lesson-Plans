P = int (input())
C = int (input())

points = (P * 50) - (C * 10)

if P > C:
  print (points + 500)
else:
  print (points)
  
