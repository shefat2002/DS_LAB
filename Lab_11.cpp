#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define ll long long;


void heapify_maxheap(int a[], int n, int i)
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
        heapify_maxheap(a, n, mx);
    }
    
}

void MaxHeap(int a[], int n)
{
    for(int i = (n/2)-1 ; i >=0 ; i--){
        heapify_maxheap(a, n ,i);
    }
}

void heapify_minheap(int a[], int n, int i)
{
    int mn = i;
    int l = 2*i +1;
    int r = 2*i +2;
    if(l < n && a[l] < a[mn]){
        mn = l;
    }
    if(r < n && a[r] < a[mn]){
        mn = r;
    }
    if(mn != i){
        swap(a[i] , a[mn]);
        heapify_minheap(a, n, mn);
    }
    
}


void MinHeap(int a[], int n)
{
    for(int i = (n/2)-1 ; i >=0 ; i--){
        heapify_minheap(a, n ,i);
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
        heapify_maxheap(a, n , i);
    }
    for(int i = n-1; i >0 ; i--){
        swap(a[0], a[i]);
        heapify_maxheap(a,i,0);
    }
}

int main()
{
    int a[] = {1,2,3,15,7,8,21,11,5,16,19,9};

    int n = sizeof(a)/sizeof(a[0]);

    /*
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;
    */
    MaxHeap(a,n);

    cout << "Max Heap:";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;

    MinHeap(a,n);

    cout << "Min Heap:";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;
    /*
    cout << "Enter a value to insert: "; 
    int x; cin >> x;

    a[n] = x;
    n++;
    MaxHeap(a,n);

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

    MaxHeap(a,n);

    cout << "After Deletion :";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;
    */
    heapSort(a,n);

    cout << "Heap Sort:";nl;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    return 0;
}
