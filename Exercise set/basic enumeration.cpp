#include<iostream>
#include<cstdio>
using namespace std;
//arrays to input the arrays needed
// int length to store the result arrays length
//

void getarrays(int *arrays, int start, const int size, int *result, const int length) {

    for (int i = start; i < (size - length + 1); i++) {
        result[length - 1] = i;

        if (length - 1 == 0) {
            for (int n = 0; n < length; n++) {
                printf("%d\t",arrays[result[n]]);
            }
            printf("\n");
        }
        else{
            getarrays(arrays, i+1, size, result, length - 1);
        }
    }
}



int main() {
    int arrays[] = { 1,2,3,4,5,6 };
    const int num = 4;
    int result[num];

    getarrays(arrays,0,sizeof (arrays)/sizeof(int),result,num);
    system("pause");

    return 0;
}