# you win if there is at least one way to make a losing combination
# you lose if there is no move or all possible moves lead to a winning combination

def AABDD (a, b, c, d):
  return a >= 2 and b >= 1 and d >= 2

def ABCD (a, b, c, d):
  return a >= 1 and b >= 1 and c >= 1 and d >= 1

def CCD (a, b, c, d):
  return c >= 2 and d >= 1

def BBB (a, b, c, d):
  return b >= 3

def AD (a, b, c, d):
  return a >= 1 and d >= 1

def can_move (a, b, c, d):
  return AABDD (a, b, c, d) or ABCD (a, b, c, d) or CCD (a, b, c, d) or BBB (a, b, c, d) or AD (a, b, c, d)

def winning_combination (a, b, c, d):
  if AABDD (a, b, c, d) and losing_combination (a - 2, b - 1, c, d - 2):
    return True
  elif ABCD (a, b, c, d) and losing_combination (a - 1, b - 1, c - 1, d - 1):
    return True
  elif CCD (a, b, c, d) and losing_combination (a, b, c - 2, d - 1):
    return True
  elif BBB (a, b, c, d) and losing_combination (a, b - 3, c, d):
    return True
  elif AD (a, b, c, d) and losing_combination (a - 1, b, c, d - 1):
    return True
  else:
    return False

def losing_combination (a, b, c, d):
  if not can_move (a, b, c, d):
    return True
  else:
    result = True
    if AABDD (a, b, c, d):
      result = result and winning_combination (a - 2, b - 1, c, d - 2)
    if ABCD (a, b, c, d):
      result = result and winning_combination (a - 1, b - 1, c - 1, d - 1)
    if CCD (a, b, c, d):
      result = result and winning_combination (a, b, c - 2, d - 1)
    if BBB (a, b, c, d):
      result = result and winning_combination (a, b - 3, c, d)
    if AD (a, b, c, d):
      result = result and winning_combination (a - 1, b, c, d - 1)
    return result     

n = int (input ())

for _ in range (n):
  amount = input ().split ()
  a = int (amount[0])
  b = int (amount[1])
  c = int (amount[2])
  d = int (amount[3])

  if winning_combination (a, b, c, d):
    print ("Patrick")
  else:
    print ("Roland")
