#include<iostream>
using namespace std;
void binaryOut(char c) {
    unsigned char tmp = 0x80;

    for (int i = 0; i<8; i++) {

        if (c&tmp)

            cout << 1;

        else

            cout << 0;

        tmp >>= 1;

    }

}
void displayInBinary(void *data, int len) {
    for (int i = len - 1; i >= 0; i--) {
        binaryOut(*((char*)data + i));
    }
    cout << endl;
}
int main() {
    char c = 'b';
    short n = 257;
    float f = 1.0f;
    displayInBinary(&c, sizeof(c));
    displayInBinary(&n, sizeof(n));
    displayInBinary(&f, sizeof(f));
    system("pause");
    return 0;
}