# ccc senior s1 2016 - https://dmoj.ca/problem/ccc16s1

first_string = input ()
second_string = input ()

unique_letters = set (first_string)
asterisks = 0

for i in unique_letters:
  first_amount = first_string.count (i)
  second_amount = second_string.count (i)
  if first_amount >= second_amount:
    asterisks += first_amount - second_amount
  else:
    asterisks = -1
    break

if asterisks == second_string.count ("*"):
  print ("A")
else:
  print ("N")
