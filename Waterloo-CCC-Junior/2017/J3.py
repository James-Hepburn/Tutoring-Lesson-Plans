starting_coordinate = input().split()
destination_coordinate = input().split()
electrical_charge = int (input())

needed_charge = abs (int (starting_coordinate[0]) - int (destination_coordinate[0])) + abs (int (starting_coordinate[1]) - int (destination_coordinate[1]))

if ((electrical_charge - needed_charge) % 2 == 0) and (electrical_charge >= needed_charge):
  print ("Y")
else:
  print ("N")
  
