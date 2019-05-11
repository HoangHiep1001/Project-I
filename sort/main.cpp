#include<bits/stdc++.h>
using namespace std;
int *a;
int n;
void creat_data_keyboard()
{
    //Nhap du lieu vao tu ban phim va kiem tra xem dung k?
    do
    {
        cout<<"\nNhap vao so phan tu mang: ";
        cin.clear();
        fflush(stdin);
        cin>>n;
        if(!cin)
            cout<<"\nBan nhap sai moi nhap lai!";
    }
    while(!cin);

    a = new int [n];
    for(int i=0; i<n; i++)
    {
        a[i] = rand() % 1000;
    }
}
void creat_data_file()
{
    //Nhap du lieu tu file
    do
    {
        cout<<"\nNhap vao so phan tu mang: ";
        cin.clear();
        fflush(stdin);
        cin>>n;
        if(!cin)
            cout<<"\nBan nhap sai moi nhap lai!";
    }
    while(!cin);
    ofstream fileout;
    fileout.open("input.txt",ios_base::out);
    fileout << n;
    fileout << "\n";
    for(int i=0; i<n; i++)
    {
        fileout<<rand()%1000<<" ";
    }
    fileout.close();
}

void read_data()
{
    ifstream filein;
    filein.open("input.txt",ios_base::in);
    filein>>n;
    string temp;
    getline(filein,temp);
    a = new int [n];
    for(int i=0; i<n; i++)
    {
        filein>>a[i];
    }

    filein.close();
}
void print_to_file()
{
    ofstream fileout;
    fileout.open("output.txt",ios_base::out);
    fileout<<"So phan tu cua mang la: "<<n;
    fileout<<"\nDay sau khi da sap xep la: "<<endl;
    for(int i = 0; i<n; i++)
        fileout<<a[i]<<" ";
    fileout.close();
}

void xuat_mang()
{
    cout<<"\nMang sau khi da sap xep la:"<<endl;
    for(int i= 0; i < n; i++)
    {
        cout<<setw(5)<<left<<a[i];
    }
    cout<<endl;
}
void Bubble_Sort(int l,int r)
{
    for (int i = l; i < n-1; i++)
        for (int j = l; j < n-i-1; j++)
            if (a[j] < a[j+1])
                swap(a[j],a[j+1]);
}
//bubble sort co bien swapped de tranh truong hop day da sap xep
void bubblesort(int l,int r)
{
    bool swapped;
    do
    {
        swapped = false;
        for(int i=l; i<=r-1; i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                swapped = true;
            }
        }
    }
    while(swapped);
}
// quick sort
int partition(int l, int r)
{
    int key = a[r];// khoa
    int i = l-1;
    for (int j=l; j<r; j++)
        if (a[j] <= key)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[i+1], a[r]);
    return i + 1;
}
void Quicksort(int l, int r)
{
    if(l<r)
    {
        int tru = partition(l,r);
        if(l<tru)
        {
            Quicksort(l,tru-1);
        }
        if(tru<r)
        {
            Quicksort(tru+1,r);
        }
    }
}
// quicksort random khoa
void Quick_Sort(int left,int right)
{
    int i =left;
    int j = right;
    int tru = a[left + rand()%(right -left)];
    while(i<=j)
    {
        while(a[i]>tru)
            i++;
        while(a[j]<tru)
            j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(left<j)
        Quick_Sort(left,j);
    if(i<right)
        Quick_Sort(i,right);
}
void Build_Heapfy(int n,int i)
{
    int Left = 2*i +1;
    int Right = 2*i +2;
    int Largest;
    if(Left<n && a[Left]<a[i])
    {
        Largest = Left;
    }
    else
        Largest = i;
    if(Right<n&& a[Right]<a[Largest])
        Largest = Right;
    if(i!=Largest)
    {
        swap(a[i],a[Largest]);
        Build_Heapfy(n,Largest);

    }

}

void Build()
{
    for(int i=n/2-1; i>=0; i--)
        Build_Heapfy(n,i);
}
void Heap_Sort()
{
    Build();
    for(int i=n-1; i>0; i--)
    {
        swap(a[0],a[i]);
        Build_Heapfy(i,0);
    }
}
void Merge(int left,int right)
{
    int *temp; // Khoi tao mang tam de sap xep
    int mid =(right + left)/2;
    int i = left; // Vi tri phan tu dau tien cua mang con ben trai
    int j = mid + 1; // Vi tri phan tu dau tien cua mang con ben phai

    temp = new int[right - left + 1];

    for (int k = 0; k <= right - left; k++)
    {
        if (a[i] > a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        if (i == mid + 1)
        {
            while (j <= right)
            {
                k++;
                temp[k] = a[j];
                j++;
            }
            break;
        }

        if (j == right + 1)
        {
            while (i <= mid)
            {
                k++;
                temp[k] = a[i];
                i++;
            }
            break;
        }
    }

    for (int k = 0; k <= right - left; k++)
        a[left + k] = temp[k];
    delete temp;
}
void MergeSort(int left, int right)
{
    if (right > left)
    {
        int mid;
        mid = (left + right ) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left,right);
    }
}
void menu()
{
    int luachon;
    while(true)
    {
        system("cls");
        cout<<"\t\t\n\n\t\t\tSORT AGORITHMS\t\t\n\n";
        cout << "\n\n\t\t========== Menu ==========\n";
        cout << "\n\t1. Creat Data";
        cout << "\n\t2. Lay du lieu tu file";
        cout << "\n\t3. Quicksort";
        cout << "\n\t4. Heap_Sort";
        cout << "\n\t5. Bubble Sort";
        cout << "\n\t6. Merge Sort";
        cout << "\n\t7. Da luong Bubble_sort";
        cout << "\n\t8. Da luong Quicksort";
        cout << "\n\t9. Xuat mang da sap xep";
        cout << "\n\t10. In mang da sap xep vao file";
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
        if(luachon < 0 ||luachon > 10)
        {
            cout<<"\nLua chon khong hop le. Moi ban nhap lai!!";
            system("pause");
        }
        else if(luachon==1)
        {
            creat_data_keyboard();
        }
        else if(luachon==2)
        {
            creat_data_file();
            read_data();
        }
        else if(luachon==3)
        {
            cout<<"\nMang ban dau la:"<<endl;
            for(int i= 0; i < n; i++)
            {
                cout<<setw(5)<<left<<a[i];
            }
            cout<<endl;
            Quick_Sort(0,n-1);
            xuat_mang();
            //clock_t finish = clock();
            //printf("\nThoi gian thuc hien la: %.20f (s)\n",(double)((finish - start)/CLOCKS_PER_SEC));
            //system("pause");
        }
        else if(luachon==4)
        {
            cout<<"\nMang ban dau la:"<<endl;
            for(int i= 0; i < n; i++)
            {
                cout<<setw(5)<<left<<a[i];
            }
            cout<<endl;
            Heap_Sort();
            xuat_mang();
            system("pause");
            //clock_t finish = clock();
            //printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)((finish - start)/CLOCKS_PER_SEC));
            system("pause");
        }
        else if(luachon==5)
        {
            cout<<"\nMang ban dau la:"<<endl;
            for(int i= 0; i < n; i++)
            {
                cout<<setw(5)<<left<<a[i];
            }
            cout<<endl;
            clock_t start = clock();
            Bubble_Sort(0,n-1);
            xuat_mang();
            clock_t finish = clock();
            printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)((finish - start)/CLOCKS_PER_SEC));
            system("pause");
        }
        else if(luachon==6)
        {
            cout<<"\nMang ban dau la:"<<endl;
            for(int i= 0; i < n; i++)
            {
                cout<<setw(5)<<left<<a[i];
            }
            cout<<endl;
            MergeSort(0,n-1);
            xuat_mang();
            //clock_t finish = clock();
            //printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)(finish - start)/CLOCKS_PER_SEC);
            system("pause");
        }
        else if(luachon==7)
        {
//            cout<<"\nMang ban dau la:"<<endl;
//            for(int i= 0; i < n; i++)
//            {
//                cout<<setw(5)<<left<<a[i];
//            }
//            cout<<endl;
//            if(n<8)
//                cout<<"\nSo luong phan tu qua nho. Hay dung sap xep binh thuong"<<endl;
//            else
//            {
            {
                clock_t start = clock();
                Bubble_Sort(0,n-1);
                //xuat_mang();
                clock_t finish = clock();
                printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)((finish - start)/CLOCKS_PER_SEC));
            }
            {
                clock_t start = clock();
                thread t1(Bubble_Sort,0,n/4-1);
                thread t2(Bubble_Sort,n/4,n/2-1);
                thread t3(Bubble_Sort,n/2,3*n/4-1);
                thread t4(Bubble_Sort,3*n/4,n-1);
                t1.join();
                t2.join();
                t3.join();
                t4.join();
                //PTHREAD_BARRIER_SERIAL_THREAD;
                Merge(0,n/2-1);
                Merge(n/2,n-1);
                Merge(0,n-1);
                //xuat_mang();
                clock_t finish = clock();
                printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)(finish - start)/CLOCKS_PER_SEC);
            }
            system("pause");
        }
        else if(luachon==8)
        {

//            if(n<8)
//                cout<<"\nSo luong phan tu qua nho. Hay dung sap xep binh thuong"<<endl;
//            else
//            {
//            cout<<"\nMang ban dau la:"<<endl;
//            for(int i= 0; i < n; i++)
//            {
//                cout<<setw(5)<<left<<a[i];
//            }
//            cout<<endl;
            {

                clock_t start = clock();
                Quick_Sort(0,n-1);
                //xuat_mang();
                clock_t finish = clock();
                printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)((finish - start)/CLOCKS_PER_SEC));
            }
            clock_t start = clock();
            thread t1(Quick_Sort,0,n/4-1);
            thread t2(Quick_Sort,n/4,n/2-1);
            thread t3(Quick_Sort,n/2,3*n/4-1);
            thread t4(Quick_Sort,3*n/4,n-1);
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            //PTHREAD_BARRIER_SERIAL_THREAD;
            Merge(0,n/2-1);
            Merge(n/2,n-1);
            Merge(0,n-1);
            //xuat_mang();
            clock_t finish = clock();
            printf("\nThoi gian thuc hien la: %.20f (s)\n",(float)(finish - start)/CLOCKS_PER_SEC);
            system("pause");
        }
        else if(luachon==9)
        {
            xuat_mang();
            system("pause");
        }
        else if(luachon==10)
        {
            print_to_file();
            cout<<"\nMo file ouput.txt de xem ket qua.";
            system("pause");
        }
        else
            break;
    }
}

int main()
{
    menu();
    delete a;
    return 0;
}

