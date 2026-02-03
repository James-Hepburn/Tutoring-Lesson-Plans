# ccc senior s3 2005 - https://dmoj.ca/problem/ccc05s3

def tensor_product (a, b):
  product = []

  for i in range (len (a)):
    for j in range (len (b)):
      row = []

      for k in range (len (a [0])):
        for l in range (len (b [0])):
          row.append (a [i][k] * b [j][l])

      product.append (row)

  return product

n = int (input ())

matrices = []

for _ in range (n):
  r, c = [int (i) for i in input ().split ()]
  matrix = [[int (i) for i in input ().split ()] for _ in range (r)]
  matrices.append (matrix)

a = matrices [0]
b = matrices [1]
product = tensor_product (a, b)
index = 2

while index < n:
  a = product
  b = matrices [index]
  product = tensor_product (a, b)
  index += 1

maximum_element = product [0][0]
minimum_element = product [0][0]
maximum_row_sum = - float ("inf")
minimum_row_sum = float ("inf")
maximum_column_sum = - float ("inf")
minimum_column_sum = float ("inf")

for i in range (len (product)):
  row_sum = sum (product [i])
  max_row = max (product [i])
  min_row = min (product [i])
  maximum_row_sum = max (maximum_row_sum, row_sum)
  minimum_row_sum = min (minimum_row_sum, row_sum)
  maximum_element = max (maximum_element, max_row)
  minimum_element = min (minimum_element, min_row)

for i in range (len (product [0])):
  column_sum = 0
  for j in range (len (product)):
    column_sum += product [j][i]
  maximum_column_sum = max (maximum_column_sum, column_sum)
  minimum_column_sum = min (minimum_column_sum, column_sum)

print (maximum_element)
print (minimum_element)
print (maximum_row_sum)
print (minimum_row_sum)
print (maximum_column_sum)
print (minimum_column_sum)
