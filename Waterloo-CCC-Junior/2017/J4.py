D = int(input())

arithmetic_sequences = [34, 111, 123, 135, 147, 159, 210, 222, 234, 246, 258, 321, 333, 345, 357, 420, 432, 444, 456, 531, 543, 555, 630, 642, 654, 741, 753, 840, 852, 951, 1111]

half_days = D // 720
remaining_hours = (D - (half_days * 720)) // 60
remaining_minutes = D - (remaining_hours * 60) - (half_days * 720)
time = remaining_minutes + (remaining_hours * 100)

answer = half_days * len (arithmetic_sequences)

for i in arithmetic_sequences:
  if time >= i:
    answer += 1

print (answer)
