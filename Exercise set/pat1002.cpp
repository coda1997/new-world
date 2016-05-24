#include<iostream>
using std::cin;
using std::cout;
int getsum(int n){
    char intger[100];
    int getvalue, value;
    value = atoi(intger);

    
	return sum;
}
void readsum(int sum){
	int temp;
	temp = sum %10;
    if(sum!=0)
	    readsum(sum/10);
	switch(temp){
	case 1:
        cout << "yi";
	break;
	case 2:
        cout << "er";
	break;
	case 3:
        cout << "san";
	break;
	case 4:
        cout << "si";
	break;
	case 5:
        cout << "wu";
	break;
	case 6:
        cout << "liu";
	break;
	case 7:
        cout << "qi";
	break;
	case 8:
        cout << "ba";
	break;
	case 9:
        cout << "qiu";
	break;
	default:
	break;
	}
    if (sum == 0)
        return;
    cout<<" ";

	
    return;
}
int main(){
	int n;
	cin>>n;
	readsum(getsum(n));
    system("pause");
	return 0;
}