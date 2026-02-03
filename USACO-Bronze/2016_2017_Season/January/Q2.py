# USACO 2017 January - Bronze Level - Problem 2. Hoof, Paper, Scissors - http://www.usaco.org/index.php?page=viewproblem2&cpid=688

n = int (input ())
games = [[int (i) for i in input ().split ()] for _ in range (n)]
    
def count_wins (meaning):
  win_1 = ["hoof", "scissors"]
  win_2 = ["scissors", "paper"]
  win_3 = ["paper", "hoof"]
  count = 0
  for i in games:
    moves = [meaning [i [0]], meaning [i [1]]]
    if moves in [win_1, win_2, win_3]:
      count += 1
  return count

meaning_1 = {1:"hoof", 2:"paper", 3:"scissors"}
meaning_2 = {1:"hoof", 2:"scissors", 3:"paper"}
meaning_3 = {1:"paper", 2:"hoof", 3:"scissors"}
meaning_4 = {1:"paper", 2:"scissors", 3:"hoof"}
meaning_5 = {1:"scissors", 2:"hoof", 3:"paper"}
meaning_6 = {1:"scissors", 2:"paper", 3:"hoof"}

win_1 = count_wins (meaning_1)
win_2 = count_wins (meaning_2)
win_3 = count_wins (meaning_3)
win_4 = count_wins (meaning_4)
win_5 = count_wins (meaning_5)
win_6 = count_wins (meaning_6)

all_wins = [win_1, win_2, win_3, win_4, win_5, win_6]
result = max (all_wins)

print (result)
