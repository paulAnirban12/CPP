#include<bits/stdc++.h>

    using namespace std ;

    int a[10];
    int n , i ;
    int output[20];
    int max_sum = 0 ;
    int max_product  = 1 ;
    void input()
    {
        cout << "Size : " ;
        cin >> n ;
        for(i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
        }
    }
    int getmax()
    {
        int Maximum = a[1];
        for(i = 2 ; i <= n ; i++)
        {
            if(Maximum < a[i])
            {
                Maximum = a[i] ;
            }
        }
        return Maximum ;
    }
    void Countsort()
    {
        int Max = getmax() ;
        int count[Max+1];
        for(i = 0 ; i <= Max ; i++)
        {
            count[i] = 0 ;
        }
        for(i = 1 ; i <= n ; i++)
        {
            count[a[i]]++ ;
        }
        for(i = 1 ; i <= Max ; i++)
        {
            count[i] += count[i-1];
        }
        for(i = n ; i >= 1 ; i--)
        {
            output[count[a[i]]] = a[i] ;
            count[a[i]] -= 1;
        }
    }
    void print()
    {
        cout<< "Before Sorting : ";
        for(i = 1 ; i<= n ; i++)
        {
            cout << a[i] << " " ;
        }
        printf("\n");
        cout<< "After Sorting : ";
        for(i = 1 ; i<= n ; i++)
        {
            cout << output[i] << " " ;
        }
        cout << endl ;
        cout<< "Max product of two elements : ";
        cout << max_product ;
        cout << endl ;
        cout<< "Max sum of two elements : ";
        cout << max_sum ;
    }
    void calculate()
    {
        for(i = n ; i > n-2 ; i--)
        {
            max_sum += output[i];
            max_product *= output[i] ;
        }
    }
    int main()
    {
        input() ;
        Countsort() ;
        calculate() ;
        print() ;
        return 0 ;
    }
