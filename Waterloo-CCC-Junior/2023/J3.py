N = int (input())
availability = [0, 0, 0, 0, 0]

for i in range (N):
  person = input()
  for j in range (5):
    if person[j] == "Y":
      availability[j] += 1
      
most_people = max (availability)
days_possible = []

for i in range (5):
  if availability[i] == most_people:
    days_possible.append (str(i+1))
    
print (",".join (days_possible))
