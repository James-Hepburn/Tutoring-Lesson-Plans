a = int (input())
b = int (input())
c = int (input())
d = int (input())
s = int (input())

nikky_position = 0
nikky_total = 0

while True:
  if nikky_total >= s:
    break
  else:
    nikky_position += a
    nikky_total += a
  if nikky_total >= s:
    break
  else:
    nikky_position -= b
    nikky_total += b

byron_position = 0
byron_total = 0

while True:
  if byron_total >= s:
    break
  else:
    byron_position += c
    byron_total += c
  if byron_total >= s:
    break
  else:
    byron_position -= d
    byron_total += d
   
nikky_final = nikky_position - nikky_total - s
byron_final = byron_position - byron_total - s
  
if nikky_final > byron_final:
  print ("Nikky")
elif nikky_final < byron_final:
  print ("Byron")
else:
  print ("Tied")
