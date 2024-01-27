# ccc senior s1 2008 - https://dmoj.ca/problem/ccc08s1

coldest_city = ""
coldest_temperature = 201

while True:
  city_information = input ().split ()
  if int (city_information [1]) < coldest_temperature:
    coldest_city = city_information [0]
    coldest_temperature = int (city_information [1])
  if city_information [0] == "Waterloo":
    print (coldest_city)
    break
