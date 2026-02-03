instructions = []

while True:
  text = input()
  if text == "L":
    instructions.append ("Turn RIGHT")
  elif text == "R":
    instructions.append ("Turn LEFT")
  elif text == "SCHOOL":
    instructions.insert (0, " into your HOME.")
    break
  else:
    instructions.append (" onto " + text + " street.")
    
for i in range (len (instructions) - 1, -1, -2):
  print (instructions[i] + instructions[i-1])
                
