t = input()
s = input()

found = False

for i in range (len (s)):
  if s in t:
    found = True
  s = s[1:] + s[0]

if found:
  print ("yes")
else:
  print ("no")
  
