word = input()

count_valid = 0

for i in word:
  if i in "IOSHZXN":
    count_valid += 1
    
if count_valid == len (word):
  print ("YES")
else:
  print ("NO")
  
