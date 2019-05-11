#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#define MAX 10000
using namespace std;
string book[MAX];// mang luu tru cac dong cua sach
string *key;// mang luu tru cac keyword
int n;//so luong key word
int m; //so dong cua sach
// cau truc 1 cai node dong
struct dong
{
    int value;
    struct dong *pdNext;
};
typedef struct dong NODE_DONG;
NODE_DONG *head;
// cau truc 1 cai node
struct node
{
    string key_word;;
    int so_lan_xh;
    NODE_DONG *pkey; // tro den dslk cac node dong
    struct node *pNext;
};
typedef struct node NODE;
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void khoi_tao_dslk(LIST &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE *make_node(string key,int so_lan_sh)
{
    NODE * p = new NODE;
    p->key_word=key;
    p->so_lan_xh=so_lan_sh;
    p->pkey=NULL;
    p->pNext=NULL;
    return p;
}
NODE_DONG *make_node_dong(int val)
{
    NODE_DONG *p = new NODE_DONG;
    p->value= val;
    p->pdNext=NULL;
    return p;
}
NODE_DONG *insertLast(NODE_DONG *h,NODE_DONG*q)
{
    if(h == NULL)
        return q;
    NODE_DONG* p = h;
    while(p->pdNext != NULL)
    {
        p = p->pdNext;
    }
    p->pdNext = q;
    return h;
}
void them_vao_cuoi(LIST &l,NODE *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
        //p->pkey=h;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
        //p->pkey=h;
    }
}
void read_book(int &d)
{
    d = 1;
    ifstream filein;
    string temp;
    filein.open("book.txt",ios_base::in);
    if(filein.is_open())
    {
        while(!filein.eof())
        {
            getline(filein,book[d]);
            d++;
        }
        filein.close();
    }
    else
        cout<<"\nMo file that bai! Moi ban kiem tra lai";
}
void read_key_word(int &n)
{
    int i=0;
    ifstream filein;
    filein.open("key_word.txt",ios_base::in);
    if(filein.is_open())
    {
        filein>>n;
        string temp;
        getline(filein,temp);
        key = new string[n];
        while(i<n)
        {
            getline(filein,key[i]);
            i++;
        }
        filein.close();
    }
    else
        cout<<"\nMo file that bai!Ban hay kiem tra lai.";

}
int timsolanxh(string T,string P)
{
    int x = 0;// so lan xuat hien cua xau T trong xau P
    int  m= T.size();
    int n = P.size();
    for(int i = 0; i < n; i++)
        if(P[i] == T[0])
            for(int j = 1; j < m; j++)
            {
                if(P[i + j] != T[j])
                    break;

                if(j == m -1)
                {
                    x++;
                }
            }
    return x;
}
void index_book(LIST &l,NODE_DONG *h)
{
    NODE *p;
    NODE_DONG *q;
    int xh;
    for(int i=0; i<n; i++)
    {
        xh = 0;
        for(int j=1; j<=m; j++)
        {
        if(book[j].find(key[i])!= string::npos)//while cout
        {
            xh = xh + timsolanxh(key[i],book[j]);
            q = make_node_dong(j);
            h = insertLast(h,q);
        }
        }
        p = make_node(key[i],xh);
        them_vao_cuoi(l,p);
        p->pkey=h;
        h=NULL;
    }
}
void giai_phong(LIST &l)
{
    NODE *k=NULL;
    while(l.pHead!=NULL)
    {
        k=l.pHead;
        l.pHead=l.pHead->pNext;
        delete k;

    }
}
void giai_phong_dong(NODE_DONG *h)
{
    NODE_DONG * k = NULL;
    while(h!=NULL)
    {
        k = h;
        h = h->pdNext;
        delete k;
    }
}
int main()
{

    LIST l;
    khoi_tao_dslk(l);
    NODE_DONG *h=NULL;
    read_book(m);
//    string s;
//    cout<<"\nNhap vao dong: ";
//    getline(cin,s);
    read_key_word(n);
    index_book(l,h);
        for(NODE *k=l.pHead; k!=NULL; k=k->pNext)
        {
            cout<<"\nCac tu khoa xuat hien:"<<k->key_word<<endl;
            cout<<",So lan xuat hien: "<<k->so_lan_xh<<endl;
            cout<<"Tai dong :";
        for(NODE_DONG*j=k->pkey; j!=NULL; j=j->pdNext)
            cout<<j->value<<" ";
        cout<<endl;
        }
//    ofstream fileout;
//    fileout.open("output.txt",ios_base::out);
//    fileout<<"Index book\t\t\n\n";
//    for(NODE *k=l.pHead; k!=NULL; k=k->pNext)
//    {
//        fileout<<k->key_word<<",So lan xuat hien: "<<k->so_lan_xh<<endl;
//        fileout<<"Tai dong :";
//        for(NODE_DONG*j=k->pkey; j!=NULL; j=j->pdNext)
//            fileout<<j->value<<" ";
//        fileout<<endl;
//    }
//    fileout.close();
    giai_phong(l);
    giai_phong_dong(h);
    return 0;
}
