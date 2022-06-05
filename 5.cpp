
#include <iostream>
#include <random>
//program MK

float F(float X) {
    return X * sqrt(X + 1);
}

int main()
{
    float A, B, H, S, X;
    int N;
    std::cout << "Enter the ends of the original gap: ";
    std::cin >> A >> B;
    std::cout << "Enter N: ";
    std::cin >> N;
    H = (B - A) / N;
    S = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> uid(0.0f, 1.0f);

    for (int i = 1; i <= N; i++) {
        X = A + (B - A) * uid(gen);
        S = S + F(X) * H;
    }
    std::cout << "the value of the integral: " << S << std::endl;
    system("pause");
    return 0;
}
