#include<iostream>
#define MAXSIZE 20// represented with the array length
#define ERROR 0
#define OK 1
typedef int ElemType;// the type can be changed by replacing the 'int'
typedef struct {
    ElemType *data;
    int length;
}sqList;//sqList 是一个数据类型而不是一个实例对象

void InitList(sqList & L, int n) {
    L.length = n ;
    L.data = new ElemType[MAXSIZE];
    if (L.data == 0) {
        std::cout << "the list is null" << std::endl;
    }
}
void setList(sqList &L,int n) {
    ElemType i = 2;
    for (int i = 0; i < n; i++)
        L.data[i] = i;
}
ElemType getElem(sqList &L, int getn) {
    if (getn > L.length)
        return 0;
    return L.data[getn - 1];
}
ElemType InsertList(sqList &L,int n,ElemType e) {
    if (n<1 || n>L.length + 1)
        return ERROR;
    if (L.length == MAXSIZE)
        return ERROR;
    if (n != L.length + 1) {
        for (int k = L.length; k >= n; k--)
            L.data[k] = L.data[k - 1];
    }
    L.data[n - 1] = e;
    L.length++;
    return OK;
}
ElemType deleteList(sqList L, int n) {
    if (n<1 || n>L.length + 1||L.length==0)
        return ERROR;
    if (n < L.length) {
        for (int k = n; k < L.length; k++)
            L.data[k - 1] = L.data[k];
    }
    L.length--;
    return OK;
}


int main() {
    sqList L;
    InitList(L, 10);
    setList(L, 10);
    std::cout << getElem(L, 3)<< std::endl;
    std::cout << InsertList(L,3,5) << std::endl;
    std::cout << getElem(L, 3) << std::endl;
    std::cout << deleteList(L, 3) << std::endl;
    std::cout << getElem(L, 3) << std::endl;

    system("pause");
    return 0;
}