burger = int (input())
side = int (input())
drink = int (input())
dessert = int (input())

burger_list = [461, 431, 420, 0]
side_list = [100, 57, 70, 0]
drink_list = [130, 160, 118, 0]
dessert_list = [167, 266, 75, 0]

total = burger_list[burger - 1] + side_list[side - 1] + drink_list[drink - 1] + dessert_list[dessert - 1]

print ("Your total Calorie count is " + str(total) + ".")
