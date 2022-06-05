#include <math.h>
#include <iostream>
#include "twoSup.h"


int main() {

    float* A;
    float* B;
    float* X;
    int I, K, J;

    A = new float[N * N]{
        1, 2, 1, 2,
        -1, 1, 3, -3,
        2, 0, 1, 1,
        3, 2, -1, 0
    };

    B = new float[N] { 1, 2, -1, 3 };
    X = new float[N];

    AlgoGauss(A, B, X);
    return 0;
}
