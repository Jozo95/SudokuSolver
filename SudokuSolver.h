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

public:
	SudokuSolver();
	void printBoard();
	bool readData();

};