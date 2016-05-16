#include<iostream>
using std::cout;
class Complex {
    double real;
    double image;
public:
    void setValue(double r, double i);
    void addValue(double r, double i); // a=a+b 
    void multiply(double r, double i); // a=a*b
    void displayMessage();
};
void Complex::setValue(double r, double i) {
    real = r;
    image = i;
}
void Complex::addValue(double r, double i) {
    real += r;
    image += i;
} // a=a+b 
void Complex::multiply(double r, double i) {
    double temp = real;
    real = temp*r - image*i;
    image = temp*i + image*r;
} // a=a*b
void Complex::displayMessage() {
    cout << real << "+" << image << "i" << std::endl;
}
int main() {
    Complex operation;
    operation.setValue(1,3);
    operation.addValue(0, 4);//let 1+3i adds 4i
    operation.displayMessage();
    operation.setValue(1, 3);
    operation.multiply(0, 4);//let 1+3i mutiply 4i
    operation.displayMessage();
    system("pause");
    return 0;
}