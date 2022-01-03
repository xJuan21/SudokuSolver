# SudokuSolver
A program that will read any txt file that will transform its content (if it is valid input) into a Sudoku chart. Consequently, the program will recursively solve the following sudoku and print the solution. 

Juan Mota 

DATE: 09/21/2020

Platform used: Linux (Gedit).

This program utilized a 2-Dimensional Array to store each digit in the Sudoku Chart. For execution, Compile the 

In order to compile the following Project, it was need to complete the following sequence of steps:

1.- Initialize:

	1.a An two dimensional Array with the capacity of creating a 9x9 Sudoku Chart.
	1.b An ifstream object that allows to read the file input by the user.
	1.c A string that stores the name of the file.
	1.d A one dimesion Array that stores a range of digits from 1-9 to place it in the Sudoku Chart.
	
2.- Important methods:

	2.a A method that allows to read the name and file of the User. Also, to store the digits of the file to the 2-D Array
	2.b A function that prints the actual information stored in the Array, along with the Borders of the Sudoku chart.
	2.c Boolean methods that helped to recognize if there was an space available in the Array to place a non-repeated number in the Row, Column, or 3x3 Boxes.
	
3.- A function using recursion to check if the chart was solved or not.

No bugs have been found at this point.

In order to approach to the solution/creation of this project, it was necessary to understand the process of nested loops to work with a two dimensional array and store/edit its elements.
Additionally, using the debugger(Nemiver) played a big role in the development of the project, since it allowed to track the status of different variables and the flow of loops and booleans
used to define or execute conditions. Finally, it was very important to review the concept of recursion and its use in order to solve the rest of the puzzle.

