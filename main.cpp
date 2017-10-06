#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

bool test(int mat[3][3]) {                
	bool result = true;
	for (int i = 0; i<3; ++i) {
		string stroka;
		getline(cin, stroka);
		istringstream stream(stroka);
		for (int j = 0; j<3; ++j) {
			if (!(stream >> mat[i][j])) {
				result = false;
				break;
			}
		}
		if (!(result)) { break; }
	}
	return result;
}

int main()
{
	int matrix_1[3][3], matrix_2[3][3];
	string operation;
	if (test(matrix_1)) {
		getline(cin, operation);
		if (operation == "+") {
			if (test(matrix_2)) {
				cout << endl;
				for (int i = 0; i<3; ++i) {
					for (int j = 0; j<3; ++j) {
						cout << (matrix_1[i][j] + matrix_2[i][j]) << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "An error has occured while reading input data" << endl;
				return -1;
			}
		}
		if (operation == "-") {
			if (test(matrix_2)) {
				cout << endl;
				for (int i = 0; i<3; ++i) {
					for (int j = 0; j<3; ++j) {
						cout << (matrix_1[i][j] - matrix_2[i][j]) << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "An error has occured while reading input data" << endl;
				return -1;
			}
		}
		if (operation == "*") {
			if (test(matrix_2)) {
				cout << endl;
				for (int i = 0; i<3; ++i) {
					for (int j = 0; j<3; ++j) {
						int result_op = 0;
						for (int k = 0; k<3; ++k) {
							result_op += matrix_1[i][k] * matrix_2[k][j];
						}
						cout << result_op << " ";
					}
				}
			}
			else {
				cout << "An error has occured while reading input data" << endl;
				return -1;
			}
		}

	}
	else {
		cout << "An error has occured while reading input data" << endl;
		return -1;
	}
	return 0;
}
