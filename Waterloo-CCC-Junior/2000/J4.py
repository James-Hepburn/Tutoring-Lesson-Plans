n = int (input())

streams = []
for i in range (n):
  streams.append (int(input()))
                  
while True:
  split_join = int (input())
  if split_join == 77:
    break
  elif split_join == 99:
    stream_number = int (input())
    percentage = int (input())
    current_stream = streams[stream_number - 1]
    left = current_stream * (percentage / 100)
    right = current_stream - left
    streams[stream_number - 1] = left
    streams.insert (stream_number, right)
  elif split_join == 88:
    stream_number = int (input())
    if stream_number != len (streams):
      streams[stream_number - 1] += streams[stream_number]
      del streams[stream_number]

str_streams = [str(i) for i in streams]      
print (" ".join (str_streams))      
      
