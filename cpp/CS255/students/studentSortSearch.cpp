/* 
 * Name: Taylor Moore
   Program Type: CS 255 - Computer Science II
   Date: August 29, 2019
   Program Description:
		This program will store student names and IDs using parallel arrays.
		The data will be read from a file and a count of the number of students 
		(no more than 100) will be kept as the data is read. The program will
		then display the student names and student IDs (all 8 digits with
		leading zeros to fill empty spaces). The array should be sorted 
		alphabetically by the students' first names and corresponding IDs should 
		be swapped. Then, the program will offer an option to search for a 
		student using their ID.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Declaring Using Global Constant
const int MAX_STUDENTS=100;

// Function Declarations
void readStudentData (string studentNames[], int studentIds[], int& count);     
void printData (string studentNames[], int studentIds[], int count);            
int linearSearch (int studentIds[], int count, int key);                        
void selectionSort (string studentNames[], int studentIds[], int count);        


// Driver Function
int main()
{
	string studentNames[MAX_STUDENTS];
	int studentIds[MAX_STUDENTS], count=0, data=0, key=0, numElements=0, nameReturned=0;
	
	readStudentData (studentNames, studentIds, count);
        selectionSort (studentNames, studentIds, count);
	printData (studentNames, studentIds, count);

	cout << "Enter the ID for the student you are searching: ";
	cin >> key;
	
	nameReturned = linearSearch (studentIds, count, key);
	cout << studentNames[nameReturned];
	
	return 0;
}

/*
 * Function Name: readStudentData                                                              
 * Purpose: Reads the incoming file and stores the information into parallel arrays.  
 * Incoming: studentNames - string, studentIds - int, count - int                     
 * Outgoing: none 											
 * Return: none
*/

void readStudentData (string studentNames[], int studentIds[], int& count)
{
	ifstream studentFile;
	studentFile.open("students.txt");
		
	if (studentFile.fail())
	{
		cout << "Error opening file. Check for typos and permission issues." << endl;
		exit (1);
	}
	
	while (!studentFile.eof())
	{
	    studentFile >> studentNames[count] >> studentIds[count];
	    count++;
	}
		
	count--;
	studentFile.close();
}
	
	
/*
 Name: printData                                                                           
 Purpose: Prints out and formats the student information that is coming from the arrays.   
 Incoming: studentNames - string, studentIds - string, count - int                         
 Outgoing: nothing                                                                         
 Return: nothing                                                                           
*/

void printData (string studentNames[], int studentIds[], int count)
{
	cout << "Student Name:" << setw(25)<< "Student ID:" << endl;
	cout << "_____________" <<  "              " << "___________" << endl << endl;
	for (int i=0; i<count; i++) 
	{
		cout  << left << setfill(' ') << setw(8) <<  studentNames[i] << "                   "  
		<< setw(12) << setfill('0')  << setw(8) << right << studentIds[i]  << endl;
	}
}
	
	

/* Name: linearSearch											     
 * Purpose: Allows the user to search for a student based on ID and  
 * then returns the position of the student in the array.            
 * Incoming: studentIds - int, count - int, key - int                
 * Outgoing: position - int											 
 * Return: position - int or -1 if the position is not found.	     
*/

int linearSearch (int studentIds[], int count, int key)
{
	bool found=false;
	int position=0;
	while (!found && position < count)
		if (studentIds[position] == key)
			found = true;
		else
			position++;
	if (found){
		return position;
	}else{
		cout << "Student ID Does Not Exist" << endl;
		return -1;
}

/*
 * Name: selectionSort 													
 * Purpose: Keeps the names and IDs together and prevents them from separating 
 * 	    with the alphabetical sort and the search.			
 * Incoming: studentNames - string, studentIds - int, count - int
 * Outgoing: nothing														
 * Return:   nothing														 
*/

void selectionSort (string studentNames[], int studentIds[], int count)
{
	string temp;
	int tempTwo=0, minIndex=0;
	for (int i=0; i < count-1; i++)
	{
		minIndex=i;
		for (int j=i+1; j<count; j++)
		if (studentNames[j] < studentNames[minIndex]){
			minIndex=j;
			temp = studentNames[i];
			studentNames[i]=studentNames[minIndex];
			studentNames[minIndex]=temp;
			tempTwo = studentIds[i];
			studentIds[i] = studentIds[minIndex];
			studentIds[minIndex]=tempTwo;
		}
	}
}
