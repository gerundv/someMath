

#include <iostream>
#include <cmath>
#include "Gauss.h"

/*
float form(float* Y, int i, float h) {
	return (Y[i + 1 + i * N] - 2 * Y[i + i * N] + Y[i - 1 + i * N]) / std::pow(h,2);
}
*/

int main()
{
	int N = 1000;
	float* Y = new float[N * N];
	float h = 1 / (float)N;
	float* B = new float[N];

	B[0] = 0;

	for (int i = 1; i < N - 1; i++)
		B[i] = 1;

	B[N - 1] = 0;

	float* X = new float[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Y[i + j * N] = 0;
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << Y[i + j * N] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;*/

	Y[0] = 1;

	Y[1] = 1 / (float)std::pow(h, 2);

	for (int i = 1; i < N; i++) {
		Y[i + i * N] = 1 - 2 / (float)std::pow(h, 2);
		Y[i + 1 + i * N] = 1 / (float)std::pow(h, 2);
		Y[i - 1 + i * N] = 1 / (float)std::pow(h, 2);
	}

	Y[N * N - N - 1] = 0;
	Y[N * N - 1] = 1;
	Y[N] = 0;



	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << Y[i + j * N] << "\t";
		}
		std::cout << std::endl;
	}*/

	AlgoGauss(Y, B, X);

	std::cout << std::endl;
	return 0;
}
