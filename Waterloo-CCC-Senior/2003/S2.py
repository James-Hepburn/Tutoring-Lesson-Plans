# ccc senior s2 2003 - https://dmoj.ca/problem/ccc03s2

def get_syllable (word):
  word = word.lower()
  index = 0
  for i in range (len (word)):
    if word[i] in "aeiou":
      index = i
  return word[index:]
      
def identify_poem ():
  line1 = get_syllable (input().split()[-1])
  line2 = get_syllable (input().split()[-1])
  line3 = get_syllable (input().split()[-1])
  line4 = get_syllable (input().split()[-1])
  if line1 == line2 == line3 == line4:
    return "perfect"
  elif line1 == line2 and line3 == line4:
    return "even"
  elif line1 == line3 and line2 == line4:
    return "cross"
  elif line1 == line4 and line2 == line3:
    return "shell"
  return "free"

N = int (input())

for i in range (N):
  print (identify_poem ())
