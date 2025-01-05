#include<bits/stdc++.h>
#define infinity 9999999 ;

    using namespace std ;

    int a[100],Size,i ;
    void scan()
    {
        cout<< "Size : " ;
        cin >> Size ;
        for(i = 0 ; i < Size ; i++)
        {
            cin >> a[i] ;
        }
    }

    void print()
    {
        for(i = 0 ; i < Size ; i++)
        {
            cout << a[i] << " ";
        }
    }

    void Sort(int p, int q, int r)
    {
        int n1,n2 , j, L[50], R[50] ;
        n1 = q - p + 1 ;
        n2 = r - q ;
        for(i = 0 ; i < n1 ; i++)
        {
            L[i] = a[p + i] ;
        }
        for(j = 0 ; j < n2 ; j++)
        {
            R[j] = a[q + j + 1] ;
        }
        L[n1] = infinity ;
        R[n2] = infinity ;
        i = 0 , j = 0 ;
        int k ;
        for(k = p ; k <= r ; k++)
        {
            if(L[i] <= R[j])
            {
                a[k] = L[i] ;
                i++ ;
            }
            else
            {
                a[k] = R[j] ;
                j++ ;
            }
        }
    }
    void Merge(int first, int last)
    {
        if(first < last)
        {
            int mid = (first+last)/2 ;
            Merge(first,mid);
            Merge(mid+1,last);
            Sort(first,mid,last);
        }
    }
    int main()
    {
        scan();
        Merge(0,Size-1);
        print() ;
        return 0 ;
    }
