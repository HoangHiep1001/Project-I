#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
#define MAX 100
extern int dem;
extern int x[MAX];
extern int n;
// kiem tra cac quan hau co an nhau khong?
bool check(int v, int k);
// in ket qua
void printS();
//in ra file .html
void result();
// thu lan luot cac truong hop
void TRY(int k);

#endif // QUEEN_H_INCLUDED
