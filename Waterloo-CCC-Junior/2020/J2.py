P = int (input())
N = int (input())
R = int (input())

total_infected = N
day_count = 0

while total_infected <= P:
  total_infected += N * R
  N *= R
  day_count += 1
  
print (day_count)
