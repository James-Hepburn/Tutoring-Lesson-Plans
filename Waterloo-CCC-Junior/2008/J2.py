playlist = ["A", "B", "C", "D", "E"]

while True:
  b = int (input())
  n = int (input())
  if b == 4:
    print (" ".join (playlist))
    break
  else:
    for i in range (n):
      if b == 1:
        first = playlist[0]
        playlist.remove (first)
        playlist.append (first)
      elif b == 2:
        last = playlist[4]
        playlist.remove (last)
        playlist.insert (0, last)
      elif b == 3:
        temp = playlist[0]
        playlist[0] = playlist[1]
        playlist[1] = temp
        
