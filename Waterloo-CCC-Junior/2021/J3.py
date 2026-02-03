previous = ""    
    
while True:
  instruction = input()
  if instruction == "99999":
    break
  else:
    sum = int (instruction[0]) + int (instruction[1])
    if sum % 2 != 0 and sum != 0:
      previous = "left"
    elif sum % 2 == 0 and sum != 0:
      previous = "right"
    print (previous, instruction[2:])
   
