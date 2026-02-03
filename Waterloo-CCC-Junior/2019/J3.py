N = int (input())

for i in range (N):
  line = input()
  result = []
  count = 1
  for j in range (len(line) - 1):
    if line[j] == line[j+1]:
      count += 1
    else:
      result.append (str(count) + " " + line[j])
      count = 1
  result.append (str(count) + " " + line[-1])
  print (" ".join (result))
  
