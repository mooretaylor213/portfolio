/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science II
 * Date: November 7, 2019
 * Program Description:
 * 	This is the driver file, which contains the function calls
	that work with the functions in the implementation file.
	This program takes in user input and uses a dynamic array 
	that stores the strings. A pointer is used to locate the information
	for insertion and deletion (pushing and popping) from the stack.
*/


// MAIN DRIVER

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	int response=0;
	string pushResponse, popResponse;
	
	StackNode s(5);
	do
	{
		cout << "MENU: " << endl;
		cout << "1. Push an item onto a stack" << endl;
		cout << "2. Pop an item from stack" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> response;
		if (response==1)
		{
			cout << "Insert what you want to push (a string): ";
			cin >> pushResponse;
			s.push (pushResponse);
		}
		if (response==2)
		{
			popResponse=s.pop();
			cout << popResponse << " has been popped off the stack." << endl;
		}
	}while(response != 3);
	
	
	return 0;
}

