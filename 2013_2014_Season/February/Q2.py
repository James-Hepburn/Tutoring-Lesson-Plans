# USACO 2014 February - Bronze Level - Problem 2. Auto-Complete - http://www.usaco.org/index.php?page=viewproblem2&cpid=395

def auto_complete (k, partial):
  count = 0
  for i in range (len (dictionary)):
    if partial == dictionary[i][:len(partial)]:
      count += 1
      if count == k:
        return original.index (dictionary[i]) + 1
  return -1

w, n = [int (i) for i in input ().split ()]
dictionary = [input () for _ in range (w)]

original = dictionary.copy ()
dictionary.sort ()

for _ in range (n):
  k, partial = input ().split ()
  print (auto_complete (int (k), partial))
