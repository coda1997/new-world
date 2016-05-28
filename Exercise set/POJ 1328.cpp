#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	double left,right;
}p[2010],temp;

bool operator <(point a,point b){
	return a.left<b.left;
}

int main(){
	int r = 0;
	int cases = 0;
	int islandNum = 0;
	while(cin>>islandNum>>r&&(islandNum||r)){
		bool flag = false;
		for(int i = 0;i<islandNum;i++){
			double a,b;
			cin>>a>>b;
			if(fabs(b)>r)
				flag = true;
			else{
				p[i].left = a*1.0-sqrt(r*r-b*b);
				p[i].right = a*1.0+sqrt(r*r-b*b);
			}
		}
		cout<<"Case"<<++cases<<":";

		if(flag)
			cout<<-1<<endl;
		else{
            int countt = 1;
			sort(p,p+islandNum);
			temp = p[0];
			
			for(int i = 1;i<islandNum;i++){
				if(p[i].left>temp.right){
					countt++;
					temp = p[i];
				}
				else if (p[i].right<temp.right)
					temp = p[i];
			}
			cout<<countt<<endl;
		}
	}
    return 0;
}