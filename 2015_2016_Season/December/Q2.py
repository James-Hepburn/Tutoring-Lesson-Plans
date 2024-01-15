# USACO 2015 December - Bronze Level - Problem 2. Speeding Ticket - http://www.usaco.org/index.php?page=viewproblem2&cpid=568

n, m = [int (i) for i in input ().split ()]

current_length = 1
n_information = []

for _ in range (n):
  new_length, speed_limit = [int (i) for i in input ().split ()]
  n_information.append ([[current_length, new_length + current_length - 1], speed_limit])
  current_length += new_length

current_length = 1
m_information = []

for _ in range (m):
  new_length, speed = [int (i) for i in input ().split ()]
  m_information.append ([[current_length, new_length + current_length - 1], speed])
  current_length += new_length

def check_limit (length, speed):
  for i in n_information:
    start = i [0][0]
    end = i [0][1]
    limit = i [1]
    if start <= length <= end:
      return speed - limit

over_limit = 0

for i in m_information:
  start = i [0][0]
  end = i [0][1]
  speed = i [1]
  result_start = check_limit (start, speed)
  result_end = check_limit (end, speed)
  over_limit = max (over_limit, result_start)
  over_limit = max (over_limit, result_end)

print (over_limit)
