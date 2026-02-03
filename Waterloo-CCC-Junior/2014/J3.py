n = int (input())

antonia = 100
david = 100

for i in range (n):
  rolls = input().split()
  if int (rolls[0]) > int (rolls[1]):
    david -= int (rolls[0])
  elif int (rolls[0]) < int (rolls[1]):
    antonia -= int (rolls[1])
    
print (antonia)
print (david)
    
