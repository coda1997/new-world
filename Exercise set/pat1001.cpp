#include<iostream>
using namespace std;
int step;
void cutNum(int n){
	if(n==1)
		return;
	step++;

	if(n%2==0)
		cutNum(n/2);
	else
		cutNum((3*n+1)/2);
	return;
}
int main(){
	int temp;
	cin>>temp;
	cutNum(temp);
	cout<<step;
	
}