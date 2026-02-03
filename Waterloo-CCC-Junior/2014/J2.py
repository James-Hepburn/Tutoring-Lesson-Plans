V = int (input())
votes = input()

A = votes.count ("A")
B = votes.count ("B")

if A > B:
  print ("A")
elif A < B:
  print ("B")
else:
  print ("Tie")
  
