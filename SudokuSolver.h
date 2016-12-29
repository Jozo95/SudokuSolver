#pragma once
#include <math.h>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>

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
	void printBoard();
	bool readData();
	std::vector<int> possibleEntries();

	bool solveBoard();

};