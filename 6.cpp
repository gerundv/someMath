#include <iostream>

//program MNK

const int N = 9;


int main() {
	float* X;
	float* Y;

	X = new float[N] {
		//	1.65, 1.69, 1.92, 2.33, 2.55, 3.84, 5.11, 4.91, 5.44
		0.23, 2.27, 2.50, 2.92, 3.13, 4.42, 3.69, 5.50, 6.03
	};

	Y = new float[N] {
		//	8.12, 7.68, 9.16, 9.15, 10.64, 11.86, 16.64, 15.24, 17.94
		-4.50, -0.14, 1.34, 1.33, 2.82, 8.03, 4.01, 7.42, 10.12
	};
	float CX, CXX, CY, CXY, A, B, D;
	CX = 0;
	CXX = 0;
	CY = 0;
	CXY = 0;
	for (int I = 0; I < N; ++I) {
		CX += X[I];
		CXX += pow(X[I], 2);
		CY += Y[I];
		CXY += X[I] * Y[I];
	}
	D = N * CXX - CX * CX;
	A = (N * CXY - CX * CY) / D;
	B = (CXX * CY - CX * CXY) / D;
	std::cout << "y = " << A << "x + " << B << std::endl;
	return 0;
}

