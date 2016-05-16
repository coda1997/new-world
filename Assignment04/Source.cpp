#include<iostream>
#include"test01.h"
using namespace std;

int main() {
    int val, size;
    int arrays[10] = { 0,1,2,3,4,5,6,7,8,9 };
    size = 10;
    val = 2;
    cout<<find(val,arrays,size);
    system("pause");
    return 0;
}