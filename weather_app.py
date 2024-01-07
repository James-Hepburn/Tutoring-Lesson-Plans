import requests

print ("Welcome to the Weather App!\n")

location = input ("Which location would you like to select? ")

link = "http://api.weatherapi.com/v1/current.json?key=896373c9f2bb491aae0153243240701&q=" + location
response = requests.get (link)
data = response.json ()

location = data ["location"]
name = location ["name"]
region = location ["region"]
country = location ["country"]

temperature = data ["current"]
celsius = temperature ["temp_c"]
fahrenheit = temperature ["temp_f"]

print ("\n" + name, "-", region, "-", country)
print ("Temperature in celsius:", celsius)
print ("Temperature in fahrenheit:", fahrenheit)
