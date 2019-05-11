#include"queen.h"
#include"travel.h"
// queen
int dem;
int x[MAX];// modelling
int n;
// travel
int m; // so luong dinh
int c[MAX][MAX]; // ma tran chi phi
bool mark[MAX]; // ma tran trang thai
int g; // can duoi
int Cmin; // gia tri  chi phi nho nhat
// luu thong tin lo trinh
int a[MAX];
int f;
// thong tin lo trinh tot nhat
int f_best;
int a_best[MAX];
void menu()
{
    int luachon;
    while(true)
    {
        system("cls");
        cout<<"\t\t\n\n\t\t\tBACK_TRACKING\t\t\n\n";
        cout << "\n\n\t\t========== Menu ==========\n";
        cout << "\n\t1. Bai toan quan hau";
        cout << "\n\t2. Bai toan nguoi du lich(vet can)";
        cout << "\n\t3. Bai toan nguoi du lich(nhanh va can)";
        cout << "\n\t0. Thoat";
        cout << "\n\n\t\t========== End ===========\n";
        do
        {
            cout<<"\nNhap vao lua chon: ";
            cin.clear();
            fflush(stdin);
            cin>>luachon;
            if(!cin)
                cout<<"\nBan nhap sai moi nhap lai!";
        }
        while(!cin);
        if(luachon < 0 ||luachon >3)
        {
            cout<<"\nLua chon khong hop le. Moi ban nhap lai!!";
            system("pause");
        }
        else if(luachon==1)
        {
            dem = 0;
            do
            {
                do
                {
                    cout<<"\nNhap vao kich thuoc ban co: ";
                    cin.clear();
                    fflush(stdin);
                    cin>>n;
                    if(!cin)
                        cout<<"\nBan nhap sai moi nhap lai!";
                }
                while(!cin);
                if(n<4 && n!=1)
                    cout<<"\nKhong co loi giai cho bai toan nay voi n<4 va n !=1.Moi ban nhap lai!!";
            }
            while(n<4 && n!=1);
            cout<<"\nNotes: Cac o X la cac quan hau!!";
            TRY(1);
            system("pause");
        }
        else if(luachon==2)
        {
//            do
//            {
//                cout<<"\nNhap vao so luong thanh pho: ";
//                cin.clear();
//                fflush(stdin);
//                cin>>m;
//                if(!cin)
//                    cout<<"\nBan nhap sai moi nhap lai!";
//            }
//            while(!cin);
//            creat_data();
            read_data();
            a[0]=0;
            mark[a[0]] = true;
            f = 0;
            f_best = -999999999;
            for(int v = 1; v <= n-1; v++)
                mark[v] = false;
            TRY_vc(1);
            printSolution();
            system("pause");
        }
        else if(luachon==3)
        {
//            do
//            {
//                cout<<"\nNhap vao so luong thanh pho: ";
//                cin.clear();
//                fflush(stdin);
//                cin>>m;
//                if(!cin)
//                    cout<<"\nBan nhap sai moi nhap lai!";
//            }
//            while(!cin);
//            creat_data();
            read_data();
            a[0]=0;
            mark[a[0]] = true;
            f = 0;
            f_best = -999999999;
            for(int v = 1; v <= n-1; v++)
                mark[v] = false;
            Cmin  = find_min();
            TRY_nc(1);
            printSolution();
            system("pause");
        }
        else
            break;
    }
}
int main()
{
    menu();
    return 0;
}
