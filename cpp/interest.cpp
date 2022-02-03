/*		
 *	Name: Taylor Moore
 *	Program Type: Course Assignment - Computer Science I
 *	Date: January 22, 2019
 *	Program Description: 
 *		Program prompts a user to input investment information and provides
 *		output of the future investment value and total interest earned.
 *			
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
	// Variable Declarations
	double money=0, rate=0, years=0, periods=0,
	       futureVal=0, interestEarned=0;
	
	double temp1 = 0, temp2 = 0;

	// User Input 
	cout << "How much money did you invest?  $";
	cin >> money;
	
	cout << "What is the annual interest rate? %";
	cin >> rate;
	
	cout << "How many years are you investing for? ";
	cin >> years;
	
	cout << "How many periods are you investing it for? ";
	cin >> periods;
	
	// Calculations of Interest and Future Value 
	rate = rate / 100;
	temp1 = (1 + ( rate / periods ));
	temp2 = periods * years;
	futureVal = money * pow(temp1,temp2);
	interestEarned = futureVal - money;


	// Program Outputs
	cout << "Future Value is: $" << setprecision(2) << fixed << futureVal << endl;
	cout << "Interest Earned is: $" << interestEarned << endl;
	
	return 0;
}
