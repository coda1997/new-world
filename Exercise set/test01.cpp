#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    cout << "please enter integer numbers and enter ctrl + z to quit" << endl;
    int sum=0, x;
    while (cin >> x) {
        sum += x;
    }
    cout << "the sum of the numbers is " << sum << endl;
    system("pause");
    return 0;
}
