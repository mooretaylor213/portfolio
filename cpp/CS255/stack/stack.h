/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science II
 * Date: November 7, 2019
 * Program Description: 
 * 	This is the header file. It contains public and private information.
 * 	The information contains the types of data stored and dealt with 
 * 	throughout the program. 
*/


#include <iostream>

using namespace std;

class StackNode
{
	private:
		int maxStack; 
		int top;
		string *stackPtr;
	public:
		StackNode (int);
        	~StackNode();
        	void push(string);
        	string pop();
       	 	bool empty()const;
        	bool full()const;
};
