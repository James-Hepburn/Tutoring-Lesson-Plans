line = input().split()

start = int (line[0])
total = int (line[1])
dates = []

row1 = ["   " for i in range (start - 1)]
for i in range (1, 8 - start + 1):
  row1.append ("  " + str (i))
dates.append (row1)

row = []
counter = 0

for i in range (8 - start + 1, total + 1):
  counter += 1
  if (counter - 1) % 7 == 0 and counter != 1:
    dates.append (row)
    row = []
  if len (str (i)) == 1:
    row.append ("  " + str (i))
  else:
    row.append (" " + str (i))
dates.append (row)
    
print ("Sun Mon Tue Wed Thr Fri Sat")
for i in dates:
  print (" ".join (i))
  
