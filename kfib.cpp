#include <fstream>
#include <iostream>
#include <array>

using namespace std;

using BigUInt = unsigned long long;

using Matrix2x2 = array<array<BigUInt,2>,2>;

Matrix2x2 fib = {0,1,1,1};

Matrix2x2 multiply(Matrix2x2 a, Matrix2x2 b,uint mod) {
	Matrix2x2 res = {0,0,0,0};
	for(int k = 0; k < 2; ++k) {
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				res[i][j] += (a[i][k] * b[k][j]) % mod;
				res[i][j] %= mod;
			}
		}
	}

	return res;
}

void printMatrix(Matrix2x2 mat) {
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

Matrix2x2 pow(Matrix2x2 b, uint exp, uint mod) {
	if(exp == 0) {
		return {1,0,0,1};
	}
	if(exp == 1) {
		return b;
	}

	if(exp % 2 == 0) {
		return pow(multiply(b,b,mod),exp/2,mod);
	}
	else {
		return multiply(pow(multiply(b,b,mod),exp/2,mod),b,mod);
	}
}

const uint MOD = 666013;

int main() {
	ifstream in("kfib.in");
	ofstream out("kfib.out");

	uint k;
	in >> k;

	out << pow(fib,k+1,MOD)[0][0] << '\n';
}