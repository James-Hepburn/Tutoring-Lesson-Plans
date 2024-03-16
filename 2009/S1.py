# ccc senior s1 2009 - https://dmoj.ca/problem/ccc09s1

a = int (input ())
b = int (input ())

cube_root = int (a ** (1/3))
cube = cube_root ** 3
count = 0

while cube <= b:
    if cube >= a:
        square_root = int (cube ** (1/2))
        square = square_root ** 2
        if square == cube:
            count += 1
    cube_root += 1
    cube = cube_root ** 3

print (count)
