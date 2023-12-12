# http://www.usaco.org/index.php?page=viewproblem2&cpid=121

binary = input ()

decimal = int (binary, 2)
decimal *= 17

print ("{0:b}".format (decimal))
