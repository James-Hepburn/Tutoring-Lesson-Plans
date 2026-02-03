instructions = input ()
chords = amount = sign = ""
dict = {"+":"tighten", "-":"loosen"}

for i in instructions:
  if i.isalpha():
    if sign != "":
      print (chords, dict[sign], amount)
      amount = chords = sign = ""
    chords += i
  elif i.isdigit():
    amount += i
  else:
    sign = i
print (chords, dict[sign], amount)
