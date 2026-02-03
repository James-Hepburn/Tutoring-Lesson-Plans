cities = input().split()

print (0, cities[0], int(cities[0]) + int(cities[1]), int(cities[0]) + int(cities[1]) + int(cities[2]), int(cities[0]) + int(cities[1]) + int(cities[2]) + int(cities[3]))
print (cities[0], 0, cities[1], int(cities[1]) + int(cities[2]), int(cities[1]) + int(cities[2]) + int(cities[3]))
print (int(cities[0]) + int(cities[1]), cities[1], 0, cities[2], int(cities[2]) + int(cities[3]))
print (int(cities[0]) + int(cities[1]) + int(cities[2]), int(cities[1]) + int(cities[2]), cities[2], 0, cities[3])
print (int(cities[0]) + int(cities[1]) + int(cities[2]) + int(cities[3]), int(cities[1]) + int(cities[2]) + int(cities[3]), int(cities[2]) + int(cities[3]), cities[3], 0)
  
