#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define ll long long;

/*
01. Creation
02. Insertion
03. Deletion
04. Heapsort
*/

void heapify(int a[], int n, int i)
{
    int mx = i;
    int l = 2*i +1;
    int r = 2*i +2;
    if(l < n && a[l] > a[mx]){
        mx = l;
    }
    if(r < n && a[r] > a[mx]){
        mx = r;
    }
    if(mx != i){
        swap(a[i] , a[mx]);
        heapify(a, n, mx);
    }
    
}


void constructHeap(int a[], int n)
{
    for(int i = (n/2)-1 ; i >=0 ; i--){
        heapify(a, n ,i);
    }
}


int find(int a[] ,int n, int x)
{
    for(int i = 0 ; i < n ; i++){
        if(a[i] == x) return i;
    }
    return -1;
}

void heapSort(int a[] ,  int n)
{
    for(int i = n/2 -1 ; i >=0 ; i--){
        heapify(a, n , i);
    }
    for(int i = n-1; i >0 ; i--){
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
}

int main()
{
    int a[] = {1,2,3,5,7,8,9,11,15,16,19,21};

    int n = sizeof(a)/sizeof(a[0]);

    /*
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;
    */
    constructHeap(a,n);

    cout << "Heap:";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    cout << "Enter a value to insert: "; 
    int x; cin >> x;

    a[n] = x;
    n++;
    constructHeap(a,n);

    cout << "After insertion :";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    cout << "Enter a value to delete: "; 
    cin >> x;

    int pos = find(a,n, x);
    
    a[pos] = a[n-1];
    n--;

    constructHeap(a,n);

    cout << "After Deletion :";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    heapSort(a,n);

    cout << "After Sorting(Ascending Order):";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    


    return 0;
}
