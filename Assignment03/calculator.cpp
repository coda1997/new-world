#include<iostream>
#include<stdlib.h>
#include<cstring>
#include"calculator.h"
using std::cout;
using std::endl;
int main(int argc, char *argv[]) {
    if (argc != 4)
        cout << "You must give 4 arguments!" << endl;
    double operand1, operand2;
    char *operation;
    operand1 = atof(argv[2]);
    operand2 = atof(argv[3]);
    operation = argv[1];

    Calculator one(operand1, operand2, operation);
    cout << one.doOperation() << endl;
    return 0;
}
Calculator::Calculator(double x,double y,char* docode) {
    operand1 = x;
    operand2 = y;
    operation = docode;
}
double Calculator::doOperation() {
    if (strcmp(operation, "add") == 0) {
        return operand1 + operand2;
    }
    else if (strcmp(operation, "sub") == 0) {
        return operand1 - operand2;
    }
    else if (strcmp(operation, "mul") == 0) {
        return operand1 * operand2;
    }
    else if (strcmp(operation, "div") == 0) {
        return operand1 / operand2;
    }
    return 0;
}