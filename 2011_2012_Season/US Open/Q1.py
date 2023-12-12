# http://www.usaco.org/index.php?page=viewproblem2&cpid=130

def remove_breed (breeds, id):
  new_breeds = breeds.copy ()
  while new_breeds.count (id) > 0:
    new_breeds.remove (id)
  return new_breeds

def count_consecutive (breeds):
  answer = 0
  count = 0
  for i in range (len (breeds) - 1):
    if breeds[i] == breeds[i+1]:
      count += 1
    else:
      answer = max (answer, count)
      count = 1
  return answer
      
n = int (input ())
breeds = [int (input ()) for _ in range (n)]

answer = 0

for i in breeds:
  new_breeds = remove_breed (breeds, i)
  consecutive = count_consecutive (new_breeds)
  answer = max (answer, consecutive)

print (answer)
