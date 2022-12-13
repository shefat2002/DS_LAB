#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";

void selectionSort(int a[], int n)
{
    for(int i = 0 ; i< n-1;i++){
        int mn = i;
        for(int j = i+1 ; j <n ; j++){
            if(a[j] < a[mn]) mn = j;
        }
        swap(a[i], a[mn]);
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void Merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        Merge(a, l, m, r);
    }
}

void shuffle_(int a[], int n)
{

    int seed = 0;

    shuffle(a, a + n,
            default_random_engine(seed));
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    nl;nl;

    cout << "Unsorted Array: ";nl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;
    selectionSort(a,n);
    cout << "Selection Sort: ";nl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;;nl;nl;
    shuffle_(a,n);
    cout << "Unsorted Array: ";nl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    insertionSort(a,n);
    cout << "Insertion Sort: ";nl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;nl;

    shuffle_(a,n);

    cout << "Unsorted Array: ";nl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;

    mergeSort(a, 0, n - 1);

    cout << "Merge Sort: ";nl;
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;nl;

}
