#include"travel.h"


void creat_data()
{
    ofstream fileout;
    fileout.open("dulich.txt",ios_base::out);
    fileout<<m<<"\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==j)
            {
                fileout<<0<<" ";
            }
            else
            {
                fileout<< 2+ rand() % 100<<" ";
            }

        }
        fileout<<"\n";
    }
    fileout.close();
}
void read_data()
{
    ifstream filein;
    filein.open("dulich.txt",ios_base::in);
    filein>>m;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            filein>>c[i][j];
        }
    }
    filein.close();
}
int find_min()
{
    int min = c[0][1];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if((c[i][j]>min)&&c[i][j]!=0)
                min = c[i][j];
        }
    }
    return min;
}
bool check_dl(int v, int i)
{
    return !mark[v];
}
void update()
{
    if(f + c[a[m-2]][a[m-1]] > f_best)
    {
        f_best = f + c[a[m-2]][a[m-1]];
        for(int i = 0; i < m; i++)
            a_best[i] = a[i];
    }
}
void TRY_nc(int i) // thu gia tri cua x[i]
{
    for(int v = 1; v <= m-1; v++)
    {
        if(check_dl(v,i))
        {
            a[i] = v;
            mark[v] = true;
            f = f + c[a[i-1]][a[i]];
            if(i == m-1)
            {
                update();
            }
            else
            {
                g = f + (m-i+1)*Cmin;
                if(g>f_best)
                    TRY_nc(i+1);
            }
            f = f - c[a[i-1]][a[i]];
            mark[v] = false;
        }
    }
}
void TRY_vc(int i)
{
    for(int v = 1; v <= m-1; v++)
    {
        if(check_dl(v,i))
        {
            a[i] = v;
            mark[v] = true;
            f = f + c[a[i-1]][a[i]];
            if(i == m-1)
            {
                update();
            }
            else
            {
                TRY_vc(i+1);
            }
            f = f - c[a[i-1]][a[i]];
            mark[v] = false;
        }
    }
}
void printSolution()
{
    if(m==1)
        cout<<"\nChi phi di lai la: 0"<<endl;
    else
    {
        for(int i = 0; i < m-1; i++)
        {
            cout<<a_best[i]<<" -> ";
        }
        cout<<a_best[m-1];
        cout<<"\nKhoang cach phai di la:"<<f_best<<endl;
    }
}
