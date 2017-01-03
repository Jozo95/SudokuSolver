#include "SudokuSolver.h"



SudokuSolver::SudokuSolver(){

	size = 9;
	
	sudokuBoard = new int*[size];
	for (int i = 0; i < size; i++) {
		sudokuBoard[i] = new int[size];
	}

	//backTracker = new BackTracker[size];

	readData();


	//int sizer = 9;
	//int *possEntries = new int[sizer];


	//for (int i = 1; i <= sizer; i++) {
	//	possEntries[i - 1] = i;
	//}
	//possibleEntries(8, 1, possEntries, sizer);
	////cout << "Accepted numbers for row " << row1 << ". column " << column1 << endl;
	//	for (int i = 0; i < sizer; i++) {
	//		cout << "Accepted: " << possEntries[i] << endl;
	//}
	solveBoard(-1,0);
}

void SudokuSolver::printBoard(){
	stringstream ss;
	int w = 0,p=0,s=0;
	for (int i = 0; i < size; i++) {
		ss << "|";
		for (int q = 0; q < size; q++) {
			ss << sudokuBoard[i][q] ;
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

			if (size*3+2 == s) {
				//ss << endl;
				for (int s = 0; s < size-1; s++)
					ss << "---";
				ss << std::endl;
				s = 0;
			}
			else
				s++;
		}

			
		
		
	}
	ss << endl;
	cout << ss.str();
}

bool SudokuSolver::readData(){

	std::cout << "IN ON READ DATA " << std::endl;
	std::ifstream dataFile;
	dataFile.open("9t.txt", std::ios::in);
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
		printBoard();
		std::cout << "Counter: " << c << std::endl;
	}
	dataFile.close();
	//dataFile.open("data16k.txt", std::ios::in);
	//if (dataFile.is_open()) {
	//	int x, y, c = 0;
	//	while (!dataFile.eof()) {
	//		dataFile >> x;
	//		dataFile >> y;
	//		verticesFor16.push_back(Vertex(x, y));
	//		c++;
	//	}
	//	//printVertex();
	//	std::cout << "Counter: " << c << std::endl;
	//}
	return true;
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
	for (int rowz = 0; rowz < 3; rowz++) {
		for (int colz = 0; colz < 3; colz++) {
			r = rowz + (row - (row % 3));
			c = colz + (column - (column % 3));
			if (sudokuBoard[r][c] == num)
				return false;
		}
	}


	return true;
}
void SudokuSolver::possibleEntries(int row, int column, int possEntries[], int& sizer)
{
	
	int *foundNumbers = new int[size*2]; // change

	int x = 0;


	for (int i = 0; i < sizer; i++)
		for (int rowz = 0; rowz < 3; rowz++)
			for (int colz = 0; colz < 3; colz++)
				if (sudokuBoard[rowz + (row - (row % 3))][colz + (column - (column % 3))] == possEntries[i]) {
					if (sizer == 1) {
						possEntries[i] = -1;
					}
					else
						possEntries[i] = possEntries[--sizer];
				}



	delete foundNumbers;
}




bool SudokuSolver::solveBoard(int column, int row){
	int sizer = size;
	int row1 = row, column1 = column+1;



	
	bool zeroFound = false;

	for (int i = row1; i < size; i++) {

		for (int k = column1; k < size; k++) {

			if (sudokuBoard[i][k] == 0) {
				row1 = i;
				column1 = k;
				i = size;
				zeroFound = true;
				break;
			}

		}
	}
	//printBoard();
	if (zeroFound) {
		int *possEntries = new int[sizer];

		int ctrrr = 0;
		for (int i = 1; i <= size; i++) {
			if (isSafe(i, row1, column1)) {
				possEntries[ctrrr++] = i;
			}
			else
				sizer--;
		}
		sizer = ctrrr;
		int counter = 0;
		//possibleEntries(row1, column1, possEntries, sizer);
		/*cout << "Accepted numbers for row " << row1 << ". column " << column1 << endl;
		for (int i = 0; i < sizer; i++) {
			cout << "Accepted: " << possEntries[i] << endl;
		}*/
		int tester = possEntries[counter];
		if (tester > 0 && tester <=size) { // || poss
			sudokuBoard[row1][column1] = possEntries[counter++];
		}
		else {
			
			sudokuBoard[row1][column1] = 0;
			delete possEntries;
			//printBoard();
			return false;

		}
		while (!solveBoard(-1, 0)) {
			if (possEntries[counter] > 0 && possEntries[counter] <=size) { // || poss
				sudokuBoard[row1][column1] = possEntries[counter++];
			}
			else {
				delete possEntries;
				sudokuBoard[row1][column1] = 0;
				return false;
				
			}
		}
		delete possEntries;
		return true;
	}

	else {
		cout << "NO ZEROS FOUND " << endl;
		return true;
	}
	
	/*for (int i = 0; i < sizer; i++){
		cout << "Accepted: " << possEntries[i] << endl;
	}*/
}

SudokuSolver::BackTracker::BackTracker(){

	this->column = 0;
	this->value = 0;
	this->row = 0;

}

void SudokuSolver::BackTracker::setValue(int value){

	this->value = value;

}
