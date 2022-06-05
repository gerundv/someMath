
#include <iostream>

//program SYMP

float F(float X) {
    //return X * sqrt(X + 1);
    //return sin(X); 
    float a = 0.83;
    float b = 1.53;
    //float a = 1.85;
    //return exp(a* X) * sin(b * X); //1
    return 1 / sqrt(X * X + a);
}

// n=2m , m=1,2,3..  | [40] = n 
// пи = 3.1415926535

int main()
{
    float A, B, H, S, X;
    int N;
    float e = 0.1f;
    std::cout << "Enter the ends of the original gap: ";
    std::cin >> A >> B;
    std::cout << "Enter m: ";
    std::cin >> N;
    N *= 2;
    H = (B - A) / float(N);
    S = (F(A) - F(B)) / 2;
    for (int i = 1; i <= N / 2; i++) {
        X = A + 2 * i * H;
        S = S + F(X) + 2 * F(X - H);
    }
    S = S * 2 * H / 3;
    std::cout << "the value of the integral: " << S;
    return 0;
}
