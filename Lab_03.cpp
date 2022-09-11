/*
Lab_03

1. Duplicate elimination from an array.
2. Finding k-th maximum and k-th minimum.

*/

#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------*/

#define ll      long long
#define nl      cout << "\n";
#define fast    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX_INT 100007

/*---------------------------------------------------------------------------*/

//User Defined Functions
void Sort(int arr[] , int a);



/*---------------------------------------------------------------------------*/

void solve()
{
    //Input
    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    int a[n+10];
    cout << "Enter Array Eliments: ";
    for(int i = 0 ;i < n; i++){
        cin >> a[i];
    }


    //Task #01:
    //Eliminate Duplicate Element
    int a2[n];
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; ){
            if(a[i] == a[j]){
                for(int k = j ; k< n-1 ; ++k){
                    a[k] = a[k+1];
                }
                n--;
            }
            else j++;
        }
    }
    cout << "After Deleting Duplicate Eliment: ";nl;
    for(int i = 0 ;i < n; i++){
        cout << a[i] << ' ';
    }
    nl;nl;


    //Task #02:
    //k-th maximum and k-th minimum

    Sort(a, n);
    cout << "Enter k-th number: ";
    int x;
    cin >> x;
    cout << x << "-th maximum number: " << a[n-x];nl;
    cout << x << "-th minimum number: " << a[x-1];
    nl;nl;

}


int main()
{
    solve();
    return 0;
}

void Sort(int arr[] , int a)
{
    for(int i = 0 ; i < a -1 ;i++){
        for(int j = 0 ; j < a-1 ;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
