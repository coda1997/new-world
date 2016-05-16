#include<iostream>
#include"Triangle.h"
using std::cout;
using std::endl;


int main() {
    Triangle a(1,2,4);
    Triangle b(2, 4, 6);
    if (a > b)
        cout << "the area of triangle a is larger than that of triangle b";
    else
        cout << "the area of triangle b is larger than that of triangle a";
    system("pause");
}

Triangle::Triangle() {
    cout << "please enter the side length of a triangle";
}
Triangle::Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

double Triangle::Area(){
    double p = (a + b + c) / 2;
    return p*(p - a)*(p - b)*(p - c);
}

bool operator>(Triangle a,Triangle b) {
    return a.Area() > b.Area();
}