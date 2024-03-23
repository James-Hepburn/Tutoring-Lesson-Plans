# ccc senior s2 2023 - https://dmoj.ca/problem/ccc23s2

def get_asymmetric (heights, start_index, end_index):
  if end_index >= len (heights):
    return 100000000
  total = 0
  i = start_index
  j = end_index
  while i <= j:
    total += abs (heights [i] - heights [j])
    i += 1
    j -= 1
  return total   

n = int (input ())
heights = [int (i) for i in input ().split ()]

asymmetric_values = []

for i in range (1, n + 1):
  current_values = []
  for j in range (n):
    current_values.append (get_asymmetric (heights, j, j + i))
  asymmetric_values.append (str (min (current_values)))

asymmetric_values.insert (0, "0")
asymmetric_values.pop (-1)

print (" ".join (asymmetric_values))
