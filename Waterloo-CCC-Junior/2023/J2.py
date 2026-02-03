def calculate_spice_level (pepper):
  if pepper == "Poblano":
    return 1500
  elif pepper == "Mirasol":
    return 6000
  elif pepper == "Serrano":
    return 15500
  elif pepper == "Cayenne":
    return 40000
  elif pepper == "Thai":
    return 75000
  return 125000

N = int (input())
T = 0

for i in range (N):
  pepper = input()
  T += calculate_spice_level (pepper)
  
print (T)
