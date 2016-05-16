#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int year =0;
    ifstream file1("input.txt");
    ofstream file2("output.txt");
    if (!file1.eof())
        file1 >> year;
    else
        cout << "there is some error opening file1";
    if (year % 4 == 0 && year %100 != 0 || year % 400 == 0)
        file2 << year << "  is a leap year" << endl;
    else   file2 << year << " is not a leap year" << endl;
    return 0;
    system("pause");
}

