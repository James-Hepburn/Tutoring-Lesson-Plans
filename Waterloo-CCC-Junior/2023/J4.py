C = int (input())
row1 = input().split()
row2 = input().split()

total = (row1.count ("1") + row2.count ("1")) * 3

for i in range (C - 1):
  if row1[i] == row1[i+1] == "1":
    total -= 2
  if row2[i] == row2[i+1] == "1":
    total -= 2

for i in range (0, C, 2):
  if row1[i] == row2[i] == "1":
    total -= 2
    
print (total)    
