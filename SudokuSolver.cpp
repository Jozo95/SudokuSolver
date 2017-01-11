#include "SudokuSolver.h"



SudokuSolver::SudokuSolver(){

	size = 9;
	
	sudokuBoard = new int*[size];
	for (int i = 0; i < size; i++) {
		sudokuBoard[i] = new int[size];
	}

	//backTracker = new BackTracker[size];

	readData("9.txt");

	solveBoard();
}

SudokuSolver::SudokuSolver(int size){

	this->size = size;

	sudokuBoard = new int*[size];
	for (int i = 0; i < size; i++) {
		sudokuBoard[i] = new int[size];
	}

	//backTracker = new BackTracker[size];
	if(size == 4)
		readData("4.txt");
	if (size == 9)
		readData("9.txt");
	if (size == 16)
		readData("16.txt");

	//solveBoard(-1, 0);
}

void SudokuSolver::printBoard(){
	stringstream ss;

	if (size == 9) {
		int w = 0, p = 0, s = 0;

		for (int i = 0; i < size; i++) {
			ss << "|";
			for (int q = 0; q < size; q++) {
				ss << sudokuBoard[i][q];
				if (w != 2) {
					ss << ", ";
					w++;
				}
				else {
					//ss << endl;
					//for (int s = 0; s < size; s++)
					ss << "|";
					//ss << std::endl;
					w = 0;

				}

				if (size - 1 == p) {
					ss << endl;
					p = 0;
					s++;
				}
				else
					p++;

				if (size*(int)sqrt(size) + 2 == s) {
					//ss << endl;
					for (int s = 0; s < size - 1; s++)
						ss << "---";
					ss << std::endl;
					s = 0;
				}
				else
					s++;
			}
		}
	}

	else {
		for (int i = 0; i < size; i++) {
			ss << "|";
			for (int q = 0; q < size; q++) {
				ss << sudokuBoard[i][q] << ", ";
			}
			ss << "|";
			ss << endl;
		}
	}

	ss << endl;
	cout << ss.str();
}

bool SudokuSolver::readData(string filename){

	std::cout << "IN ON READ DATA " << std::endl;
	std::ifstream dataFile;
	dataFile.open(filename, std::ios::in);
	if (!dataFile.is_open()) {
		std::cout << "dataFile wasnt loaded with '4'" << std::endl;
	}
	else {
		int x=0, y=0, c = 0;
		string str;
		while (getline(dataFile, str)){
			istringstream ss(str);
			int num;
			while (ss >> num){
				sudokuBoard[x][y++] = num;
			}
			x++;
			y = 0;
		}
		//printBoard();
		std::cout << "Counter: " << c << std::endl;
	}
	dataFile.close();
	return true;
}

bool SudokuSolver::coverFiller(int row, int column) {

	if (column == size) {
		row += 1;
		column = 0;
	}
		
	int *possEntries = new int[this->size];
	int trueSize = 0;
	bool zeroFound = false;

	
	for (int i = row; i < size; i++) {
		for (int k = column; k < size; k++) {
			if (sudokuBoard[i][k] == 0) {
				row = i;
				column = k;
				i = size;
				zeroFound = true;
				break;
			}
		}
	}

	if (zeroFound) {

		for (int i = 1; i <= this->size; i++) {
			if (isSafe(i, row, column))
				possEntries[trueSize++] = i;
		}

		if (trueSize == 1) {
			cout << "ROW: " << row << ". COLUMN " << column << " has 1 poss, " << possEntries[0] << endl;
			sudokuBoard[row][column] = possEntries[0];
			delete possEntries;
			coverFiller(row, (column + 1));
			return true;
		}
		else {
			delete possEntries;
			coverFiller(row, (column + 1));
			return false;
		}
		
	}
	delete possEntries;
	return false;
}

bool SudokuSolver::isSafe(int num, int row, int column) {
	for (int i = 0; i < size; i++) {
		//row modifier
		if (sudokuBoard[row][i] == num){
			return false;
		}
		if (sudokuBoard[i][column] == num) {
			return false;
		}
	}
	int r, c;


	for (int rowz = 0; rowz < (int)sqrt(size); rowz++) {
		for (int colz = 0; colz < (int)sqrt(size); colz++) {
			r = rowz + (row - (row % ((int)sqrt(size))));
			c = colz + (column - (column % (int)sqrt(size)));
			if (sudokuBoard[r][c] == num)
				return false;
		}
	}


	return true;
}

bool SudokuSolver::solveBoard(){

	//coverFiller(0, 0);

	int sizer = size;
	int row, column;
	bool zeroFound = false;
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (sudokuBoard[i][k] == 0) {
				row = i;
				column = k;
				i = size;
				zeroFound = true;
				break;
			}
		}
	}
	
	if (!zeroFound)
		return true;
	else {
		int *possEntries = new int[sizer];
		int trueSize = 0;
		for (int i = 1; i <= size; i++)
			if (isSafe(i, row, column))
				possEntries[trueSize++] = i;
		for (int l = 0; l < trueSize; l++){
			//if (row > 13)
				//printBoard();
			sudokuBoard[row][column] = possEntries[l];
			if (solveBoard()) {
				delete possEntries;
				return true;
			}
			sudokuBoard[row][column] = 0;
		}
		delete possEntries;
		return false;
	}


	//int sizer = size;
	//int row1 = row, column1 = column+1;

	//
	//bool zeroFound = false;

	//for (int i = row1; i < size; i++) {

	//	for (int k = column1; k < size; k++) {

	//		if (sudokuBoard[i][k] == 0) {
	//			row1 = i;
	//			column1 = k;
	//			i = size;
	//			zeroFound = true;
	//			break;
	//		}

	//	}
	//}
	////printBoard();
	//if (zeroFound) {

	//	int *possEntries = new int[sizer];
	//	int ctrrr = 0;
	//	for (int i = 1; i <= size; i++) {
	//		if (isSafe(i, row1, column1)) {
	//			possEntries[ctrrr++] = i;
	//		}
	//		else
	//			sizer--;
	//	}
	//	sizer = ctrrr;
	//	int counter = 0;
	//	if (row1 > 3 && column1 > 0) {
	//		printBoard();
	//		zeroFound = true;
	//	}
	//	//int tester = possEntries[counter];
	//	if (possEntries[counter] > 0 && possEntries[counter] <=size && counter < ctrrr) { // || poss
	//		sudokuBoard[row1][column1] = possEntries[counter++];
	//	}

	//	else {
	//		//if (row1 == 3 && column1 == 12) {
	//		//	printBoard();
	//		//	cout << " POSSIBILITIES: " << endl;
	//		//	for (int i = 0; i < size; i++)
	//		//		cout << sudokuBoard[3][i] << ", ";
	//		//	cout << endl;
	//		//	cout << "VAL: " << sudokuBoard[row1][column1] << endl;
	//		//}
	//		//printBoard();
	//		sudokuBoard[row1][column1] = 0;
	//		delete possEntries;
	//		//printBoard();
	//		return false;

	//	}
	//	int debugger = 0;
	//	while (!solveBoard(-1, 0)) {
	//		if (row1 == 3 && column1  == 11) {
	//			debugger = 0;
	//			//printBoard();

	//			//cout << "val: " << sudokuBoard[row1][column1] << endl;
	//		}
	//	
	//		if (possEntries[counter] > 0 && possEntries[counter] <=size && counter < ctrrr) { // || poss
	//			sudokuBoard[row1][column1] = possEntries[counter++];
	//		}
	//		else {
	//			delete possEntries;
	//			sudokuBoard[row1][column1] = 0;
	//			return false;
	//			
	//		}
	//		debugger++;
	//		
	//	}

	//	delete possEntries;
	//	return true;
	//}

	//else {
	//	cout << "NO ZEROS FOUND " << endl;
	//	return true;
	//}
}

int SudokuSolver::randomizedSudoku(int size){
	int randNr;
	for (int i = 0; i < this->size; i++)
		delete sudokuBoard[i];
	delete sudokuBoard;
	this->size = size;

	sudokuBoard = new int*[size];
	//int *sudokuBoardz = new int[size];

	for (int i = 0; i < size; i++) {
		sudokuBoard[i] = new int[size];
		for (int k = 0; k < size; k++)
			sudokuBoard[i][k] = 0;
	}


	srand(time(NULL));
	int ctr = 0;
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			ctr = 0;
			randNr = rand() % size;
			while (!isSafe(randNr, i, k)) {

				if (randNr == 0){
					sudokuBoard[i][k] = randNr;
					break;
				}
				randNr = rand() % (size);
				ctr++;
				if (ctr == 100) {
					printBoard();
					ctr = 0;
					//return 0;
					//break;
				}
			}
			sudokuBoard[i][k] = randNr;
		}
	}


	if (!solveBoard()) {
		
		randomizedSudoku(size);

	}
	//cout << "END" << endl;
	//cout << tempHolder << " <_ tmp.   sudoku->" << sudokuBoard << endl;
	//sudokuBoard = tempHolder;
	//cout << tempHolder << " <_ tmp.   sudoku->" << sudokuBoard << endl;
	return 1;

}

SudokuSolver::BackTracker::BackTracker(){

	this->column = 0;
	this->value = 0;
	this->row = 0;

}

void SudokuSolver::BackTracker::setValue(int value){

	this->value = value;

}
