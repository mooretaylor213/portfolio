#!/usr/local/bin/ruby

# Name: Taylor Moore 
# Program Type: Course Assignment - Programming Languages
# Date: March 8, 2021
# Program Description: 
#     This program takes user input for a specified number of players. It then uses
#     persistent objects to read/write all players' info into a file using pstore. This
#     can be useful for anyone that wants to keep up with a specific number of 
#     players in any game and it also keeps a few fun facts about the players. 
#            
#     The scores of any type of game can be inputted, and the name/age/favorite 
#     color is kept to distinguish between players. The date can be found on top
#     of the player's block of information just to keep a record in the event that
#     the same "playerFile" is used regularly over a span of different dates.

require 'pstore'

print "How many players? "
numPlayers = gets.to_i

class Player
  attr_accessor :date,:name, :color, :age, :score;
end

for i in 1..numPlayers 
  player = Player.new
  print "Enter today's date (MM/DD/YYYY): "
  dateIn=gets.chomp
  player.date=dateIn
  print "Enter player ##{i}'s first name: "
  nameIn=gets.chomp
  player.name=nameIn
  print "Enter player ##{i}'s favorite color: "
  favColor=gets.chomp
  player.color=favColor
  print "Enter player ##{i}'s age: "
  inAge=gets.to_i
  player.age=inAge
  print "Enter player ##{i}'s score: "
  scoreEntered=gets.to_i
  player.score=scoreEntered
  puts   
  # Writing each player into "playerFile"
  store = PStore.new("playerFile")
  store.transaction do
    store[:playerInfo] ||=Array.new
    store[:playerInfo] << player
  end
end

# Reading the file that was written into, displaying contents.
people = []
  store.transaction do
    people=store[:playerInfo]
  end
 people.each do |person|
   puts "Today's Date: #{person.date.chomp}"
   puts "Name: #{person.name.chomp}"
   puts "Favorite Color: #{person.color.chomp}"
   puts "Age: #{person.age}"
   puts "Score: #{person.score}"
   puts 
end

