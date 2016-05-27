#include<iostream>
double **allocMatrix(int n);
void releaseMatrix(double **m);
int main(){
    int size;
    std::cin >> size;
    double** Matirx = allocMatrix(size);
    releaseMatrix(Matirx);
    system("pause");
	return 0;
	
}
double** allocMatrix(const int n){
    double **p = new double*[n];
	for(int i=0;i<n;i++)
		p[i] = new double[n];
	return p;
}
void releaseMatrix(double** m){
    for (int i = 0; i < _msize(m) / sizeof(m); i++)
        delete[] m[i];
    delete[] m;
}