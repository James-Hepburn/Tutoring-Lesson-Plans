import math
import time
import os

row1 = ['01', '02', '03', '04', '05', '06']
row2 = ['07', '08', '09', '10', '11', '12']
row3 = ['13', '14', '15', '16', '17', '18']
row4 = ['19', '20', '21', '22', '23', '24']
row5 = ['25', '26', '27', '28', '29', '30']
row6 = ['31', '32', '33', '34', '35', '36']

player_type = " X"

def print_board ():
  print ()
  print (row1[0], row1[1], row1[2], "|", row1[3], row1[4], row1[5])
  print (row2[0], row2[1], row2[2], "|", row2[3], row2[4], row2[5])
  print (row3[0], row3[1], row3[2], "|", row3[3], row3[4], row3[5])
  print ("-------------------")
  print (row4[0], row4[1], row4[2], "|", row4[3], row4[4], row4[5])
  print (row5[0], row5[1], row5[2], "|", row5[3], row5[4], row5[5])
  print (row6[0], row6[1], row6[2], "|", row6[3], row6[4], row6[5])
  print ()

def rotate_quadrant1_left ():
  new_quadrant1 = [row1[2], row2[2], row3[2], row1[1], row2[1], row3[1], row1[0], row2[0], row3[0]]
  row1[0] = new_quadrant1[0]
  row1[1] = new_quadrant1[1]
  row1[2] = new_quadrant1[2]
  row2[0] = new_quadrant1[3]
  row2[1] = new_quadrant1[4]
  row2[2] = new_quadrant1[5]
  row3[0] = new_quadrant1[6]
  row3[1] = new_quadrant1[7]
  row3[2] = new_quadrant1[8]

def rotate_quadrant1_right():
  new_quadrant1 = [row3[0], row2[0], row1[0], row3[1], row2[1], row1[1], row3[2], row2[2], row1[2]]
  row1[0] = new_quadrant1[0]
  row1[1] = new_quadrant1[1]
  row1[2] = new_quadrant1[2]
  row2[0] = new_quadrant1[3]
  row2[1] = new_quadrant1[4]
  row2[2] = new_quadrant1[5]
  row3[0] = new_quadrant1[6]
  row3[1] = new_quadrant1[7]
  row3[2] = new_quadrant1[8]

def rotate_quadrant2_left():
  new_quadrant2 = [row1[5], row2[5], row3[5], row1[4], row2[4], row3[4], row1[3], row2[3], row3[3]]
  row1[3] = new_quadrant2[0]
  row1[4] = new_quadrant2[1]
  row1[5] = new_quadrant2[2]
  row2[3] = new_quadrant2[3]
  row2[4] = new_quadrant2[4]
  row2[5] = new_quadrant2[5]
  row3[3] = new_quadrant2[6]
  row3[4] = new_quadrant2[7]
  row3[5] = new_quadrant2[8]

def rotate_quadrant2_right():
  new_quadrant2 = [row3[3], row2[3], row1[3], row3[4], row2[4], row1[4], row3[5], row2[5], row1[5]]
  row1[3] = new_quadrant2[0]
  row1[4] = new_quadrant2[1]
  row1[5] = new_quadrant2[2]
  row2[3] = new_quadrant2[3]
  row2[4] = new_quadrant2[4]
  row2[5] = new_quadrant2[5]
  row3[3] = new_quadrant2[6]
  row3[4] = new_quadrant2[7]
  row3[5] = new_quadrant2[8]

def rotate_quadrant3_left():
  new_quadrant3 = [row4[2], row5[2], row6[2], row4[1], row5[1], row6[1], row4[0], row5[0], row6[0]]
  row4[0] = new_quadrant3[0]
  row4[1] = new_quadrant3[1]
  row4[2] = new_quadrant3[2]
  row5[0] = new_quadrant3[3]
  row5[1] = new_quadrant3[4]
  row5[2] = new_quadrant3[5]
  row6[0] = new_quadrant3[6]
  row6[1] = new_quadrant3[7]
  row6[2] = new_quadrant3[8]

def rotate_quadrant3_right():
  new_quadrant3 = [row6[0], row5[0], row4[0], row6[1], row5[1], row4[1], row6[2], row5[2], row4[2]]
  row4[0] = new_quadrant3[0]
  row4[1] = new_quadrant3[1]
  row4[2] = new_quadrant3[2]
  row5[0] = new_quadrant3[3]
  row5[1] = new_quadrant3[4]
  row5[2] = new_quadrant3[5]
  row6[0] = new_quadrant3[6]
  row6[1] = new_quadrant3[7]
  row6[2] = new_quadrant3[8]

def rotate_quadrant4_left():
  new_quadrant4 = [row4[5], row5[5], row6[5], row4[4], row5[4], row6[4], row4[3], row5[3], row6[3]]
  row4[3] = new_quadrant4[0]
  row4[4] = new_quadrant4[1]
  row4[5] = new_quadrant4[2]
  row5[3] = new_quadrant4[3]
  row5[4] = new_quadrant4[4]
  row5[5] = new_quadrant4[5]
  row6[3] = new_quadrant4[6]
  row6[4] = new_quadrant4[7]
  row6[5] = new_quadrant4[8]

def rotate_quadrant4_right():
  new_quadrant4 = [row6[3], row5[3], row4[3], row6[4], row5[4], row4[4], row6[5], row5[5], row4[5]]
  row4[3] = new_quadrant4[0]
  row4[4] = new_quadrant4[1]
  row4[5] = new_quadrant4[2]
  row5[3] = new_quadrant4[3]
  row5[4] = new_quadrant4[4]
  row5[5] = new_quadrant4[5]
  row6[3] = new_quadrant4[6]
  row6[4] = new_quadrant4[7]
  row6[5] = new_quadrant4[8]

def check_win (type):
  if row1[0] == row1[1] == row1[2] == row1[3] == row1[4] == type:
    return True
  elif row1[1] == row1[2] == row1[3] == row1[4] == row1[5] == type:
    return True
  elif row2[0] == row2[1] == row2[2] == row2[3] == row2[4] == type:
    return True
  elif row2[1] == row2[2] == row2[3] == row2[4] == row2[5] == type:
    return True
  elif row3[0] == row3[1] == row3[2] == row3[3] == row3[4] == type:
    return True
  elif row3[1] == row3[2] == row3[3] == row3[4] == row3[5] == type:
    return True
  elif row4[0] == row4[1] == row4[2] == row4[3] == row4[4] == type:
    return True
  elif row4[1] == row4[2] == row4[3] == row4[4] == row4[5] == type:
    return True
  elif row5[0] == row5[1] == row5[2] == row5[3] == row5[4] == type:
    return True
  elif row5[1] == row5[2] == row5[3] == row5[4] == row5[5] == type:
    return True
  elif row6[0] == row6[1] == row6[2] == row6[3] == row6[4] == type:
    return True
  elif row6[1] == row6[2] == row6[3] == row6[4] == row6[5] == type:
    return True

  for i in range (6):
    if row1[i] == row2[i] == row3[i] == row4[i] == row5[i] == type:
      return True
    elif row2[i] == row3[i] == row4[i] == row5[i] == row6[i] == type:
      return True

  return False

def check_row (row, square):
  for i in range (6):
    if row[i] == square:
      return i
  return -1

while True:

  time.sleep (3)
  os.system ('clear')
  
  print_board ()
  
  square = input("Pick a square player" + player_type + ": ")
  quadrant = int (input("Which quadrant would you like to rotate? "))
  direction = input("Would you like to rotate left or right? ")

  if len (square) == 1:
    square = '0' + square

  index1 = check_row (row1, square)
  index2 = check_row (row2, square)
  index3 = check_row (row3, square)
  index4 = check_row (row4, square)
  index5 = check_row (row5, square)
  index6 = check_row (row6, square)

  if index1 != -1:
    row1[index1] = player_type
  elif index2 != -1:
    row2[index2] = player_type
  elif index3 != -1:
    row3[index3] = player_type
  elif index4 != -1:
    row4[index4] = player_type
  elif index5 != -1:
    row5[index5] = player_type
  elif index6 != -1:
    row6[index6] = player_type
  else:
    print ("\nInvalid square.")
  
  if quadrant < 1 or quadrant > 4:
    print ("\nInvalid quadrant.")
  elif direction != "left" and direction != "right":
    print ("\nInvalid direction.")
  elif quadrant == 1 and direction == "left":
    rotate_quadrant1_left ()
  elif quadrant == 1 and direction == "right":
    rotate_quadrant1_right ()
  elif quadrant == 2 and direction == "left":
    rotate_quadrant2_left ()
  elif quadrant == 2 and direction == "right":
    rotate_quadrant2_right ()
  elif quadrant == 3 and direction == "left":
    rotate_quadrant3_left ()
  elif quadrant == 3 and direction == "right":
    rotate_quadrant3_right ()
  elif quadrant == 4 and direction == "left":
    rotate_quadrant4_left ()
  elif quadrant == 4 and direction == "right":
    rotate_quadrant4_right ()
  
  if check_win (player_type):
    print ("\nPlayer" + player_type + " won!")
    break
  
  if player_type == " X":
    player_type = " O"
  else:
    player_type = " X"
