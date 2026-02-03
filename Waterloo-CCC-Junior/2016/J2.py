row1 = input().split()
row2 = input().split()
row3 = input().split()
row4 = input().split()

row1_sum = int (row1[0]) + int (row1[1]) + int (row1[2]) + int (row1[3]) 
row2_sum = int (row2[0]) + int (row2[1]) + int (row2[2]) + int (row2[3]) 
row3_sum = int (row3[0]) + int (row3[1]) + int (row3[2]) + int (row3[3]) 
row4_sum = int (row4[0]) + int (row4[1]) + int (row4[2]) + int (row4[3]) 

column1_sum = int (row1[0]) + int (row2[0]) + int (row3[0]) + int (row4[0]) 
column2_sum = int (row1[1]) + int (row2[1]) + int (row3[1]) + int (row4[1]) 
column3_sum = int (row1[2]) + int (row2[2]) + int (row3[2]) + int (row4[2]) 
column4_sum = int (row1[3]) + int (row2[3]) + int (row3[3]) + int (row4[3]) 

if row1_sum == row2_sum == row3_sum == row4_sum == column1_sum == column2_sum == column3_sum == column4_sum:
  print ("magic")
else:
  print ("not magic")
  
