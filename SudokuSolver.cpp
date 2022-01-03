/**
Author: Juan Mota
Date: 09/21/2020
Purpose: Solves a Sudoku puzzle entered by the user in an input file (that contains no white spaces)
*/
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_DIM 9

char digit[MAX_DIM][MAX_DIM];// Array that stores the Sudoku Game and each digit in it.
char interval[MAX_DIM] = {'1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };// Sequence of digits that are possible and NEED to be placed in each row/column/subgrid once (Just once).
ifstream userFile;
string line;//Name of the file (Given by the user).

//Prompt a String asking the user to insert the name of the file
void ReadFile()
{
	//Get the file name
	cout << "\nWelcome to this Sudoku Solver!\nPlease, enter the name of your Sudoku file: " << endl;
	cin >> line;
	
	//Open the file
	userFile.open(line.c_str());
	
	//If the file name is NOT valid/does not exist
	if(!userFile)
	{
		cout << " XXX Sorry, '" << line << "' could not be opened. XXX \n";
		userFile.close();
	}else //If the file IS valid, store the digits of the file into the array
	    {
	    	cout << "\nFile received! you typed: "<< line << endl;
	    }
			for(int row=0; row<MAX_DIM; row++)
			{
				for (int col=0; col<MAX_DIM; col++)
					userFile >> digit[row][col];	
			}
}

//Check for all 0's and turn them into *'s (Empty spaces)
void convZeros()
{
	for(int row=0; row<MAX_DIM; row++)
	{
		for (int col=0; col<MAX_DIM; col++)
		{
			if(digit[row][col] == '0')
			{
				digit[row][col] = '*';
			}
		}	
	}
}

//Print the Borders of the chart
void printRowBorder()
{
	cout << "+---+---+---+\n";
}
//Print the Sudoku Chart (Solved or not)
void printSudoku()
{
	userFile.open(line.c_str());
	printRowBorder();//Print the top border
	
	for(int row=0; row<MAX_DIM; row++)
	{
		if(row == 3 || row == 6)// Every three rows, print a new border.
			{
				printRowBorder();

			}
				
		cout << "|";
		for (int col=0; col<MAX_DIM; col++)
		{	
			if(col == 3 || col == 6) //Split my grid into 3x3x3 columns
			{
				cout << "|";

			}
			
			cout << digit[row][col];//Print the next digit
		}
			
		cout << "|" << endl;// Set a new line (go to the next row) when I reach my last column (9th)
		
	}
	
	printRowBorder();//Print the bottom line of the grid
}
//Check if there's an empty place in the grid
bool findEmptyPlaces(char digit[MAX_DIM][MAX_DIM], int &row, int &col)
{
    for (row = 0; row < MAX_DIM; row++)
        for (col = 0; col < MAX_DIM; col++)
            if (digit[row][col] == '*')//Find any "Stars"/Empty places in the chart
                return true;
    return false;
}

// Check if this number is repeated in the current row
bool checkRow(char digit[MAX_DIM][MAX_DIM], int row, char ch)
{
    for (int col = 0; col < MAX_DIM; col++)
    if (digit[row][col] == ch)//Check if the intended number matches with one in the row
        return true;
    return false;
}

// Check if this number is repeated in the current column
bool checkCol(char digit[MAX_DIM][MAX_DIM], int col, char ch)
{
    for (int row = 0; row < MAX_DIM; row++)
        if (digit[row][col] == ch)//Check if the intended number matches with one in the column
            return true;
    return false;
}

// Check if this number is repeated in the current 3x3 Sub Grid.
bool checkSubgrid(char digit[MAX_DIM][MAX_DIM], int boxStartRow, int boxStartCol, char ch)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (digit[row+boxStartRow][col+boxStartCol] == ch)
                return true;
    return false;
}

//All the methods meet the condition and it's posible to place a number.
bool canPlace(char digit[MAX_DIM][MAX_DIM], int row, int col, char ch)
{
    return !checkRow(digit, row, ch) && !checkCol(digit, col, ch) &&
       !checkSubgrid(digit, row - row%3 , col - col%3, ch);
}

/**Solve the Sudoku Grid.
*
*Find empty places and try to place a number that 
* has not already been placed in the Game.
*/
bool SolveSudoku(char digit[MAX_DIM][MAX_DIM])
{
    int col, row;// Column and Row start in the first position (0)
    
    if (!findEmptyPlaces(digit, row, col))//if all spaces are filled, return true
       return true;
       
    for (int num = 0; num < 9; num++)
    {
    	if (canPlace(digit, row, col, interval[num])) // Check if possible to place a number
    	{
        	digit[row][col] = interval[num];// store the number (between 1-9) that meets the condition
        
        	if (SolveSudoku(digit))//Recursion, try to solve rest of the puzzle
        	    return true;
        	digit[row][col] = '*';// Recursive call failed, place and empty space ('*') again
    	}
    }
    return false;
}

int main(int argc, char *argv[])
{	
	ReadFile();
	convZeros();
	printSudoku();
	
	// If possible to Solve this Sudoku Game, print it out
	if (SolveSudoku(digit))
	{
		cout << "\nA solved version \nof the previous Sudoku:\n" << endl;
		printSudoku();
	}else
		cout << "We're sorry, we cannot find a possible solution for this" << endl;
	
	return 0;
}


