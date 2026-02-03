# ccc senior s2 2014 - https://dmoj.ca/problem/ccc14s2

n = int (input())
students_a = input().split()
students_b = input().split()
bad = False

for i in range (len (students_a)):
  a = students_a [i]
  b = students_b [i]
  a_in_b_index = students_b.index (a)
  partner = students_a [a_in_b_index]
  if partner != b or a == b:
    bad = True
    break

if bad:
  print ("bad")
else:
  print ("good")
