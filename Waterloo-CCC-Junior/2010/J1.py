i = int (input())

combinations = []

for j in range (0, 6):
  for k in range (0, 6):
    if j + k == i and [j, k] not in combinations and [k, j] not in combinations:
      combinations.append ([j, k])
      
print (len (combinations))
