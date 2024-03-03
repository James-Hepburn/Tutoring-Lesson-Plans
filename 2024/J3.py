n = int (input ())
scores = [int (input ()) for _ in range (n)]

unique_scores = sorted (list (set (scores)))

value = unique_scores [-3]
amount = scores.count (unique_scores [-3])

print (value, amount)
