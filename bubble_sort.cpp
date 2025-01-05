#include<bits/stdc++.h>

    using namespace std ;

    void bubblesort(int a[], int n)
    {
        int i , temp , j , count = 0 ;
        for(i = 0 ; i < n ; i++)
        {
            for(j = i+1 ; j <= n ; j++)
            {
                if(a[j] < a[i])
                {
                    temp = a[i] ;
                    a[i] = a[j] ;
                    a[j] = temp ;
                    count++ ;
                }
            }
            cout << a[i] << " " ;
        }
        cout << endl ;
        cout << "Total number of swapping : " << count ;
    }
    int main()
    {
        int a[100] , n ;
        cout << "Size : " ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i] ;
        }
        bubblesort(a,n);
        return 0 ;
    }
