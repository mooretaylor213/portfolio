#!/usr/local/bin/ruby

# Name: Taylor Moore
# Program Type: Course Assignment - Programming Languages
# Date: 7 March 2021
# Program Description: 
#     This program has the user enter a base number and displays all possible powers
#     of the base that have a result that is less than one million.

print "What is the base? "
base = gets.to_i

power=0
result=0
million=1000000

while result<million
  result = base ** power
  if result>million
    break
  end
  puts "#{base} to the power of #{power} is #{result}\n"
  power=power+1
end

