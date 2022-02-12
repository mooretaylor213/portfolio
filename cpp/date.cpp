/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science I
 * Date: February 11, 2019 at 11:59pm
 * Program Description:
 * 	Program accepts user input of an ISO 8601 formatted date.
 * 	An ISO 8601 date follows the format YYYYMMDD.
 * 	The date value is read in as an integer and is manipulated
 * 	to be broken into the date format MM/DD/YYYY. 
 *
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main ()
{
	int date=0, year=0, month=0, day=0;
	
	cout << "Input ISO formatted date (YYYYMMDD): ";
	cin >> date; 

	// Checking for invalid input length.
	if (date <= 9999999 || date >= 100000000)
		cout << "Invalid Length" << endl;	
	else
	{	
	
	// Date Calculations
	
	year = date / 10000;
	date = date % 10000;
	month = date / 100;
	date = date % 100;
	day = date / 1;

	// Checking for Invalid Inputs 
	
	if (year < 999 || year >= 10000)
		cout << "Invalid Year";

	if (month > 12 || month <= 0)
		cout << "Invalid Month" << endl;
	
	if (day <= 0 || day > 31)
	 	cout << "Invalid Day" << endl;
	
	// Outputting the US Formatted Date Using Variables from Calculation.
	
	else
	cout << "New Date Format: " << month << "/" << day << "/" << year << endl;
   	}

	return 0;
}
