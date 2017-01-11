#pragma once
#include <math.h>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class SudokuSolver {


private:
	std::ifstream dataFile;
	int size;
	int **sudokuBoard;
	class BackTracker{
	public:
		BackTracker();
		BackTracker(int r, int c, int v) { row = r; column = c; value = v; };
		void setValue(int value);
		
	private:
		int row;
		int column;
		int value;
	};

	SudokuSolver::BackTracker * backTracker;

public:
	SudokuSolver();
	SudokuSolver(int size);
	void printBoard();
	bool readData(string filename);
	bool isSafe(int num, int row, int column);

	bool solveBoard();
	bool SudokuSolver::coverFiller(int row, int column);

	int randomizedSudoku(int size);

};