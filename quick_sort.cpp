#include<bits/stdc++.h>
using namespace std;
int a[1000], Size , i ;
void input()
{
    cout<< "Size : " ;
        cin >> Size ;
        for(i = 0 ; i < Size ; i++)
        {
            cin >> a[i] ;
        }
}
void output()
{
    for(i = 0 ; i < Size ; i++)
        {
            cout << a[i] << " ";
        }
}

int Partition(int p, int r)
{
    int x = a[r];
    i = p-1;
    for(int j=p; j<=r-1; j++)
    {
        if(a[j]<=x)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[r];
    a[r] = a[i+1];
    a[i+1] = t;
    return i+1;
}

void quickSort(int p, int r)
{
    int q;
    if(p<r)
    {
        q = Partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
    return;
}
int main()
{
    input();
    quickSort(0, Size-1);
    output();
    return 0;
}


