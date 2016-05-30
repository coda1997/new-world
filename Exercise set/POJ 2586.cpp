#include<iostream>
using namespace std;
int check(int s,int d){
	if(4*s<d)
		return 10 * s - 2 * d;
	
	else if(3*s<2*d)
		return 8 * s - 4 * d;
	
	else if(2*s<3*d)
		return 6 * s - 6 * d;
	
	else if(s<4*d)
		return 3 * s - 9 * d;
    else
        return -12 * d;
}
int main(){
	int s,d;
    int result;
    while (cin >> s >> d) {
        result =check(s, d);
        if (result < 0)
            cout << "Deficit" << endl;
        else
            cout << result << endl;
    }
    system("pause");
	return 0;
}