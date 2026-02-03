pink = int (input())
green = int (input())
red = int (input())
orange = int (input())
money = int (input())

smallest = 1000000
count = 0

for i in range (0, money+1):
  for j in range (0, money+1):
    for k in range (0, money+1):
      for l in range (0, money+1):
        if (i * pink) + (j * green) + (k * red) + (l * orange) == money:
          print ("# of PINK is", i, "# of GREEN is", j, "# of RED is", k, "# of ORANGE is", l)
          count += 1
          if i + j + k + l < smallest:
            smallest = i + j + k + l
          
print ("Total combinations is " + str (count) + ".")
print ("Minimum number of tickets to print is " + str (smallest) + ".")
