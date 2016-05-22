#include<iostream>
using namespace std;
bool refrigerator[6][6]={false};
bool flag;
int deep;
int step;
int cols[16] = {0};
int rows[16] = {0};
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

void open(const int row,const int col){
	refrigerator[row][col] = !refrigerator[row][col];
	for(int i = 1;i<5;i++)
		refrigerator[i][col] = !refrigerator[i][col];
	for(int j = 1;j<5;j++)
		refrigerator[row][j] = !refrigerator[row][j];
}


void dfs(int row,int col,const int deep){
    if (deep >= 17||row>5||col>5)
        return;

	if(deep==step){
		flag = check_all();
		return;
	}
	if(flag||col==5)
		return;
    if (deep <=step) {
        cols[deep ] = col;
        rows[deep ] = row;
    }
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
            if (temp == '-') {
                refrigerator[i][j] = true;
            }
		}
			
	}
	for(step=0;step<17;step++){
		dfs(1,1,0);
		if(flag)
			break;
	}
	if(flag){
		cout<<step<<endl;
		for(int i = 0;i<step;i++)
			cout<<rows[i]<<" "<<cols[i]<<endl;
	}
	else
		cout<<"impossible";
    system("pause");
    return 0;
	
}