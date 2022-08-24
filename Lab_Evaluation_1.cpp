#include <bits/stdc++.h>
using namespace std;
#define nl cout << endl

int* insertion(int a[], int n , int pos, int x)
{
    for(int i = n+1 ; i >= pos ; i--){
        a[i] = a[i-1];
    }
    a[pos -1] = x;
    return a;
}

int deletion(int a[], int n , int val)
{
    int pos;
    for(int i = 0 ; i < n ;i++){
        if(val == a[i]){
            pos = i;
            break;
        }
    }
    for(int i = pos; i < n ; i++){
        a[i] = a[i+1];
    }
    return n;
}

int main()
{
    int a[] = {11, 6 , 15,  8 , 6 , 10 , 21, 8};
    int n = sizeof(a)/ sizeof(a[0]);
    int val , pos , del; cin >> pos >> val >> del;
    insertion(a,n ,pos , val);
    n++;
    cout << "After insertion:";nl;
    for(int i = 0 ; i< n-1 ;i++){
        cout << a[i] << ", ";
    }
    cout << a[n-1];
    nl;nl;

    n--;
    cout << "Remaining Books:";nl;
    deletion(a, n , del);
    for(int i = 0 ; i< n-1 ;i++){
        cout << a[i] << ", ";
    }
    cout << a[n-1];


    return 0;
}
