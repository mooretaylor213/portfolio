/*
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science II
 * Date: September 5, 2019
 * Program Description:
 * 	This program will test a formula that outputs data regarding football quarterbacks.
 * 	The data will include information taken from a file and use basic equations to calculate
 * 	the percentage. A struct with an array of information will also be included in this program 
 * 	and is referred to throughout the program for various functions.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Global Constant Declarations
const int MAX_QBS=50;
const double MAKE_PERCENT=100.0;
const double MAKE_DOUBLE=1.0;

// Struct Creation
struct QBInfo
{
	string firstName, lastName;
	int attempts, completions, passYards, tds, intercepts;
	double percentage, rating;
};


// Function Prototypes 
void readStats (QBInfo players[], int &count);
void displayStats (QBInfo players[], int count);
double compPer (QBInfo players[], int count);
double compRating (QBInfo players[], int count);
void qbSortNames (QBInfo players[], int count);
void qbSortRatings (QBInfo players[], int count);

// Driver Function
int main()
{
	int numPlayers=0;
	QBInfo players[MAX_QBS];
	readStats(players, numPlayers);
	displayStats(players, numPlayers);
	
	cout << endl << endl;
	qbSortNames (players, numPlayers);
	
	cout << "Sorted QBs by Last Name (ascending order): " << endl << endl;
	displayStats(players, numPlayers);
    	cout << endl << endl << endl;
	
  	qbSortRatings (players,numPlayers);
    	cout << "Sorted QBs by Ratings (descending order): " << endl << endl;
    	displayStats(players, numPlayers);
	return 0;
}

/* 
FUNCTION NAME: readStats
DESCRIPTION:   Reads the information from the file into the QBStruct.
INCOMING: 	   QBInfo players - array of structs, count - integer
OUTGOING:	   Nothing
RETURN:		   Nothing
*/

void readStats (QBInfo players[], int &count)
{
	ifstream infile("football-in.txt");
	count=0;

	while (!infile.eof())
	{
		infile >> ws;
		getline(infile, players[count].firstName);
		getline(infile, players[count].lastName);
		infile >> players[count].attempts;
		infile >> players[count].completions;
		infile >> players[count].passYards;
		infile >> players[count].tds;
		infile >> players[count].intercepts;
		players[count].rating = compRating(players, count);
		count++;	
	}
	count--;
	infile.close();
	
}

/*
FUNCTION NAME: displayStats
DESCRIPTION:   Formats the output and prints the information in the QBStruct. Also calls 
   	       other functions to print calculated data.
INCOMING:      QBInfo players - array of structs, count - integer
OUTGOING:      None
RETURN:	       None
*/
	
void displayStats (QBInfo players[], int count)
{
	
	cout << "Quarterback" << setw(15) << "Att." << setw(10) << "Comp." << setw(10) << "Pct."
             << setw(10) << "Yards" << setw(8) << "TD" << setw(11) << "Int." << setw(12) 
	     << "Rating" << endl;
	
	cout << "___________" << setw(15) << "____" << setw(10) << "______" << setw(10) 
	     << "_____" << setw(10) << "_____" << setw(10) << "______" << setw(10) 
	     << "_____" << setw(12) << "_______" << setw(10) << endl << endl;	
	
	for (int i=0; i<count; i++)
	{
		string fullName = players[i].firstName+" "+players[i].lastName;
		cout << setw(23) << left << fullName;
		cout << setw(9) << players[i].attempts;
		cout << setw(10) << players[i].completions;
		cout << setw(10) << fixed << setprecision(1) << compPer(players, i);
		cout << setw(10) << players[i].passYards;
		cout << setw(8) << players[i].tds;
		cout << setw(3) << right << players[i].intercepts;
		cout << setw(14) << fixed << setprecision(2) << compRating(players, i);
		cout << endl;
	}
}

/*
FUNCTION NAME: compPer
DESCRIPTION:   Computes the completion percentage given a quarterback struct.
INCOMING: 	   QBInfo players - array of structs, count - integer
OUTGOING:	   Percentage - double, or 0 if attempts are equal to zero
RETURN:		   Percentage, if attempts aren't equal to 0. Returns 0 if attempts are equal to zero.
*/
		
double compPer (QBInfo players[], int count)
{
	double percentage=0;
	if (players[count].attempts!=0)
	{
		percentage = ((players[count].completions) * MAKE_DOUBLE) / (players[count].attempts) * MAKE_PERCENT;
		return percentage;
    	}else{
		return 0;
	}
}

/*
FUNCTION NAME: compRating
DESCRIPTION:   Computes the performance rating of a football player during a football game 
	       using a specific formula.
INCOMING: 	   QBInfo players - array of structs, count - integer
OUTGOING:	   rating - double, or 0 if attempts is equal to zero
RETURN:		   Returns 0 if attempts is equal to zero and returns rating if attempts is greater than 0.
*/
		
double compRating (QBInfo players[], int count)
{
	double numerator=0, denominator=0, rating=0;
 	if (players[count].attempts==0){
		return 0;	
	}else{
		numerator = (3 * players[count].completions) + (players[count].passYards) + (10 * players[count].tds);
		denominator = (players[count].attempts) + (8 * players[count].intercepts);
		rating = (numerator/denominator);
		return rating;
	}
}

/*
FUNCTION NAME:  qbSortNames
DESCRIPTION:    Sorts the quarterbacks by last name in in ascending order.
INCOMING: 	QBInfo players - array of structs, count - integers
OUTGOING:	Nothing
RETURN:		Nothing
*/

void qbSortNames (QBInfo players[], int count)
{
	QBInfo temp;
	int maxIndex=0;
	for (int i=0; i<count-1; i++)
	{
		maxIndex=i;
		for (int j=i+1; j<count; j++){
			if (players[j].lastName < players[maxIndex].lastName){
				maxIndex=j;
				temp = players[i];
				players[i]=players[maxIndex];
				players[maxIndex]=temp;
			}
		}
	}
}

/*
FUNCTION NAME:  qbSortRatings
DESCRIPTION:    Sorts the ratings of quarterbacks in descending order.
INCOMING: 	QBInfo players - array of structs, count - integers 
OUTGOING:	Nothing
RETURN:		Nothing	
*/

void qbSortRatings (QBInfo players[], int count)
{
	QBInfo temp;
	int  minIndex=0;
	for (int i=0; i<count-1; i++)
	{
		minIndex=i;
		for (int j=i+1; j<count; j++){
			if (players[j].rating > players[minIndex].rating){
				minIndex=j;
				temp = players[i];
				players[i]=players[minIndex];
				players[minIndex]=temp;
			}
		}
	}
}
