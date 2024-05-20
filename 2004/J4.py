keyword = input ()
message = input ()

output = ""
new_message = ""

for i in message:
    if i.isalpha ():
        new_message += i

for i in range (len (new_message)):
    if new_message [i].isalpha ():
        index = i % len (keyword)
        amount = ord (keyword [index]) - ord ("A")
        result = ord (new_message [i]) + amount
        if result > ord ("Z"):
            result = ord ("A") + (result - ord ("Z") - 1)
        output += chr (result)
        
print (output)
