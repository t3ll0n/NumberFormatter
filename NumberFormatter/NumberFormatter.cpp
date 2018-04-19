//-------------------------------------------------------------------------------------------------------
//
// Name: Smith, Tellon
//
// Course: CS 1063 - Data Structures & ADT, Spring 15, Dr. Stringfellow
//
// Program Assignment : #4 - Problem 2
//
// Due Date: Monday, Mar. 30, 2015, 9AM
//
// Purpose: This program prints a number with commas inserted by using a recursive function
//
//-------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//Purpose: prints a number with commas inserted (if applicable) using recursion 
//Requires: the number to be formatted (num), and count (the number of recursions to perform) 
//Returns: the number with commas inserted (if applicable)
void printNumber(long num, int & count);

//Purpose: prints heading info
//Requires: none
//Returns: prints heading to console
void printHeadings();

//Purpose: prints welcome message
//Requires: none
//Returns: prints welcome message to console
void printWelcomeMessage();

//Purpose: prints exit message
//Requires: none 
//Returns: prints exit message to console
void printExitMessage();

//Purpose: gets the user input for a number to print formatted with commas
//Requires: the user input
//Returns: the user input
long getNum();

int main()
{
	long num;
	int count = 0;
	bool choice = true;

	printHeadings();
	printWelcomeMessage();

	//continues to run unless user enters -1
	do
	{
		num = getNum();

		if (num == -1)
		{
			choice = false;
		}
		else
		{
			printNumber(num, count);
		}
	} while (choice);

	printExitMessage();

	system("pause");
	return 0;
}

void printNumber(long num, int & count)
{
	if (num != 0)
	{
		//increment level of recursion
		count++;
		
		//print all but last digit (with commas)
		printNumber(num / 10, count);
		
		//print last digit
		cout << (num % 10);

		//determine if a comma should be printed based on level, should not print a comma after\
		 last digit
		if (((count + 2) % 3) == 0 && count != 1)
			cout << ',';
		
		//decrement level of recursion
		count--;		
	}	
}

void printHeadings()
{
	cout << "\nName: Tellon Smith" << endl;
	cout << "Course: CS 1063 - Data Structures & ADT, Spring 15, Dr. Stringfellow" << endl;
	cout << "Program Assignment: #4 - Problem 2" << endl;
	cout << "Due Date: Monday, Mar. 30, 2015, 9AM" << endl;
	cout << "Purpose: This program prints a number with commas inserted by using a" << endl;
	cout << "         recursive function" << endl;
}


void printWelcomeMessage()
{
	cout << "\nWelcome to the Number Formatter Program!" << endl;
	cout << "\nEnter -1 to Quit" << endl;
}

void printExitMessage()
{
	cout << "\nThank you for using the Number Formatter Program... Goodbye!" << endl;
}

long getNum()
{
	long num;
	bool withinRange = false;

	//prevents user from entering a number greater that the max size for a long variable
	do
	{
		cout << "\nPlease enter a number to be formatted with commas: ";
		cin >> num;
		if (!cin)
		{
			cin.clear();
			cin.ignore();
					
			cout << "\nPlease enter a number less than 2,147,483,648" << endl;
		}
		else
		{
			withinRange = true;
		}
	} while (withinRange == false);

	return num;
}
