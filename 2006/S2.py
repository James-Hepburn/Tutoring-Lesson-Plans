# ccc senior s2 2006 - https://dmoj.ca/problem/ccc06s2

def get_missing_letter (text):
  for i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ ":
    if i not in text:
      return i

plaintext = input ()
ciphertext = input ()
message = input ()

cipher = {}
for i in range (len (plaintext)):
  if ciphertext [i] not in cipher:
    cipher [ciphertext [i]] = plaintext [i]

if len (cipher) == 26:
  cipher [get_missing_letter (ciphertext)] = get_missing_letter (plaintext)

result = ""
for i in message:
  if i in cipher:
    result += cipher [i]
  else:
    result += "."

print (result)
