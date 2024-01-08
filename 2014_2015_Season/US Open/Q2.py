# USACO 2015 US Open - Bronze Level - Problem 2. Bessie Gets Even - http://www.usaco.org/index.php?page=viewproblem2&cpid=546

n = int (input ())
letters = {}

for _ in range (n):
  info = input ().split ()
  if info [0] in letters:
    letters [info [0]].append (int (info [1]))
  else:
    letters [info [0]] = [int (info [1])]

count = 0

for b in letters ["B"]:
  for e in letters ["E"]:
    for s in letters ["S"]:
      for i in letters ["I"]:
        for g in letters ["G"]:
          for o in letters ["O"]:
            for m in letters ["M"]:
              result = (b + e + s + s + i + e) * (g + o + e + s) * (m + o + o)
              if result % 2 == 0:
                count += 1

print (count)
