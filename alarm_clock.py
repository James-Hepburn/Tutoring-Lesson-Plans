import time
import os

print("Welcome to the Alarm Clock!")

future_hour = int(input("\nWhat hour is your alarm for? "))
future_minute = int(input("What minute is your alarm for? "))

current_hour = int(input("\nWhat hour is it currently? "))
current_minute = int(input("What minute is it currently? "))

remaining_seconds = 0
remaining_minutes = future_minute - current_minute
remaining_hours = future_hour - current_hour

if remaining_minutes < 0:
  remaining_minutes += 60
  remaining_hours -= 1

time.sleep(3)
os.system("clear")

while remaining_seconds != 0 or remaining_minutes != 0 or remaining_hours != 0:

  if remaining_seconds == 0:
    remaining_seconds = 59
    if remaining_minutes == 0:
      remaining_minutes = 59
      remaining_hours -= 1
    else:
      remaining_minutes -= 1
  else:
    remaining_seconds -= 1

  time.sleep(1)

  print("\nTime remaining:", remaining_hours, "hours,", remaining_minutes, "minutes, and", remaining_seconds, "seconds.")

print("\nAlarm reached! Time to wake up!")
