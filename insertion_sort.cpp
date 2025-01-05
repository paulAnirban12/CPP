#include<bits/stdc++.h>

    using namespace std ;

    int a[10] , n ;

    void insertionsort()

    {
        int i , x , j , count = 0 ;
        for(i = 1 ; i < n ; i++)
        {
            x = a[i] ;
            j = i-1 ;
            while(j >= 0 && a[j] > x)
            {
                a[j+1] = a[j] ;
                j-- ;
                count++ ;
            }
            a[j+1] = x ;

        }
        cout << "Swapped happened : " << count ;
        cout << endl ;
        for(i = 0 ; i < n ; i++)
        {
            cout << a[i] << " " ;
        }
    }
    int main()

    {

        cout << "Size : " ;
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i] ;

        }
        insertionsort() ;
        return 0 ;
    }

