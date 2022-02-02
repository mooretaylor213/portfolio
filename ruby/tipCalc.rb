#!/usr/local/bin/ruby

# Name: Taylor Moore
# Program Type: Course Assignment
# Date: 7 March 2021
# Program Description: 
#     This program has the user enter the price of their meal.
#     The program then calculates and prints the tips and totals after
#     tips for 3 different common tip percentages.


response = 'Y'
while response == 'Y'
print ("Enter the price of your meal: $")
price = gets.to_f

if price < 0.01
  puts "Cannot have a negative price, try again."
  break
end

tip10 = price * 0.10
total10 = price + tip10

tip15 = price * 0.15
total15 = price + tip15

tip20 = price * 0.20
total20 = price + tip20

print ("10% Tip: $")
printf("%.2f",(tip10))
printf "\n"
print "15% Tip: $"
printf("%.2f",(tip15))
printf "\n"
print "20% Tip: $"
printf("%.2f",(tip20))
printf "\n"

print "Total for 10% Tip: $"
printf("%.2f",(total10))
printf "\n"
print "Total for 15% Tip: $"
printf("%.2f",(total15))
printf "\n"
print "Total for 20% Tip: $"
printf("%.2f",(total20))
printf"\n"

print ("Would you like to continue? (Y/N) ")
response=gets.chomp

if response=='N'
  puts "Have a nice day\n"
  break


