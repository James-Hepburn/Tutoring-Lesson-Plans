H = int (input())

for i in range (H):
  if i < H / 2:
    print ("*" * (2 * i + 1) + " " * (2 * (H - 2 * i) - 2) + "*" * (2 * i + 1))
  elif i > H / 2 and i != 1 + H // 2 :
    print ("*" * (2 * (H - i) + 1) + " " * (2 * (H - 2 * (H - i)) - 2) + "*" * (2 * (H - i) + 1))

print ("*" + " " * (2 * H - 2) + "*")
  
