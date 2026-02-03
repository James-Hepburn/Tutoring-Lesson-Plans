ottawa = int(input())

victoria = (ottawa - 300) % 2400
edmonton = (ottawa - 200) % 2400
winnipeg = (ottawa - 100) % 2400
halifax = (ottawa + 100) % 2400
st_john = (ottawa + 130) % 2400

last_2_digits = int (str (st_john)[-2:])
if last_2_digits >= 60:
  hours = st_john // 100
  minutes = st_john % 100
  hours += minutes // 60
  minutes = minutes % 60
  st_john = int (str (hours) + str (minutes))

print(ottawa, "in Ottawa")
print(victoria, "in Victoria")
print(edmonton, "in Edmonton")
print(winnipeg, "in Winnipeg")
print(ottawa, "in Toronto")
print(halifax, "in Halifax")
print(st_john, "in St. John's")
