#include<iostream>//need to be handle!
#include<string>
using std::cout;
using std::cin;
using std::endl;
void reverseOrder(char* str, int p, int q){
char temp;
while (p < q)
     {
         temp = str[p];
         str[p] = str[q];
         str[q] = temp;
         p++;
         q--;
     }

}
char* multiLargeNum(char* A, char* B)
{
    int m = strlen(A);
    int n = strlen(B);
    char* result = new char[m + n + 1];
    memset(result, '0', m + n);
    result[m + n] = '\0';
    reverseOrder(A, 0, m - 1);
    reverseOrder(B, 0, n - 1);

    int multiFlag; 
    int addFlag;   
    for (int i = 0; i <= n - 1; i++) 
    {
        multiFlag = 0;
        addFlag = 0;
        for (int j = 0; j <= m - 1; j++) 
        {
            int temp1 = (A[j] - 48) * (B[i] - 48) + multiFlag;
            multiFlag = temp1 / 10;
            temp1 = temp1 % 10;
            int temp2 = (result[i + j] - 48) + temp1 + addFlag;
            addFlag = temp2 / 10;
            result[i + j] = temp2 % 10 + 48;
        }
        result[i + m] += multiFlag + addFlag;
    }
    reverseOrder(result, 0, m + n - 1); 

    return result;
}

void check(char* n,char* p){
    char temp[101] = {0};
	int k = 1;
	strcpy(temp,n);
	while(strcmp(n,p)){
		strcpy(n,multiLargeNum(temp,n));
		k = k+1;
	}
	cout<<k<<endl;;
}
int main(){
    char n[101] = { 0 };
    char p[101] = { 0 };
	while(cin>>n>>p){

		check(n,p);
	}
    system("pause");
	return 0;
}