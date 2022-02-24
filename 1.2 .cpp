#include <iostream>
#include <cmath>
#include <iomanip>

// Нахождение корня функции с точностью e*
// методом деления отрезка;

float F(float X) {
    //return pow(X, 3) + 2 * X - 2;
    return pow(2, X) + 5 * X - 3;
}

int main() {
    float A, B, C, E;
    int k = 0;
    setlocale(LC_ALL, "rus");
    std::cout << "Введите промежутки:";
    std::cin >> A >> B;
    std::cout << "Введите точность:";
    std::cin >> E;
    //std::cout << std::setprecision(3) << std::fixed;
    while (B - A > 2 * E) {
        C = (A + B) / 2;
        std::cout << A << " " << B << std::endl;
        if (F(A) * F(C) > 0) {
            A = C;
        }
        else {
            B = C;
        }
        k++;
    }
    std::cout << "Количество итераций:" << k + 1 << std::endl;
    std::cout << "Значение корня с точностью " << E << " равно " << (A + B) / 2 << std::endl;
    std::cout << "Значение функции в корне: " << F((A + B) / 2) << std::endl;
    return 0;
}
