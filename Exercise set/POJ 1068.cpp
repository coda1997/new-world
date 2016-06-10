#include<iostream>
using namespace std;
void set_s(int *s,int* p,int len_p){
	int start =0;
	for (int i=0;i<len_p;i++){
		int temp = p[i];
		if(i==0){
			for(int n = 0;n<p[i];n++){
                s[start + n] = 0;
			}
            s[start + p[i] ] = 1;
            start = start + p[i]+1;
		}else{
			for(int n = 0;n<p[i]-p[i-1];n++){
				s[start+n] = 0;
			}
			s[start+p[i]-p[i-1]] = 1;
			start = start +p[i]-p[i-1]+1;
		}
	}
	return;
}


int main(){
    int s[40] = {-1};
	int p[20] = {0};
	int len_p;
	int cases;
	cin>>cases;
	while(cin>>len_p){
		for(int i = 0;i<len_p;i++)
			cin>>p[i];
		set_s(s,p,len_p);
		int count;
		for(int i=0;i<40;i++){
            if (s[i] == -1)
                break;
			if(s[i]==1){
				count =2;
				for(int j = i-1;;j--){
					if(s[j]==0){
						s[i]=s[j] = 2;
						break;
					}else{
						count++;
					}
					
				}
                cout << count / 2 << " ";

			}
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}