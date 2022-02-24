#include <iostream>
#include <cmath>
//program ITER

float F(float X){
    return 1/(2+std::pow(X,2));
}

int main(){
    float X1,X2,E;
    std::cout << "Enter the accuracy: ";
    std::cin >> E;
    X1 = 1;
    X2 = F(X1);
    std::cout << X1 << std::endl;
    while (std::abs(X2-X1)>E){
        X1 = X2;
        std::cout << X2 << std::endl;
        X2 = F(X1);
    }
    std::cout << "Function value F(X) = " << F(X2);
    return 0;
}