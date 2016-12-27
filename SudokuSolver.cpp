#include "SudokuSolver.h"

using namespace std;



SudokuSolver::SudokuSolver(){

	size = 4;
	
	*sudokuBoard = new int[size];
	for (int i = 0; i < size; i++) {
		sudokuBoard[i] = new int[size];
	}

	readData();

}

void SudokuSolver::printBoard(){
	stringstream ss;
	int w = 0;
	for (int i = 0; i < size; i++) {
		ss << "|";
		for (int q = 0; q < size; q++) {
			ss << " " << sudokuBoard[i][q] << ", ";
		}
		if (w != 2)
			w++;
		else {
			ss << endl;
			for (int s = 0; s < size; s++)
				ss << "--";
			ss << std::endl;
			w = 0;
		}
			

		
	}
}

bool SudokuSolver::readData(){

	std::cout << "IN ON READ DATA " << std::endl;
	std::ifstream dataFile;
	dataFile.open("4", std::ios::in);
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
