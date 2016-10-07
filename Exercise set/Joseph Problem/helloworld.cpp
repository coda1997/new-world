#include<iostream>
#include"Joseph.h"
using namespace std;
int main() {
    int length;
    cout << "please input the number of all people on the ring" << endl;
    cin >> length;
    Joseph peo(length);
    //for (int i = 0; i < peo.getLength(); i++) {
    //    peo.removePeople(rand() % peo.getLength());
    //}
    int num;
    while (cin >> num) {
        
        peo.removePeople(num);
    }
    getchar();

}