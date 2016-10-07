#include"Polynomial.h"
#include<iostream>

int main() {
    Polynomial ah, bh, ch;
    int exp;
    float coef;
    cout << "please enter exp(from small one to lager) and the corresponding coef of ah on the screen, you can enter 0 0 to finish" << endl;
    while (cin >> exp >> coef) {
        if (coef == 0 && exp == 0)
            break;
        ah.inputPoly(exp, coef);
    }
    cout << "please enter exp(from small one to lager) and the corresponding coef of bh on the screen, you can enter 0 0 to finish" << endl;
    while (cin >> exp >> coef) {
        if (coef == 0 && exp == 0)
            break;
        bh.inputPoly(exp, coef);
    }
    ch = ah*bh;
    cout << "ah*bh equals : [coef,exp]" << endl;
    ch.outputPoly();

    //ah.inputPoly(1,1);
    //ah.inputPoly(2, 2);
    //bh.inputPoly(1, 1);
    //bh.inputPoly(2, 2);
    //ch = ah*bh;
    //ah.outputPoly();
    //bh.outputPoly();
    //ch.outputPoly();
    system("pause");
}