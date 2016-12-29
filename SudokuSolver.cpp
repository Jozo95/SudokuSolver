#include "SudokuSolver.h"

using namespace std;



SudokuSolver::SudokuSolver(){

	size = 9;
	
	sudokuBoard = new int*[size];
	for (int i = 0; i < size; i++) {
		sudokuBoard[i] = new int[size];
	}

	backTracker = new BackTracker[size];

	readData();

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

vector<int> SudokuSolver::possibleEntries()
{



	return vector<int>();
}




bool SudokuSolver::solveBoard(){





	return false;
}

SudokuSolver::BackTracker::BackTracker(){

	this->column = 0;
	this->value = 0;
	this->row = 0;

}

void SudokuSolver::BackTracker::setValue(int value){

	this->value = value;

}
