def get_postfix (prefix):
    stack = []
    operators = ['+', '-', '*', '/']
    
    for i in prefix [::-1]:
        if i.isdigit ():
            stack.append (i)
        elif i in operators:
            x = stack.pop ()
            y = stack.pop ()
            expression = x + " " + y + " " + i
            stack.append (expression)
    return " ".join (stack)
    
while True:
    prefix = input ()
    if prefix == "0":
        break
    print (get_postfix (prefix.split ()))
