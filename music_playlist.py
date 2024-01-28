import random, time, os

def read_file (file_name):
  file = open (file_name, "r")
  lines = []
  for i in file:
    i = i.strip ()
    lines.append (i)
  file.close ()
  return lines

def rewrite_file (lines, file_name):
  file = open (file_name, "w")
  for i in lines:
    file.write (i + "\n")
  file.close ()

def shuffle (lines):
  for _ in range (50):
    index1 = random.randint (0, len (lines) - 1)
    index2 = random.randint (0, len (lines) - 1)
    lines [index1], lines [index2] = lines [index2], lines [index1]
  return lines

def split_dictionary (lines):
  dict = {}
  for i in lines:
    info = i.split (" - ")
    dict [info [0]] = info [1]
  return dict

def join_dictionary (dict):
  lines = []
  for i in dict:
    lines.append (i + " - " + dict [i])
  return lines

def sort_songs (lines):
  lines = dict (sorted (lines.items ()))
  return lines

def sort_artists (lines):
  lines = dict (sorted (lines.items (), key = lambda x : x [1]))
  return lines

file_name = input ("Playlist name? ")
file_name = "-".join (file_name.split (" ")) + ".txt"

file = open (file_name, "w")
file.close ()

os.system ("clear")

while True:
  print ("Music Playlist!\n")
  
  print ("(1) Add a song")
  print ("(2) Delete a song")
  print ("(3) View all songs")
  print ("(4) Search playlist")
  print ("(5) Shuffle playlist")
  print ("(6) Sort alphabetically by song")
  print ("(7) Sort alphabetically by artist")
  print ("(8) Exit playlist")
  
  option = int (input ("\nOption? "))
  print ()
  
  if option == 1:
    song = input ("Song? ").lower ()
    artist = input ("Artist? ").lower ()
    line = song + " - " + artist
    lines = read_file (file_name)
    lines.append (line)
    rewrite_file (lines, file_name)
  
  elif option == 2:
    song = input ("Song? ").lower ()
    artist = input ("Artist? ").lower ()
    line = song + " - " + artist
    lines = read_file (file_name)
    if line in lines:
      lines.remove (line)
      rewrite_file (lines, file_name)
  
  elif option == 3:
    lines = read_file (file_name)
    for i in range (len (lines)):
      print (str (i + 1) + ") " + lines [i])
  
  elif option == 4:
    song = input ("Song? ").lower ()
    artist = input ("Artist? ").lower ()
    line = song + " - " + artist
    lines = read_file (file_name)
    if line in lines:
      print ("\n" + line + " does exist.")
    else:
      print ("\n" + line + " does not exist.")
      
  elif option == 5:
    lines = read_file (file_name)
    lines = shuffle (lines)
    rewrite_file (lines, file_name)

  elif option == 6:
    lines = read_file (file_name)
    lines = split_dictionary (lines)
    lines = sort_songs (lines)
    lines = join_dictionary (lines)
    rewrite_file (lines, file_name)

  elif option == 7:
    lines = read_file (file_name)
    lines = split_dictionary (lines)
    lines = sort_artists (lines)
    lines = join_dictionary (lines)
    rewrite_file (lines, file_name)
  
  elif option == 8:
    print ("Goodbye.")
    break
  
  else:
    print ("Invalid option.")

  time.sleep (2)
  os.system ("clear")
