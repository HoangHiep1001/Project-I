#include"queen.h"


bool check(int v, int k)
{
    for(int i = 1; i < k; i++)
    {
        if(x[i] == v)
            return false;
        if(x[i] + i == v + k)
            return false;
        if(x[i] - i == v - k)
            return false;
    }
    return true;
}
void printS()
{
    dem++;
    cout<<"\nLoi giai thu "<<dem<<":"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==x[j])
            {
                cout<<"|X";
            }
            else
                cout<<"|O";
            if(j==n)
                cout<<"|";
        }
        cout<<endl;
    }
}
void TRY(int k) // thu gia tri cho x[k] khj da biet x[1,..,k-1]
{
    for(int v = 1; v <= n; v++)
    {
        if(check(v,k))
        {
            x[k] = v;
            if(k == n)
            {
                printS();
                system("pause");
            }
            else
            {
                TRY(k+1);
            }
        }
    }
}
