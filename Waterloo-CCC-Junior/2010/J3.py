A = 0
B = 0

while True:
  instruction = input().split()
  if instruction[0] == "1":
    if instruction[1] == "A":
      A = int (instruction[2])
    else:
      B = int (instruction[2])
  elif instruction[0] == "2":
    if instruction[1] == "A":
      print (A)
    else:
      print (B)
  elif instruction[0] == "3":
    if instruction[1] == "A" and instruction[2] == "A":
      A = A + A
    elif instruction[1] == "A" and instruction[2] == "B":
      A = A + B
    elif instruction[1] == "B" and instruction[2] == "A":
      B = B + A
    else:
      B = B + B
  elif instruction[0] == "4":
    if instruction[1] == "A" and instruction[2] == "A":
      A = A * A
    elif instruction[1] == "A" and instruction[2] == "B":
      A = A * B
    elif instruction[1] == "B" and instruction[2] == "A":
      B = B * A
    else:
      B = B * B
  elif instruction[0] == "5":
    if instruction[1] == "A" and instruction[2] == "A":
      A = A - A
    elif instruction[1] == "A" and instruction[2] == "B":
      A = A - B
    elif instruction[1] == "B" and instruction[2] == "A":
      B = B - A
    else:
      B = B - B
  elif instruction[0] == "6":
    if instruction[1] == "A" and instruction[2] == "A":
      A = A // A
    elif instruction[1] == "A" and instruction[2] == "B":
      A = A // B
    elif instruction[1] == "B" and instruction[2] == "A":
      B = B // A
    else:
      B = B // B
  else:
    break
    
