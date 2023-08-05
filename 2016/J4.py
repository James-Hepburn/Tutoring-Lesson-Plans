starting_time = input ().split(":")

starting_minutes = (int (starting_time[0]) * 60) + int (starting_time[1])
traffic_7am = 7 * 60
traffic_10am = 10 * 60
traffic_3pm = 15 * 60
traffic_7pm = 19 * 60
duration = 240

while duration > 0:
  if starting_minutes >= traffic_7am and starting_minutes < traffic_10am:
    duration -= 1
  elif starting_minutes >= traffic_3pm and starting_minutes < traffic_7pm:
    duration -= 1
  else:
    duration -= 2
  starting_minutes += 1

HH = (starting_minutes // 60) % 24
MM = starting_minutes % 60

if HH <= 9:
  HH = "0" + str (HH)
if MM <= 9:
  MM = "0" + str (MM)
  
print (str (HH) + ":" + str (MM))
