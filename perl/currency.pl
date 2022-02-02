#!/usr/bin/perl

# Name: Taylor Moore
# Program Type: Course Assignment - Programming Languages
# Date: 7 February 2021
# Program Description: 
# 	This is a perl program that reads user input of US Dollars
#	and converts the amount to the appropriate amount in the 
#	chosen currency. These conversions are accurate according to 
#	conversion rates found on Google on 2/7/21. These rates may
#	need to be changed in order to be accurate for any time after
#	2/7/21.

do{
# User Input
   print "\nConvert your U.S. Dollars to Foreign Currency\n\n";
   print "How many U.S. Dollars do you want to exchange? ";
   $amount = <STDIN>;
   chomp($amount);
   print "Enter P (British Pounds), E (Euros), M (Mexican Pesos), or C (Canadian): ";
   $currency = <STDIN>;
   chomp($currency);

# Checking for correct inputs, then allows for the appropriate calculations.
 
   if ($currency eq "P" | $currency eq "E" | $currency eq "M" | $currency eq "C")
   {
  	 if ($currency eq "P")
  	 {
  	 $pounds = ($amount * 0.65);
  	 printf "Your converted amount is %.2f",$pounds;
  	 print " Pounds\n";
   	 }
  	 if ($currency eq "E")
   	 {
   	 $euros = ($amount * 0.83);
   	 printf "Your converted amount is %.2f",$euros;
   	 print " Euros\n";
   	 }
  	 if ($currency eq "M")
   	 {
   	 $pesos = ($amount * 20.12);
   	 printf "Your converted amount is %.2f",$pesos;
    	 print " Pesos\n";
   	 }
   	 if ($currency eq "C")
   	 {
   	 $canadian = ($amount * 1.28);
   	 printf "Your converted amount is %.2f",$canadian;
   	 print " Canadian Dollars\n";
   	}
    }
    else
        {
	 print "You have entered an invalid choice.\n"
        }
  
# User input for if they want to convert again. 
   print "\nDo you want to exchange again (yes/no)? ";
   $reply = <STDIN>;
   chomp($reply);

# Prints thank you message then program ends.
   if ($reply eq "no")
   {
   print "\nThank you for your business\n"
   }

   }while($reply eq "yes");

