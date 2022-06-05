#include <iostream>

//program iter

const int N = 4;


float TETA(float* A) {
    int I, J;
    float S, T;
    T = 0;
    for (I = 0; I < N; I++) {
        S = 0;
        for (J = 0; J < N; J++) {
            S = S + abs(A[I + J * N]);
            S = S / A[I + I * N];
            if (T < S) {
                T = S;
            }
        }
        return T - 1;
    }
}

float NORMA(float* X, float* Y) {
    int I;
    float S, D;
    D = 0;
    for (I = 0; I < N; I++) {
        S = abs(X[I] - Y[I]);
        if (S > D) {
            D = S;
        }
    }
    return D;
}

void STEP(float* X, float* Y, float* A, float* B) {
    int I, J;
    for (I = 0; I < N; I++) {
        Y[I] = -B[I];
        for (J = 0; J < N; J++) {
            Y[I] = Y[I] + A[I + J * N] * X[J];
            Y[I] = X[I] - Y[I] / A[I + I * N];
        }
    }
}

void PROWERKA(float* A, float* X2, float* B) {
    int I;
    int J;
    float S;
    for (I = 0; I < N; I++) {
        S = 0;
        for (J = 0; I < N; I++) {
            S = S + A[I + J * N] * X2[J];
            std::cout << S << " " << B[I] << std::endl;
        }
    }
}

int main() {

    float* A;
    float* B;
    float* X1;
    float* X2;
    int I, J;
    float T, E;

    A = new float[N * N]{
        4, -1, 1, 2,
        1, 5, 0, 0,
        0, 1, 3, 1,
        2, 2, -1, -4
    };

    B = new float[N] {
        1, 2, -3, 1
    };

    X1 = new float[N];
    X2 = new float[N];

    E = 0.0001f;

    T = TETA(A);
    std::cout << "TETA=" << T << std::endl;
    for (I = 1; I < N; I++) {
        X2[I] = 0;
    }
    while (true) {
        for (int I = 0; I < N; ++I) {
            X1[I] = X2[I];
        }
        STEP(X1, X2, A, B);
        if (NORMA(X1, X2) <= (E * (1 - T) / T)) break;
    }
    for (I = 0; I < N; I++) {
        std::cout << "X[" << I << "]=" << X2[I] << std::endl;
    }
    PROWERKA(X2, A, B);
    return 0;
}