# http://www.usaco.org/index.php?page=viewproblem2&cpid=187

grass = input ()

count = 0

for i in range (len (grass) - 1):
  if grass[i] == grass[i+1] == "(":
    for j in range (i + 1, len (grass) - 1):
      if grass[j] == grass[j+1] == ")":
        count += 1

print (count)
