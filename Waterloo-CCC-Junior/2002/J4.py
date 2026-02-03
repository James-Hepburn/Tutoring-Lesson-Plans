import math

numerator = int (input())
denominator = int (input())

whole_number = numerator // denominator
remainder = numerator % denominator
gcd = math.gcd(remainder, denominator)
simplified_numerator = remainder // gcd
simplified_denominator = denominator // gcd
display = str (simplified_numerator) + "/" + str (simplified_denominator)

if whole_number == 0 and remainder == 0:
  print (0)
elif whole_number == 0 and remainder != 0:
  print (display)
elif remainder == 0:
  print (whole_number)
else:
  print (whole_number, display)
  
