daytime = int (input())
evening = int (input())
weekend = int (input())

plan_a = round ((max (daytime - 100, 0) * 0.25) + (evening * 0.15) + (weekend * 0.2), 2)
plan_b = round ((max (daytime - 250, 0) * 0.45) + (evening * 0.35) + (weekend * 0.25), 2)

if plan_a.is_integer():
  plan_a = int (plan_a)
if plan_b.is_integer():
  plan_b = int (plan_b)

print("Plan A costs {:.2f}".format(plan_a))
print("Plan B costs {:.2f}".format(plan_b))

if plan_a > plan_b:
  print ("Plan B is cheapest.")
elif plan_a < plan_b:
  print ("Plan A is cheapest.")
else:
  print ("Plan A and B are the same price.")
  
