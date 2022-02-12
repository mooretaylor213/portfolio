/* 
 * Name: Taylor Moore
 * Program Type: Course Assignment - Computer Science II
 * Date: September 10, 2019
 * Program Description:
	This program uses classes to set information and retrieve (get) information.
	All four member variables that are set using the class will be printed and 
	formatted. Two books are created, and the result is outputted. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

//CLASS
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
};

//DRIVER FUNCTION
int main()
{	
	Books book, book2;
	
	cout << "Book Information for Book 1" << endl;
	cout << "___________________________" << endl << endl;
	book.setTitle("Perfume");
	book.setAuthor("Patrick Suskind");
	book.setPrice(16.00);
	book.setYear(1985);
	book.print();
	
	book = book2;
	cout << endl << endl << "Book Information for Book 2" << endl;
	cout << "___________________________" << endl << endl;
	book2.setTitle("Life of Pi");
	book2.setAuthor("Yann Martel");
	book2.setPrice(15.95);
	book2.setYear(2003);
	book2.print();

	return 0;
}

// SETTERS
void Books::setTitle(string ti)
{
	title=ti;
}

void Books::setAuthor(string au)
{
	author=au;
}

void Books::setPrice(double pr)
{
	price=pr;
}

void Books::setYear(int yr)
{
	year=yr;
}

// GETTERS
string Books::getTitle()const
{
	return title;
}

string Books::getAuthor()const
{
	return author;
}

double Books::getPrice()const
{
	return price;
}

int Books::getYear()const
{
	return year;
}

void Books::print()const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Price: $" << setprecision(2) << fixed << price << endl;
	cout << "Year of Publication: " << year << endl;
}

