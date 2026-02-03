year = int (input()) + 1

while True:
  list_version = [i for i in str (year)]
  if len(set(list_version)) == len (str(year)):
    print (year)
    break
  year += 1
  
