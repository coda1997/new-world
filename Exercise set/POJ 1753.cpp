#include<iostream>
using std::cout;
int all_whiteOr_all_black(int *arr,int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1])
            return 0;
    }
    return 1;
}
void change(int *arr,int changeNum) {//to change the color, it is right
    arr[changeNum] = !arr[changeNum];
    int x = changeNum / 4;
    int y = changeNum % 4;
    if (x > 0) arr[changeNum - 4] = !arr[changeNum - 4];
    if (x < 4)arr[changeNum + 4] = !arr[changeNum + 4];
    if (y > 0)arr[changeNum - 1] = !arr[changeNum - 1];
    if (y < 3)arr[changeNum + 1] = !arr[changeNum + 1];
}

int arrEnum(int *arr2, int *result,const int length, int start,int *arr) {
    for (int i = start; i < 16 - length + 1; i++) {
        result[i] = i;
        int* copy_arr = new int[16];
        for (int n = 0; n < 16; n++)
            copy_arr[n] = arr[n];
        if (length - 1 == 0) {//make  a cpoy to arr the new new_arr
            int *new_arr = new int[length];
            for (int i = 0; i < length; i++) {
                new_arr[i] = arr2[result[i]];
            }
            for (int i = 0; i < length; i++) {
                change(copy_arr, new_arr[i]);
            }
            if (all_whiteOr_all_black(copy_arr, 16)==1) {
                free(new_arr);
                return length;
            }
            else
            {
                free(new_arr);
            }
        }
        else {
            arrEnum(arr2, result, length - 1, i+1,arr);

        }
        free(copy_arr);
    }
    return 0;
}

int main() {
    int arr[] = { 0,1,1,0,0,0,1,0,0,1,1,0,0,1,1,1};
    int arr2[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int reu[16];
    int size = 16;
    int step = 0;
    if (all_whiteOr_all_black(arr, size)) {//length ==0
        cout << "0 step";
        system("pause");

        return 0;
    }
    for (int i = 1; i < 17; i++) {//i==length

        step = arrEnum(arr2, reu, i, 0, arr);
    }
    if (step != 0)
        cout << step << " step" << std::endl;
    else
        cout << "impossible !";
    system("pause");
    return 0;
}
//forget to make a copy for arr itself because of the change 