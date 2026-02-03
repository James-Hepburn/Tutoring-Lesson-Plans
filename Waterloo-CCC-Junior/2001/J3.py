def get_points (suit):
  values = {"A":4, "K":3, "Q":2, "J":1, 0:3, 1:2, 2:1}
  points = 0
  for i in suit:
    if i in values:
      points += values[i]
  if len (suit) in values:
    points += values[len (suit)]
  return points 

cards = input()

c = list (cards [cards.index("C") + 1: cards.index("D")])
d = list (cards [cards.index("D") + 1: cards.index("H")])
h = list (cards [cards.index("H") + 1: cards.index("S")])
s = list (cards [cards.index("S") + 1: ])

c_points = get_points (c)
d_points = get_points (d)
h_points = get_points (h)
s_points = get_points (s)
total = c_points + d_points + h_points + s_points

print ("Cards Dealt Points")
print ("Clubs " + " ".join (c) + " " + str (c_points))
print ("Diamonds " + " ".join (d) + " " + str (d_points))
print ("Hearts " + " ".join (h) + " " + str (h_points))
print ("Spades " + " ".join (s) + " " + str (s_points))
print ("Total " + str (total))
