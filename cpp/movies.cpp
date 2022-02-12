/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science I
 * Date: January 28, 2019
 * Program Description:
 * 	Program allows for movie ticket charges to be calculated and displayed 
 * 	to the user given the quantity of adult and children tickets sold. 
 * 	The program also calculates the amount provided to the distributor given
 * 	the global constant value stored as DISTRIBUTOR_PERCENTAGE. 


#include <iostream>
#include <iomanip>
#include <cmath>

// Declaring Global Constant Values
const double ADULT_TICKET = 7.50;
const double CHILDREN_TICKET = 4.75;
const double DISTRIBUTOR_PERCENTAGE = 0.80;

using namespace std;
int main ()
{
	// Variable Declarations
	
	char movie[30];
	int numAdult = 0, numChildren = 0;
	double grossRev = 0, distributorAmt = 0, netProfit = 0, 
		adultEarnings=0, childrenEarnings=0;
	
	// Collecting inputs for move name and numbers of tickets sold.
	
	cout << "What is the name of the movie? ";
	cin.getline (movie, 30);
	
	cout << "How many adult tickets sold? ";
	cin >> numAdult;
	
	cout << "How many children tickets sold? ";
	cin >> numChildren;
	
	// Adding an extra space for readability. 
	cout << endl;
	

	// Calculations
	
	adultEarnings = numAdult * ADULT_TICKET;
	childrenEarnings = numChildren * CHILDREN_TICKET;
	grossRev = adultEarnings + childrenEarnings;
	distributorAmt = grossRev * DISTRIBUTOR_PERCENTAGE;
	netProfit = grossRev - distributorAmt;
	
	// Outputs 
	cout << "Movie Name: " << movie << endl;
	cout << setprecision (2) << fixed;
	cout << "Gross Box Office Revenue: " << "$" << setw(8) << grossRev << endl;
	cout << "Distributor Amount:       " << "$" << setw(8) << distributorAmt << endl;
	cout << "Net Profit:               " << "$" << setw(8) << netProfit << endl;
	
	
	return 0;
}
