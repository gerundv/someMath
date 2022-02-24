#include <iostream>
#include <cmath>
#include <iomanip>
//program HORD

float F(float X){
    return X*cos(X)-0.5;
}
int main(){
    float A,B,M,E,X;
    std::cout << "Enter the ends of the original gap: ";
    std::cin >> A >> B;
    std::cout << "Enter the accuracy: ";
    std::cin >> E;
    std::cout << "Enter the parameter M: ";
    std::cin >> M;
    std::cout << "Enter the initial approximation: ";
    std::cin >> X;

    if (X=B) {
        B = A;
        A = X;}
    std::cout.precision(10);
    std::cout << std::setw(15) << std::left << "X" << std::setw(15) << std::left << "F(X)" << std::setw(15) << std::left << "|F(X)|/M" << std::endl;
    while(std::abs(F(X))/M > E) {
        std::cout << std::fixed << std::setw(15) << std::left << X << std::setw(15) << std::left << F(X) << std::setw(15) << std::left << std::abs(F(X))/M << "\n";
        X = X - F(X)/(F(X) - F(B)) * (X - B);
    }
    std::cout << std::fixed << std::setw(15) << std::left << X << std::setw(15) << std::left << F(X) << std::setw(15) << std::left << std::abs(F(X))/M << "\n";
    return 0;
}