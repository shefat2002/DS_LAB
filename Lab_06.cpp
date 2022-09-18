#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";


//User-Defined Function to exchange two numbers
void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

//User-Defined Function of BubbleSort.
void BubbleSort(int arr[] , int a)
{
    int *pa , *pb;
    for(int i = 0 ; i < a -1 ;i++){
        for(int j = 0 ; j < a-1 ;j++){
            pa = &arr[j];
            pb = &arr[j+1];
            if(*pa > *pb){
                exchange(pa, pb);
            }
        }
    }

}

int* insertion(int *p , int pos, int x)
{
    for(int i = 10 ; i >= pos ; i--){
        *(p+i) = *(p+i-1);
    }
    *(p+pos-1) = x;
    return p;
}

int deletion(int *p , int x)
{
    int pos = -1;
    for(int i = 0 ; i < 11 ; i++){
        if(x == *(p+i)){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        cout << "Item not found!";
        return 0;
    }
    for(int i = pos; i < 10 ; i++){
        *(p+i) = *(p+i+1);
    }
    return 1;
}


int main()
{
    srand(time(0));
    int a[1000];
    for(int i = 0 ; i < 100 ; i++){
        a[i] = rand()%1000;
    }
    int b[10][10];
    for(int i = 0 ; i < 10 ;i++){
        for(int j = 0 ; j < 10; j++){
            b[i][j] = rand()%1000;
        }
    }

    cout << "Display of 1D array elements: ";nl;
    for(int i = 0 ; i < 100 ; i++){
        cout << a[i] << " ";
    }
    nl;
    nl;
    cout << "Display of 2D array elements: ";nl;
    for(int i = 0 ; i < 10 ;i++){
        for(int j = 0 ; j < 10; j++){
            cout << setw(3) << b[i][j]<< "  ";
        }
        nl;
    }
    nl;



    //Task #01(I)
    int sum = 0;
    cout << "Summation of elements in 1D array: ";
    sum =0;
    int *ptr;
    ptr = a;

    for(int i = 0 ; i < 100 ; i++){
        sum += *(ptr);
        ptr++;
    }
    cout << sum;
    nl;
    nl;

    //Task #01(II)
    cout << "Summation of elements in 2D array: ";
    sum =0;
    int (*ptr2)[10];
    ptr2 = b;
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ;j++){
            sum += *(*(ptr2+i)+j);
        }

    }
    cout << sum;
    nl;
    nl;

    //Task #02
    cout << "Enter two numbers(X and Y):";nl;
    int x, y;
    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;
    exchange(&x,&y);
    cout << "After exchange:\t";
    cout << "X = " << x << ", Y = " << y;
    nl;
    nl;


    int arr[20];
    for(int i= 0 ; i < 10 ; i++){
        arr[i] = rand() % 100;
    }
    cout << "Array: ";
    for(int i= 0 ; i < 10 ; i++){
        cout << arr[i] << ' ';
    }
    nl;
    nl;


    //Task #03
    int *pt = arr;
    int *mx = arr;
    int *mn = arr;
    for(int i = 0 ; i < 10 ;i++){
        if(*pt > *mx)
            mx = pt;
        if(*pt < *mn)
            mn = pt;
        pt++;
    }
    cout << "Largest Number: " << *mx;
    nl;
    cout << "Smallest Number: "<< *mn;
    nl;
    nl;

    //Task #04

    BubbleSort(arr, 10);
    cout << "After Sorting: ";
    for(int i= 0 ; i < 10 ; i++){
        cout << arr[i] << ' ';
    }
    nl;nl;


    cout << "Enter a item to find: ";
    int o; cin >> o;


    //Task #05
    cout << "Using Binary Search: ";
    int *p , *q , *m;
    int l = 0 , r = 9;
    p = &l;
    q = &r;
    bool found = false;

    while(*p <= *q){
        int mid = *p+ (*q-1) /2;
        m = &arr[mid];
        if(*m == o){
            cout << "Item found!";
            found = true;
            break;
        }
        if(*m < o){
            *p= mid+1;
        }
        else{
            *q = mid-1;
        }
    }
    if(found == false)
        cout << "Item not found!";
    nl;
    nl;

    //Linear Search
    cout << "Using Linear Search: ";
    for(int i = 0 ; i < 10 ; i++){
        if(*m == o){
            cout << "Item Found!";
            found = true;
            break;
        }
    }
    if(found == false)
        cout << "Item Not Found!";

    nl;
    nl;


    //Task #06
    int *ii = arr;
    int pos ;
    cout << "Enter a number to insert: ";
    cin >> x;
    cout << "Enter the position to insert: ";
    cin >> pos;
    insertion(ii , pos , x);

    cout << "After Insertion: ";
    nl;
    for(int i = 0 ; i < 11 ;i++){
        cout << *(ii+i) << " ";
    }
    nl;
    nl;

    //Task #07
    cout << "Enter the value to delete: ";
    cin >> x;
    if(deletion(ii, x)){
        cout << "After Deletion:";
        nl;
        for(int i = 0 ; i < 10 ;i++)
            cout << *(ii+i) << " ";
    }
    nl;

    return 0;
}
