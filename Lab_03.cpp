#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------*/

#define ll      long long
#define nl      cout << "\n";
#define fast    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX_INT 100007

/*---------------------------------------------------------------------------*/

//User Defined Functions

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

int* insertion(int a[], int n , int pos, int x)
{
    for(int i = n+1 ; i >= pos ; i--){
        a[i] = a[i-1];
    }
    a[pos -1] = x;
    return a;
}
int deletion(int a[], int n , int pos)
{
    //--n;
    for(int i = pos; i < n ; i++){
        a[i] = a[i+1];
    }
    return n;
}


void Rotate(int arr[], int d, int n)
{
    int temp[n];

    int k = 0;
    for (int i = d; i < n; i++) {
        temp[k] = arr[i];
        k++;
    }
    for (int i = 0; i < d; i++) {
        temp[k] = arr[i];
        k++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

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
    //Frequency Count
    cout << "Frequency Count:"; nl;
    cout << "***************************";nl;
    cout << "*  Value   |   Frequency  *";nl;
    cout << "***************************";nl;
    int freq[MAX_INT] = {0}, max = -1;
    for(int i = 0 ; i < n ; i++){
        freq[a[i]]++;
        if(a[i] > max) max = a[i];
    }
    for(int i = 1; i <MAX_INT; i++){
        if(freq[i] > 0 ){
            cout << "*" << setw(5) << i << setw(6) << "|" << setw(7) << freq[i] << setw(8) << "*";nl;
        }
    }
    cout << "***************************";nl;
    nl;



    //Task #02:
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


    //Task #03:
    //k-th maximum and k-th minimum

    Sort(a, n);
    cout << "Enter k-th number: ";
    int x;
    cin >> x;
    cout << x << "-th maximum number: " << a[n-x];nl;
    cout << x << "-th minimum number: " << a[x-1];
    nl;nl;


    //Task #04:
    //Insert an eliment

    cout << "Insertion:";nl;
    cout << "Enter the value and position to insert: ";
    int val, pos;
    cin >> val >> pos;
    cout << "After inserting: ";
    insertion(a, n , pos , val);
    for(int i = 0 ; i <n ; i++){
        cout << a[i] << ' ';
    }
    cout << a[n];
    nl;nl;


    //Task #05:
    //Delete an eliment

    cout << "Deletion:";nl;
    cout << "Enter the location to delete: ";
    int size = sizeof(a)/sizeof(a[0]);
    int loc;
    cin >> loc;
    n = deletion(a, n ,loc-1);
    cout << "After deleting: ";
    for(int i = 0 ; i <n ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;


    //Task #06:
    //Rotation

    cout << "Enter position to rotate: ";
    int d;
    cin >> d;
    Rotate(a, d, n);
    cout << "After Rotation: ";
    for(int i = 0 ; i <n ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;
}


int main()
{
    solve();
    return 0;
}
