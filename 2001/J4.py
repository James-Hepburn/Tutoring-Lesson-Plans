start = int (input ())
end = int (input ())

grid = [["" for _ in range (50)] for _ in range (50)]
row = 25
column = 25
amount = 0
counter = start

while counter <= end:
    amount += 1
    
    for _ in range (amount):
        if counter > end:
            break
        grid [row][column] = str (counter)
        counter += 1
        row += 1
        
    for _ in range (amount):
        if counter > end:
            break
        grid [row][column] = str (counter)
        counter += 1
        column += 3
        
    amount += 1
    
    for _ in range (amount):
        if counter > end:
            break
        grid [row][column] = str (counter)
        counter += 1
        row -= 1
        
    for _ in range (amount):
        if counter > end:
            break
        grid [row][column] = str (counter)
        counter += 1
        column -= 3
        

for i in grid:
    print (" ".join (i))
