#include<iostream>
using namespace std;
class min {
    int x, y,z;
    int a[2];
    min();
    min(int a, int b) :x(a), y(b) {
    };
public:
    void print() {
        int a = 0;
        int b = 0;
        cout << x + y;

    }

};
int main() {
    cout << sizeof(min) << endl;
   /* int p[3];
    std::cout << sizeof(p) << endl;
    int* p2;
    std::cout << sizeof(p2) << endl;
    int *p3;
    std::cout << sizeof(min) << endl;
    */
    system("pause");
    return 0;
}

