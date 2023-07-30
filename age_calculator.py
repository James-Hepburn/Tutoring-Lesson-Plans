print ("Welcome to the Age Calculator! \n")

age = int (input("How old are you? "))

years = age
months = age * 12
days = age * 365
hours = days * 24
minutes = hours * 60
seconds = minutes * 60

print ("\nYou have been alive for ... \n")

print ("  -", years, "years")
print ("  -", months, "months")
print ("  -", days, "days")
print ("  -", hours, "hours")
print ("  -", minutes, "minutes")
print ("  -", seconds, "seconds")
