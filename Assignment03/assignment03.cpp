#include<iostream>
using std::cout;

namespace mynamespace {
    int max(int a, int b, int c) {
        int maxNumber;
        maxNumber = (a > b) ? a : b;
        maxNumber = (maxNumber > c) ? maxNumber : c;
        return maxNumber;
    }
}
int main() {
    cout<<mynamespace::max(1, 2, 3);
    system("pause");
    return 0;
}