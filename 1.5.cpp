#include <iostream>
#include <cmath>
#include <iomanip>
//program HORD

double F(double X){
    //return X*cos(X)-0.5;
    return std::pow(2,X) + std::pow(2,-X) - 3;
}
int main(){
    double A,B,M,E,X;
    std::cout << "Enter the ends of the original gap: ";
    std::cin >> A >> B;
    std::cout << "Enter the accuracy: ";
    std::cin >> E;
    std::cout << "Enter the parameter M: ";
    std::cin >> M;
    std::cout << "Enter the initial approximation: ";
    std::cin >> X;

    std::cout << std::endl;

    if (X==B) {
        B = A;
        A = X;}
    std::cout.precision(10);
    std::cout << std::setw(15) << std::left << "X" << std::setw(15) << std::left << "F(X)" << std::setw(15) << std::left << "|F(X)|/M" << std::endl;
    while(std::abs(F(X))/M > E) {
        std::cout << std::fixed << std::setw(15) << std::left << X << std::setw(15) << std::left << F(X) << std::setw(15) << std::left << std::abs(F(X))/M << "\n";
        X = X - F(X)/(F(X) - F(B)) * (X - B);
    }
    std::cout << std::fixed << std::setw(15) << std::left << X << std::setw(15) << std::left << F(X) << std::setw(15) << std::left << std::abs(F(X))/M << "\n";

    std::cout << "F(X) = " << F(X);
    return 0;
}