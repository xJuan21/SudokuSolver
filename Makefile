CC=g++ -c -g -Wall -ansi -pedantic 

runMe: SudokuSolver.o
	g++ -o runMe SudokuSolver.o
	
SudokuSolver.o: SudokuSolver.cpp
	$(CC)  SudokuSolver.cpp
