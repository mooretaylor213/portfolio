/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science II
 * Date: November 7, 2019
 * Program Description:
 * 	This portion of the program contains all of the functions 
 * 	required for the compilation and use of the assignment. 
*/

#include <iostream>
#include "stack.h"

using namespace std;


/*
Function Name: empty
Purpose:	  Initializes the top of the stack to -1,
				or an empty stack.
Incoming:         None
Outgoing:	  None
Return:		  None
*/

bool StackNode::empty()const
{
	return (top == -1);
}


/*
Function Name: full
Purpose:	   Checks to see if the stack is full.
Incoming: 	   None
Outgoing:	   None
Return:            None
*/

bool StackNode::full()const
{
	if (top==maxStack-1){
		return true;
	}else{
		return false;
	}
}


// CONSTRUCTOR
StackNode::StackNode(int MAXSTACK)
{
	stackPtr = new string[MAXSTACK];
	top = -1;
	maxStack = MAXSTACK;
}

// DESTRUCTOR
StackNode::~StackNode()
{
	while(!empty())
   	{
     	pop();
   	}
   	cout << "Stack has been destroyed." << endl;
   
   	delete stackPtr;
}


/*
Function Name: push
Purpose:	   Pushes an item on top of the stack.
Incoming: 	   inData - string
Outgoing:	   None
Return:		   None
*/

void StackNode::push(string inData)
{
  	string temp;
  	if (!full())
 	{
 		top++;
 		stackPtr[top]=inData;
    		cout << inData << " has been pushed." << endl;
 	}else{ 
    		cout << "CANNOT PUSH ONTO A FULL STACK." << endl;
	}
}

/*
Function Name: pop
Purpose:	   Removes the first item off of the stack.
Incoming: 	   None
Outgoing:	   temp - string
Return:		   temp - string
*/

string StackNode::pop()
{
	string temp;
	if (!empty())
	{
	  	temp=stackPtr [top--];
	}else{
		cout << endl << endl << "STACK IS EMPTY..." << endl;
		cout << endl << "Please enter 1 or 3 as your next option." << endl << endl;
	}

	return temp;
}




