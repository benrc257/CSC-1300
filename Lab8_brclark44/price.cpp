// This program will read in prices and store them into a two-dimensional array.
// It will print those prices in a table form.
// It will also determine and print the highest and lowest price in the array.

// AUTHOR(S): Benjamin Clark
// DATE: 3/19/24

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXROWS = 10;
const int MAXCOLS = 10;

void getPrices(double[][MAXCOLS], int&, int&);      // gets the prices into the array
void printPrices(double[][MAXCOLS], int, int);      // prints data as a table
double findHighestPrice(double[][MAXCOLS], int, int); // finds the highest price in the array
double findLowestPrice(double [][MAXCOLS], int, int);

int main()
{
	int rowsUsed;                               // holds the number of rows used
	int colsUsed;                               // holds the number of columns used
	double priceTable[MAXROWS][MAXCOLS];        // a 2D array holding the prices

	getPrices(priceTable, rowsUsed, colsUsed);  // calls getPrices to fill the array
	printPrices(priceTable, rowsUsed, colsUsed);// calls printPrices to display array

	cout << endl << "The highest price is " << findHighestPrice(priceTable, rowsUsed, colsUsed)	<< endl;                     
	cout << endl << "The lowest price is " << findLowestPrice(priceTable, rowsUsed, colsUsed) << endl;
	
	return 0;
}

//****************************************************************************************
//
//                          getPrices
//
//  task:    This procedure asks the ser to input the numer of rows and
//           columns used.  It then asks the user to input (rows * columns)
//           number of prices where x = rows * columns.  The data is placed in the array.
//  datain:  an empty array of float
//  dataout: an array filled with numbers and the number of rows
//           and columns used.
//
//****************************************************************************************
void getPrices(double table[][MAXCOLS], int& numOfRows, int& numOfCols)
{
	cout << "\n\nPlease input the number of rows from 1 to "<< MAXROWS << endl;
	cin >> numOfRows;

	cout << "Please input the number of columns from 1 to "<< MAXCOLS << endl;
	cin >> numOfCols;
	cout << endl;
	
	for (int row = 0;  row < numOfRows;  row++)
	{
		for (int col = 0; col < numOfCols;  col++)
		{
			cout << "Please input the price of an item with 2 decimal places" << endl;
			cin >> table[row][col];
		}
	}
	cout << endl;
}

//***************************************************************************
//
//                          printPrices
//
//  task:    This procedure prints the table of prices
//  datain:  an array of floating point numbers and the number of rows
//           and columns used.
//  dataout: none
//
//****************************************************************************
void printPrices(double table[][MAXCOLS], int numOfRows, int numOfCols)
{
	cout << fixed << showpoint << setprecision(2);

	for (int row = 0;  row < numOfRows;  row++)
	{
		cout << endl;
		for (int col = 0; col < numOfCols;  col++)
		{
			cout << table[row][col] << " ";
		}
	}
	cout << endl;
}

//***************************************************************************
//
//                               findHighestPrice
//
//  task:         This function finds the highest value in a 2D array
//  datain:       an array of floating point numbers and the number of rows
//                and columns used.
//  datareturned: the highest value in the array (highest price)
//
//****************************************************************************
double findHighestPrice(double table[][MAXCOLS], int numOfRows, int numOfCols)
{
	double highestPrice;

	highestPrice = table[0][0];   // make first element the highest price

	for (int row = 0;  row < numOfRows;  row++)
		for (int col = 0;  col < numOfCols;  col++)
			if (highestPrice < table[row][col])
				highestPrice=table[row][col];

	return highestPrice;
}

//***************************************************************************
//
//                               findLowestPrice
//
//  task:         This function finds the lowest value in a 2D array
//  datain:       an array of floating point numbers and the number of rows
//                and columns used.
//  datareturned: the lowest value in the array (lowest price)
//
//****************************************************************************

double findLowestPrice(double table[][MAXCOLS], int numOfRows, int numOfCols)
{
	double lowestPrice;

	lowestPrice = table[0][0];   // make first element the lowest price

	for (int row = 0;  row < numOfRows;  row++)
		for (int col = 0;  col < numOfCols;  col++)
			if (lowestPrice > table[row][col])
				lowestPrice=table[row][col];

	return lowestPrice;
}