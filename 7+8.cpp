#include <iostream>
#include <cmath>
#include <iomanip>

float function(float x, float y) {
    return (y - 1) / (x * x);
}

float realFunction(float x) {
    return std::exp(-1 + 1 / x) + 1;
}


int main() {
    float x, y, xr, yr, h;
    h = 0.01f;

    x = 1;
    y = 2;

    xr = 1;
    yr = 2;

    const int N = 10;
    float k1, k2, k3, k4;
    std::cout << "Iter." << "\t|\t" << "yRunge" << "\t|\t" << "yEuler" << "\t|\t" << "real" << "\t|" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    for (int i = 0; i < N; i++) {
        k1 = function(x, y) * h;
        x += h / 2.0f;
        k2 = function(x, y + k1 / 2.0f) * h;
        k3 = function(x, y + k2 / 2.0f) * h;
        x += h / 2.0f;
        k4 = function(x, y + k3) * h;
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0f;
        std::cout << i << "\t|\t";
        std::cout << y << "\t|\t";
        yr += h * function(xr, yr);
        xr += h;
        std::cout << yr << "\t|\t";
        std::cout << yr + realFunction(xr) * h << "\t|\t";
        std::cout << std::endl;
    }

    return 0;
}