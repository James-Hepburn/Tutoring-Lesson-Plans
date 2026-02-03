k = int (input())

icon = ["*x*", " xx", "* *"]

for i in icon:
  line = ""
  for j in i:
    line += j * k
  for j in range (k):
    print (line)
    
