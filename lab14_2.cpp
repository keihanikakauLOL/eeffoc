#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void inputMatrix(double a[][N]) {

	double t;
	for (int i = 0; i < N; i++) {
		cout << "Row " << i + 1 << ": ";

		for (int j = 0; j < N; j++) {
			cin >> t;
			a[i][j] = t;
		}
	}
}

void findLocalMax(const double a[][N], bool b[][N]){
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			double max = a[i][j];

			if(max >= a[i-1][j] && max >= a[i][j-1] && max >= a[i][j+1] && max >= a[i+1][j]) {
				b[i][j] = 1;
			}
			else {
				b[i][j] = 0;
			}
		}
	}
}

void showMatrix(const bool b[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}
}