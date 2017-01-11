#include "SudokuSolver.h"


int main() {


	cout << "--- Welcome to Jozef's Sudoku Solver ---" << endl << "Currently supports 4x4, 9x9, 16x16 formats." << endl << endl <<
		"Now solving a 4x4 sudoku:" << endl << "Input:" << endl;


	SudokuSolver s = SudokuSolver(4);
	s.printBoard();

	//s.printBoard();
	//s.randomizedSudoku(4);
	//s.printBoard();
	//s.coverFiller(0, 0);
	if (s.solveBoard()) {
		cout << "Finished, result: " << endl;
		//s.printBoard();
	}
	else
		cout << "No solutions found." << endl;
	s.printBoard();
	cout << "Now solving a 9x9 sudoku:" << endl << "Input:" << endl;

	s = SudokuSolver(9);
	s.printBoard();

	//s.coverFiller(0, 0);
	if (s.solveBoard()) {
		cout << "Finished, result: " << endl;
		//s.printBoard();
	}
	else
		cout << "No solutions found." << endl;
	s.printBoard();
	cout << "Now solving a 16x16 sudoku:" << endl << "Input:" << endl;

	s = SudokuSolver(16);
	s.printBoard();
	//s.coverFiller(0, 0);
	if (s.solveBoard()) {
		cout << "Finished, result: " << endl;
		s.printBoard();
	}
	else
		cout << "No solutions found." << endl;
	s.printBoard();
	cout << "Finished " << endl;

	//s.randomizedSudoku(9);
	//s.printBoard();

//s.printBoard();
	cout << "Catcher";
	while (1) {

	}

}