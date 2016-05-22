#include<iostream>
using namespace std;
int p[5][5]={0};
int main(void)
{
    char c;
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            cin >> c;
            if (c == '+')
            {
                for (int k = 1; k <= 4; k++)
                {
                    p[i][k]++;
                    p[k][j]++;
                }
                p[i][j]--;
            }
        }
    int sum = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            sum += p[i][j]%2;
    cout << sum << endl;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if  (p[i][j]%2)
                cout << i << " " << j << endl;
    return 0;
}