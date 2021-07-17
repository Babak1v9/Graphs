#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;

struct cityPos {
	double xPos;
	double yPos;
} city;

//calculates the distance between two points utilizing the pythagorean theorem
double getCost(cityPos a, cityPos b) {
	return sqrt(pow((b.yPos - a.yPos) , 2) + pow((b.xPos - a.xPos) , 2));
}

//prints out the matrix, optimised for human readability
void printMatrix(vector<vector<double>> matrix, int count) {
	for (int i = 0; i < count; i++) {
		cout << "   " << i + 1;
	}
	for (int i = 0; i < count; i++) {
		cout << endl << i + 1 << " ";
		for (int j = 0; j < count; j++) {
			cout << matrix[i][j] << " ";
		}

	}
	cout << endl << endl;
}

void nearestNeighbor(vector<vector<double>> matrix, int count) {
	int i = 0;
	double tempMin;
	double distance = 0;
	int tempY;
	int tempX;
	for (int k = 0; k < count - 1; k++) {
		tempMin = 0;
		tempY = 0;
		for (int j = 1; j < count; j++) {
			if (matrix[i][j] > 0 && (matrix[i][j] < tempMin || tempMin == 0)) {
				tempMin = matrix[i][j];
				tempY = j;
			}
		}
		cout << i + 1 << " --" << tempMin << "--> " << tempY + 1 << endl;
		distance = distance + tempMin;
		for (i = 0; i < count; i++) {
			matrix[i][tempY] = 0;
		}
		i = tempY;
	}
	distance = distance + matrix[i][0];
	cout << i + 1 << " --" << matrix[i][0] << "--> " << 1 << endl;
	cout << "Distance: " << distance << endl << endl;
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: tsp -n|e filename");
    }

    string algoChoice = argv[1]; //stores first input which is the algorithm
    string filename = argv[2]; //stores filename

	//Programm liest aus einer Datei n zweidimensionale Punkte ein = städte
	std::vector<cityPos> structArray; //vector to store struct
	string line;
	ifstream myFile(filename);
	int cityCount;

	if (myFile.is_open()) {
		getline(myFile, line);
		cityCount = atoi(line.c_str());
		while (getline(myFile, line)) {
			std::istringstream iss(line);
			string x, y;
			cityPos city;
			getline(iss, x, ' ');
			city.xPos = stod(x);
			getline(iss, y);
			city.yPos = stod(y);
			structArray.push_back(city);
		}
		myFile.close();
	}
	else {
		cout << "File is not open!" << endl;
	}

	cout << endl << "City count:" << cityCount << endl << endl << "City Positions:" << endl;
	for (int i = 0; i < structArray.size(); i++) {
		cout << fixed << setprecision(1) << structArray[i].xPos << " " << structArray[i].yPos << endl;
	}
	cout << endl;
	/*
	double d = getCost(structArray[0], structArray[4]);
	cout << d;
	*/
	vector<vector<double>> matrix;
	matrix.resize(cityCount);
	for_each(matrix.begin(), matrix.end(), [](vector<double>& v) {v.resize(200);});

	//cout << structArray[4].xPos;

	for (int i = 0; i < cityCount; i++) {
		for (int j = 0; j < cityCount; j++) {
			matrix[i][j] = getCost(structArray[i], structArray[j]);
		}
	}
	printMatrix(matrix, cityCount);

	std::clock_t c_start = std::clock();
	if (algoChoice == "-n") {
        cout << "You choose Nearest neighbour heuristic algorithm" <<endl ;
        nearestNeighbor(matrix, cityCount);
	}
	std::clock_t c_end = std::clock();
    cout << std::fixed << std::setprecision(2) << "CPU time used: " << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n" <<endl;

    std::clock_t c_start2 = std::clock();
	if (algoChoice == "-e") {
        cout << "You choose enumeration algorithm" <<endl ;
        // HIER DEINE FUNKTION
	}
	std::clock_t c_end2 = std::clock();
    cout << std::fixed << std::setprecision(2) << "CPU time used: " << 1000.0 * (c_end2-c_start2) / CLOCKS_PER_SEC << " ms\n" <<endl;


}
