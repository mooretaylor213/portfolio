#!/usr/local/bin/ruby

# Name: Taylor Moore
# Program Type: Course Assignment - Programming Languages
# Date: 7 March 2021
# Program Description:
#     This program has the user enter how many scores they would like to average.
#     Then, the user enters each score. The program takes the average of the
#     scores entered.

print "How many scores? "
number = gets.to_i

sum = 0
for i in 1..number
  print "Enter score ##{i}: "
  score = gets.to_i
  sum+=score
end

average = (sum/(number*1.0))
puts "Average is #{average.round(1)}"
