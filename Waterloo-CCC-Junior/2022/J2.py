N = int (input())
star_rating = 0

for i in range (N):
  points = int (input())
  fouls = int (input())
  stars = (points * 5) - (fouls * 3)
  if stars > 40:
    star_rating += 1
    
if star_rating == N:
  print (str(star_rating) + "+")
else:
  print (star_rating)
  
