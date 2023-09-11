def square (rows):
  row_amount = 0
  
  while row_amount < rows:
    column_amount = 0
    line = ""
    
    while column_amount < rows:
      line += "* "
      column_amount += 1
      
    print (line)
    row_amount += 1

def triangle (rows):
  symbol_count = 1
  row_amount = 0
  
  while row_amount < rows:
    column_amount = 0
    line = ""
    
    while column_amount < symbol_count:
      line += "* "
      column_amount += 1
      
    print (line)
    row_amount += 1
    symbol_count += 1

def diamond (rows):
  half_point = rows // 2
  symbol_count = 1
  spaces_count = half_point
  row_amount = 0
  
  while row_amount < half_point:
    column_amount = 0
    line = ""
    
    while column_amount < spaces_count:
      line += "  "
      column_amount += 1
    column_amount = 0
    
    while column_amount < symbol_count:
      line += "* "
      column_amount += 1

    print (line)
    spaces_count -= 1
    symbol_count += 2
    row_amount += 1

  row_amount = 0
  while row_amount < half_point + 1:
    column_amount = 0
    line = ""
    
    while column_amount < spaces_count:
      line += "  "
      column_amount += 1
    column_amount = 0
    
    while column_amount < symbol_count:
      line += "* "
      column_amount += 1

    print (line)
    spaces_count += 1
    symbol_count -= 2
    row_amount += 1

print ("Welcome to the Pattern Creator! \n")

shape = input ("Which shape do you want? Square, Triangle or Diamond? ").lower()
rows = int (input ("How many rows does this shape have? "))

print ()

if shape == "square":
  square (rows)
elif shape == "triangle":
  triangle (rows)
elif shape == "diamond":
  diamond (rows)
else:
  print ("\nInvalid selection.")

print ()
