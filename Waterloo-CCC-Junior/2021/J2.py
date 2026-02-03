N = int (input())

highest_bid = 0
winner = ""

for i in range (N):
  name = input()
  bid = int (input())
  if bid > highest_bid:
    winner = name
    highest_bid = bid
    
print (winner)
    
