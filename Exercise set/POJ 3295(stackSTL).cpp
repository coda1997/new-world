#include<iostream>
#include<stack>
using namespace std;

int pp,qq,rr,ss,tt;
stack<int> s;

bool isvariables(char ch);
void operators(char op);

int main(){
	char wff[101];
	while(cin>>wff&&wff[0]!='0'){
		int len = strlen(wff);
		
		bool flag = true;
		for (pp=0;pp<=1;pp++){
			for(qq=0;qq<=1;qq++){
				for(rr=0;rr<=1;rr++){
					for(ss=0;ss<=1;ss++){
						for(tt=0;tt<=1;tt++){
							for(int pw=len-1;pw>=0;pw--){
								if(!isvariables(wff[pw]))
									operators(wff[pw]);
								
							}
							int ans = s.top();
							s.pop();
							if(!ans){
								flag = false;
								break;
							}
							
						}
						if(!flag)
							break;
					}
					if(!flag)
						break;
				}
				if(!flag)
					break;
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<"tautology"<<endl;
		else
			cout<<"not"<<endl;
	}
	return 0;
}

bool isvariables(char ch){
	switch(ch){
		case 'p':s.push(pp);return true;
		case 'q':s.push(qq);return true;
		case 'r':s.push(rr);return true;
		case 's':s.push(ss);return true;
		case 't':s.push(tt);return true;
	}
	return false;
}

void operators(char op){
	switch(op){
		case 'K':{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(x&&y);
			break;
		}
		case 'A':{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(x||y);
			break;
		}		
		case 'N':{
			int x = s.top();
			s.pop();
			s.push(!x);
			break;
		}		
		case 'C':{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push((!x)||y);
			break;
		}		
		case 'E':{
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push((x&&y)||((!x)&&(!y)));
			break;
		}		
	}
	return ;
}