def get_links (line):
  counter = 0
  links = []
  link = ""
  for i in range (len (line)):
    if counter == 6 and line[i] == '"':
      links.append (link)
      counter = 0
      link = ""
    elif counter == 6:
      link += line[i]
    elif counter != 0:
      counter += 1
    elif i > len (line) - 6:
        break
    elif line[i:i+6] == 'HREF="':
      counter = 1
    else:
      counter = 0
  return links

def bfs (links, start, target):
  queue = [start]
  visited = [start]
  while len (queue) != 0:
    current = queue.pop (0)
    if current == target:
      return True
    elif current in links:
      for i in links [current]:
        if i not in visited:
          queue.append (i)
          visited.append (i)
  return False

n = int (input ())

links = {}

for i in range (n):
  from_link = input ()
  while True:
    line = input ()
    if line == "</HTML>":
      break
    elif "HREF=" in line:
      found_links = get_links (line)
      if from_link in links:
        links [from_link] += found_links
      else:
        links [from_link] = found_links

for i in links:
  for j in links [i]:
    print ("Link from", i, "to", j)

while True:
  from_link = input ()
  if from_link == "The End":
    break
  to_link = input ()
  if bfs (links, from_link, to_link):
    print ("Can surf from", from_link, "to", to_link + ".")
  else:
    print ("Can't surf from", from_link, "to", to_link + ".")
