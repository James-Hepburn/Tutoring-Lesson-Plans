# ccc senior s2 2007 - https://dmoj.ca/problem/ccc07s2

n = int (input ())
boxes = [[int (i) for i in input ().split ()] for _ in range (n)]
m = int (input ())
packages = [[int (i) for i in input ().split ()] for _ in range (m)]

for i in packages:
  sizes = [
    [i [0], i [1], i [2]], 
    [i [0], i [2], i [1]],
    [i [1], i [0], i [2]],
    [i [1], i [2], i [0]],
    [i [2], i [0], i [1]],
    [i [2], i [1], i [0]]
  ]
  volume = 100000
  for j in sizes:
    for k in boxes:
      if j [0] <= k [0] and j [1] <= k [1] and j [2] <= k [2]:
        volume = min (volume, k [0] * k [1] * k [2])
  if volume == 100000:
    print ("Item does not fit.")
  else:
    print (volume)
