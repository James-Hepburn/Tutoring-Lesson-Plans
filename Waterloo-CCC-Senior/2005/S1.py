# ccc senior s1 2005 - https://dmoj.ca/problem/ccc05s1

t = int (input ())

characters = {'A':2, 'B':2, 'C':2, 'D':3, 'E':3, 'F':3, 'G':4, 'H':4, 'I':4, 'J':5, 'K':5, 'L':5, 'M':6, 'N':6, 'O':6, 'P':7, 'Q':7, 'R':7, 'S':7, 'T':8, 'U':8, 'V':8, 'W':9, 'X':9, 'Y':9, 'Z':9}

for _ in range (t):
  phone = input ()
  conversion = ""
  
  for i in phone:
    if i.isdigit ():
      conversion += str (i)
    elif i.isalpha ():
      conversion += str (characters [i])
      
    if len (conversion) == 3:
      conversion += '-'
    elif len (conversion) == 7:
      conversion += '-'
    elif len (conversion) == 12:
      break
      
  print (conversion)
