#include <iostream>
#include <cmath>
#include <iomanip>

//метод касательных

float F(float X){
    //return float(pow(X,3) - 3 * pow(X,2) + 9 * X - 8); // A
    return float(X - sin(X) - 0.25); // B
}

float F1(float X){
    //return float(3 * pow(X,2) - 6 * X + 9); // A
    return float(1 - cos(X)); // B
}

int main() {
    float A,B,M,E,X;
    std::cout << std::setprecision(10) << std::fixed;
    std::cout << "Enter the ends of the original gap:";
    std::cin >> A >> B;
    std::cout << "Enter the accuracy:";
    std::cin >> E;
    std::cout << "Enter the parameter M:";
    std::cin >> M;
    std::cout << "Enter the initial approximation:";
    std::cin >> X;
    std::cout << std::endl;

    while (std::abs(F(X))/M>E){
        std::cout << "\tX\t" << X <<"\tFunction:\t"<< std::abs(F(X)) << "\tDerivative:\t" << std::abs(F1(X)) << "\tabs(F/M)\t" << std::abs(F(X)/M) << std::endl;
        X = X - F(X) / F1(X);
    }
    std::cout << "\tX\t" << X <<"\tFunction:\t"<< std::abs(F(X)) << "\tDerivative:\t" << std::abs(F1(X)) << "\tabs(F/M)\t" << std::abs(F(X)/M) << std::endl;
    std::cout <<"The value of the root of the function with an accuracy of " << E << " is " << X << std::endl;
    std::cout <<"Function value F(X) = " << F(X);
    return 0;
}
