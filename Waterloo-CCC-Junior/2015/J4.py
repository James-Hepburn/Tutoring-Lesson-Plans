m = int (input())
wait_time = 0
friends = {}
time = {}
received = {}

for i in range (m):
  command, value = input().split()
  value = int (value)

  if command == "W":
    wait_time += value - 2
  elif command == "R":
    received[value] = False
    time[value] = wait_time
  elif command == "S":
    received[value] = True
    if value in friends:
      friends[value] = friends[value] + wait_time - time[value] 
    else:
      friends[value] = wait_time - time[value]

  wait_time += 1

for i in sorted (received):
  if received[i] == False:
    friends[i] = -1
  print (i, friends[i])
  
