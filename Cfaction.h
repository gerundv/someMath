//
// Created by gerun on 30.03.2022.
//

#ifndef PROBATION_CFACTION_H
#define PROBATION_CFACTION_H

class Cfaction{
public:

    Cfaction(){
        x = 0;
        y = 0;
    }

    Cfaction(int value){
        x = value;
        y = 1;
    }

    Cfaction(int x, int y){
        this->x = x;
        this->y = y;
    }

    Cfaction(const Cfaction &other){
        this->x = other.x;
        this->y = other.y;
    }

    ~Cfaction(){

    }

    operator double() const {
        return x / double(y);
    }

    int operator() (int valueX,int valueY){
        this->x = valueX;
        this->y = valueY;
    }

    int operator() (int valueX){
        this->x = valueX;
        this->y = 1;
    }

    Cfaction &operator ++ (){
        this->x += this->y;
        return *this;
    }

    Cfaction &operator ++ (int value){
        Cfaction temp(*this);
        this->x += this->y;
        return *this;
    }

    Cfaction &operator -- (){
        this->x -= this->y;
        return *this;
    }

    Cfaction &operator -- (int value){
        Cfaction temp(*this);
        this->x -= this->y;
        return *this;
    }

    Cfaction &operator = (const Cfaction &other){
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    Cfaction operator + (const Cfaction &other){
        Cfaction temp;
        if (this->y != other.y){
            temp.x = this->x * other.y + other.x * this->y;
            temp.y = this->y * other.y;
        }
        else {
            temp.y = this->y;
            temp.x = this->x + other.x;
        }
        return temp;
    }

    Cfaction operator - (const Cfaction &other){
        Cfaction temp;
        if (this->y != other.y){
            temp.y = this->y * other.y;
            temp.x = this->x * other.y - other.x * this->y;
        }
        else {
            temp.y = this->y;
            temp.x = this->x - other.x;
        }
        return temp;
    }

    Cfaction operator * (const Cfaction &other){
        Cfaction temp;
        temp.x = this->x * other.x;
        temp.y = this->y * other.y;
        return temp;
    }

    Cfaction operator / (const Cfaction &other){
        Cfaction temp;
        temp.x = this->x * other.y;
        temp.y = this->y * other.x;
        return temp;
    }

    Cfaction &operator += (const Cfaction &other){
        if (this->y != other.y){
            this->x = this->x * other.y + other.x * this->y;
            this->y = this->y * other.y;
        }
        else {
            this->y = this->y;
            this->x = this->x + other.x;
        }
        return *this;
    }

    Cfaction &operator -= (const Cfaction &other){
        if (this->y != other.y){
            this->y = this->y * other.y;
            this->x = this->x * other.y - other.x * this->y;
        }
        else {
            this->y = this->y;
            this->x = this->x - other.x;
        }
        return *this;
    }

    Cfaction &operator *= (const Cfaction &other){
        this->x = this->x * other.x;
        this->y = this->y * other.y;
        return *this;
    }

    Cfaction &operator /= (const Cfaction &other){
        this->x = this->x * other.y;
        this->y = this->y * other.x;
        return *this;
    }

    bool operator == (const Cfaction &other){
        return (double(this->x) / double(this->y) == double(other.x) / double(other.y));
    }

    bool operator != (const Cfaction &other){
        return (double(this->x) / double(this->y) != double(other.x) / double(other.y));
    }

    bool operator > (const Cfaction &other){
        return (double(this->x) / double(this->y) > double(other.x) / double(other.y));
    }

    bool operator < (const Cfaction &other){
        return (double(this->x) / double(this->y) < double(other.x) / double(other.y));
    }

    bool operator >= (const Cfaction &other){
        return (double(this->x) / double(this->y) >= double(other.x) / double(other.y));
    }

    bool operator <= (const Cfaction &other){
        return (double(this->x) / double(this->y) <= double(other.x) / double(other.y));
    }

    int numerator(){
        return this->x;
    }

    int denominator(){
        return this->y;
    }

private:
    int x; // numerator
    int y; // denominator
};

#endif //PROBATION_CFACTION_H
