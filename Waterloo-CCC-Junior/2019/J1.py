A = 0
B = 0

for i in range (2):
  if i == 0:
    A += int (input()) * 3
    A += int (input()) * 2
    A += int (input())
  else:
    B += int (input()) * 3
    B += int (input()) * 2
    B += int (input())
    
if A > B:
  print ("A")
elif A < B:
  print ("B")
else:
  print ("T")
  
