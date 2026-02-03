# http://www.usaco.org/index.php?page=viewproblem2&cpid=103

n, b = [int (i) for i in input ().split ()]
items = [[int (i) for i in input ().split ()] for _ in range (n)]

items.sort (key = lambda x : x[0])

total = 0
count = 0
index = 0

while total < b and index < n:
  discount = (items[index][0]) // 2 + items[index][1]
  cost = items[index][0] + items[index][1]
  index += 1
  if total + cost <= b:
    total += cost
    count += 1
  elif total + discount <= b:
    total += discount
    count += 1

print (count)
