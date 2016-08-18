#include<iostream>
#define MAXSIZE 20
#define ERROR 0
#define OK 1
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length = 0;//初始化的时候一定要赋值！！！
}sqlist;
ElemType setList(sqlist &L,int n,ElemType e){
	if(n<1||n>MAXSIZE)
		return ERROR;
	L.data[n-1]=e;
	L.length++;
	return OK;
}
ElemType getElem(sqlist L, int n) {
    if (n < 1 || n>L.length||L.data==0)
        return ERROR;
    return L.data[n - 1];
}
int main(){
	sqlist L;
    for (int i = 0; i < 3;i++)
        cout << setList(L, i+1, 5) << endl;
    cout << L.length << endl;
    cout << getElem(L, 3) << endl;
    system("pause");
}