import math

while True:
  photos = int (input())
  if photos == 0:
    break
  max_side = int (math.sqrt (photos))
  length = 1
  width = 1
  while length * width != photos:
    width += 1
    if width > max_side:
      width = 1
      length += 1
  print ("Minimum perimeter is", (width + length) * 2, "with dimensions", length, "x", width)
  
