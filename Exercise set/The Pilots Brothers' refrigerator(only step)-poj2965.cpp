#include<iostream>
using namespace std;
bool refrigerator[6][6]={false};
bool flag;
int deep;
int step;
bool check_all(void){
	int i,j;
	for(i=1;i<5;i++){
		for(j=1;j<5;j++){
			if(refrigerator[i][j] ==false)
			    return false;
		}
	}
	return true;
}

void open(int row,int col){
	refrigerator[row][col] = !refrigerator[row][col];
	for(int i = 1;i<5;i++)
		refrigerator[i][col] = !refrigerator[i][col];
	for(int j = 1;j<5;j++)
		refrigerator[row][j] = !refrigerator[row][j];
}


void dfs(int row,int col,int deep){
	if(deep==step){
		flag = check_all();
		return;
	}
	if(flag||col==5)
		return;
	open(row,col);
	if(col<4)
		dfs(row,col+1,deep+1);
	else
		dfs(row+1,col-3,deep+1);
	open(row,col);
	if(col<4)
		dfs(row,col+1,deep);
	else
		dfs(row+1,col-3,deep);
	return;
}

int main(){
	char temp;
	int i,j;
	for (i=1;i<5;i++){
		for (j=1;j<5;j++){
			cin>>temp;
			if(temp=='-')
				refrigerator[i][j]=true;
		}
			
	}
	for(step=0;step<17;step++){
		dfs(1,1,0);
		if(flag)
			break;
	}
	if(flag)
		cout<<step;
	else
		cout<<"impossible";
    system("pause");
    return 0;
	
}