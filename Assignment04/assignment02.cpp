#include<iostream>
#include"test02.h"
using namespace std;

int main() {
    employes<int> a1(1,4)  ;//create a object with int type
    cout << a1.sumscore() << endl;;
    employes<double> a2(2.3, 6);
    cout << a2.sumscore();

    system("pause");
    return 0;
}