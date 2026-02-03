sequence = input()

longest = 0

for i in range (len (sequence)):
  for j in range (i, len(sequence)):
    substring = sequence[i:j+1]
    if substring == substring[::-1]:
      longest = max (len (substring), longest)
      
print (longest)
      
