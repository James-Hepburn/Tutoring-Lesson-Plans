# ccc senior s2 2010 - https://dmoj.ca/problem/ccc10s2

k = int (input ())
tree = {}

for _ in range (k):
  value = input ().split ()
  tree [value [1]] = value [0]

huffman = input ()

equivalent = ""
extender = 0
i = 0

while i < len (huffman):
  if huffman [i : i + extender] in tree:
    equivalent += tree [huffman [i : i + extender]]
    i = i + extender
    extender = 0
  else:
    extender += 1

print (equivalent)
