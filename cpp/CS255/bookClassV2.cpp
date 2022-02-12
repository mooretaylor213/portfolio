/* 
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science II
 * Date: September 17, 2019
 * Program Description:
 * 	This program will use a constructor methods, a destructor, 
 * 	and various functions to read data in from a text file. There
 * 	will be a class method that updates the price of the book with a 
 * 	given percentage that is a double. The books will be printed with 
 * 	both original price and the discounted price. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// CLASS
class Books
{
	private: 
		string title, author;
		double price;
		int year;
	public:
		void setTitle(string);
		void setAuthor(string);
		void setPrice(double);
		void setYear(int);
		string getTitle()const;
		string getAuthor()const;
		double getPrice()const;
	        int getYear()const;
		void print()const;
		Books();
		void setValues(string, string, double, int);
		Books(string, string, double, int);
		~Books();
		double updatePrice(double);
};

// FUNCTION PROTOTYPES
void readBooksFromFile (Books book[], int &numBooks);
void printAllBooks (Books book[], int numBooks);

// GLOBAL CONSTANT
const int MAX_BOOKS=10;

// DRIVER 
int main()
{	
	Books book[MAX_BOOKS];
	int numBooks=0;
	double rate=0.50;
	
	readBooksFromFile (book, numBooks);
	printAllBooks(book, numBooks);
	
	for (int i=0; i<=numBooks; i++)
		book[i].updatePrice(rate);
	cout << "--------------------------------------------" << endl;
 	cout << "------------ UPDATED PRICES ----------------" << endl;
	cout << "--------------------------------------------" << endl;
    
	printAllBooks(book, numBooks);
	
	
	return 0;
}

// CONSTRUCTOR
Books::Books()     
{
   title="TBA";
   author="Anonymous";
   price=0;
   year=2019;
}

/*
	FUNCTION NAME: setValues
	DESCRIPTION:   Sets all the values into the class for the new variable names.
	INCOMING: 	   ti - string, au-string, pr-double, yr-int
	OUTGOING:	   Nothing
	RETURN:		   Nothing
*/

void Books::setValues(string ti, string au, double pr, int yr)
{
  title=ti;
  author=au;
  price=pr;
  year=yr;
}

Books::Books(string ti, string au, double pr, int yr)
{
  title=ti;
  author=au;
  price=pr;
  year=yr;
}

// DESTRUCTOR
Books::~Books()
{
	cout << "Book is destroyed." << endl;
}


/*
	FUNCTION NAME: updatePrice
	DESCRIPTION:   Updates the price given the discount rate.
	INCOMING:      rate - double
	OUTGOING:      price - double
	RETURN:	       price - double
*/

double Books::updatePrice(double rate)
{
	double tempPrice=0;
	

	if (rate < 1.0){
		price -= (price * rate);
	}
	if (rate = 1.00){
		price = price;
	}else{ 
		price += (price * rate);
	}	

	return price;
}

/*
	FUNCTION NAME: readBooksFromFile
	DESCRIPTION:   Reads the book information in from an infile.
	INCOMING:      book - array, numBooks - int
	OUTGOING:      None
	RETURN:	       None
*/
void readBooksFromFile (Books book[], int &numBooks)
{
     numBooks=0;
     ifstream bookFile("books.txt");
     int yr=0;
     double pr=0;
     string ti, au;
     getline(bookFile, ti);
	   
     while (!bookFile.eof())
     {
                
       getline(bookFile, au);
       bookFile >> pr >> yr;
       bookFile >> ws;
       book[numBooks].setValues(ti, au, pr, yr);            
       numBooks++;
       getline (bookFile, ti);
     }
     
     bookFile.close();
}

/*
	FUNCTION NAME: printAllBooks
	DESCRIPTION:   Prints all books and stops when numBooks is done.
	INCOMING: 	   book - array, numBooks - int
	OUTGOING:	   Nothing
	RETURN:		   Nothing
*/
void printAllBooks (Books book[], int numBooks)
{
     
     for (int i=0; i<numBooks; i++)
     {        
         book[i].print();
         cout << endl;
     }

}

/*
	FUNCTION NAME: print
	DESCRIPTION:   Prints the basic formatting where the data from the class will fit in.
	INCOMING: 	   Nothing
	OUTGOING:	   Prints for formatting the information.
	RETURN:		   Nothing
*/
void Books::print()const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Price: $" << setprecision(2) << fixed << price << endl;
	cout << "Year of Publication: " << year << endl;
}
