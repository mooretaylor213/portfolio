/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science I
 * Date: Februaru 5, 2019
 * Program Description: 
 * 	Program processes user input of pay rates and hours worked.
*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Declaring Global Constant
const double REGULAR_HOURS = 8.0;
const int NAME_SIZE = 20;

int main ()
{
	// Variable Declarations
	int hoursWorked=0, regHours=0, doubleHours=0, tripleHours=0;
	double hourlyRate=0, regPay=0, doublePay=0, triplePay=0, totalPay=0;
	char name[NAME_SIZE];
	

	// User Input
	cout << "What is the employee's name? ";
	cin.getline (name, NAME_SIZE);
	
	cout << "What is the hourly rate the employee is paid (USD)? ";
	cin >> hourlyRate;
	
	cout << "How many hours did the employee work? ";
	cin >> hoursWorked;
	
	// Adding Extra Space for Readability
	cout << endl; 
	

	// Pay Calculations
	if (hoursWorked > 0 && hoursWorked <= 8)
	{
		regPay = hoursWorked * hourlyRate;
		totalPay = regPay;
		cout << "Regular Pay: " << "$" << setprecision(2) << fixed << regPay << endl;
		cout << "Total Pay:   " << "$" << setprecision(2) << fixed << totalPay << endl;
	}
	else
		if (hoursWorked > 8 && hoursWorked <= 16)
		{
		doubleHours = hoursWorked - REGULAR_HOURS;
		regPay = REGULAR_HOURS * hourlyRate;
		doublePay = hourlyRate * doubleHours * 2.00;
		totalPay = regPay + doublePay;
		cout << "Regular Pay: " << "$" << setprecision(2) << fixed << setw(4) << regPay << endl;
		cout << "Double Pay:  " << "$" << setprecision(2) << fixed << setw(4) << doublePay << endl;
		cout << "Total Pay:   " << "$" << setprecision(2) << fixed << setw(4) << totalPay << endl;
		}
	else 
	{
		tripleHours = hoursWorked - 16;
		triplePay = tripleHours * hourlyRate * 3.00;
		doublePay = hourlyRate * REGULAR_HOURS * 2.00;
		regPay = REGULAR_HOURS * hourlyRate;
		totalPay = regPay + doublePay + triplePay;
		cout << "Regular Pay:  " << "$" << setprecision(2) << fixed << setw(4) << regPay << endl;
		cout << "Double  Pay:  " << "$" << setprecision(2) << fixed << setw(4) << doublePay << endl;
		cout << "Triple  Pay:  " << "$" << setprecision(2) << fixed << setw(4) << triplePay << endl;
		cout << "Total Pay:    " << "$" << setprecision(2) << fixed << setw(4) << totalPay << endl;
	}

	return 0;	
}
