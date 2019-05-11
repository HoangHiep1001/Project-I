#include <iostream>
#include<fstream>
#define MAX 100
using namespace std;
extern int m; // so luong thanh pho
extern int c[MAX][MAX]; // ma tran chi phi
extern bool mark[MAX]; // ma tran trang thai
extern int a[MAX]; //
extern int g; // can
extern int Cmin; // gia tri
extern int f; //do dai lo trinh
extern int f_best;
extern int a_best[MAX];


void creat_data();
void read_data();
int find_min();
bool check_dl(int v, int i);
void update();
void TRY_nc(int i);
void TRY_vc(int i);
void printSolution();
