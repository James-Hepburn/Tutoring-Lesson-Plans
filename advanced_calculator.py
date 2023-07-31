print ("welcome to the calculator!")

print ("\nplease select one of the following options:\n")

print ("1) addition")
print ("2) subtraction")
print ("3) multiplication")
print ("4) division")

option = int (input ("your option: "))
print ()

if option == 1:
  a = int (input("first number: "))
  b = int (input("second number: "))
  print (a, "+", b, "=", a+b)

elif option == 2:
  a = int (input("first number: "))
  b = int (input("second number: "))
  print (a, "-", b, "=", a-b)

elif option == 3:
  a = int (input("first number: "))
  b = int (input("second number: "))
  print (a, "*", b, "=", a*b)

elif option == 4:
  a = int (input("first number: "))
  b = int (input("second number: "))
  print (a, "/", b, "=", a/b)

else:
  print ("invalid option")
