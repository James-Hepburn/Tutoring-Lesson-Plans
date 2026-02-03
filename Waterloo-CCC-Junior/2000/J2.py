def rotate (number):
  result = ""
  for i in number:
    if i in "180":
      result += i
    elif i == "6":
      result += "9"
    elif i == "9":
      result += "6"
    else:
      return False
  return result[::-1] == number 

m = int (input())
n = int (input())

count = 0

for i in range (m, n + 1):
  if rotate (str (i)):
    count += 1
    
print (count)
