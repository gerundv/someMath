#ifndef TWOSUP_H
#define TWOSUP_H 

#include <iostream>
#include <iomanip>

const int N = 1000;

float func(float x) {
    return -std::cos(x) + ((-1 + std::cos(1)) / std::sin(1)) * std::sin(x) + 1;
}

void reverse(int K, int R, float* A, float* B) {
    float C;
    for (int J = K; J < N; ++J) {
        C = A[K + J * N];
        A[K + J * N] = A[R + J * N];
        A[R + J * N] = C;
    }
    C = B[K];
    B[K] = B[R];
    B[R] = C;
}

void dv(int K, float* A, float* B) {
    for (int J = K + 1; J < N; ++J) {
        A[K + J * N] = A[K + J * N] / A[K + K * N];
    }
    B[K] = B[K] / A[K + K * N];

}

void clear(int K, int R, float* A, float* B) {
    for (int J = K + 1; J < N; ++J) {
        A[R + J * N] = A[R + J * N] - A[K + J * N] * A[R + K * N];
    }
    B[R] = B[R] - B[K] * A[R + K * N];
}

void AlgoGauss(float* A, float* B, float* X) {
    int I;
    for (int K = 0; K < N - 1; ++K) {
        if (A[K + K * N] == 0) {
            I = K + 1;
            while (A[I + K * N] == 0) {
                I++;
            }
            reverse(K, I, A, B);
        }
        dv(K, A, B);
        for (int I = K + 1; I < N; ++I) {
            clear(K, I, A, B);
        }
    }
    dv(N - 1, A, B);
    float hi = 1.0f;

    std::cout << std::setprecision(10);
    float maxDiff = 0;
    for (int I = N - 1; I >= 0; --I) {
        X[I] = B[I];
        for (int J = I + 1; J < N; ++J) {
            X[I] = X[I] - A[I + J * N] * X[J];
        }
        float first = X[I];
        float second = func(hi);
        float diff = first < second ? first - second : second - first;
        
        maxDiff = maxDiff > diff ? diff : maxDiff;

        std::cout << "X[" << I + 1 << "] = " << first << "\t" << "F[" << I + 1 << "] = " << second << std::endl;
        hi -= 1.0f / (float)N;
    }

    std::cout << "MaxDiff = " << maxDiff << std::endl;
}

#endif //TWOSUP_H
