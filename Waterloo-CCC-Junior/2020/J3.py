N = int (input())

max_x = 0
min_x = 100
max_y = 0
min_y = 100

for i in range (N):
  coordinate = input().split(',')
  max_x = max (int(coordinate[0]), max_x)
  min_x = min (int(coordinate[0]), min_x)
  max_y = max (int(coordinate[1]), max_y)
  min_y = min (int(coordinate[1]), min_y)
  
print (str (min_x - 1) + "," + str (min_y - 1))
print (str (max_x + 1) + "," + str (max_y + 1))
