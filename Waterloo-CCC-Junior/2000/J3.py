quarters = int (input())
machine1 = int (input())
machine2 = int (input())
machine3 = int (input())

machines = [[machine1, 35, 30], [machine2, 100, 60], [machine3, 10, 9]]
total = quarters * 0.25
index = 0
count = 0

while total >= 0.25:
  for i in machines:
    count += 1
    total -= 0.25
    i[0] += 1
    if i[0] % i[1] == 0:
      total += i[2] * 0.25
    if total < 0.25:
      break
      
print ("Martha plays", count, "times before going broke.")      
      
