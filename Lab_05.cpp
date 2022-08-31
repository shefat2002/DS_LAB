/*
Pointers to impliment different operations in one-dimensional array
1. Summation of element
2. Counting the odd and even number
3. finding the multiple of 5 and 10
4. Linear Search
5. Binary Search
6. Bubble Sort
7. K-th Maximum and K-th minimum
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl cout << "\n";

void BubbleSort(int arr[] , int a)
{
    int *pa , *pb;
    for(int i = 0 ; i < a -1 ;i++){
        for(int j = 0 ; j < a-1 ;j++){
            pa = &arr[j];
            pb = &arr[j+1];
            if(*pa > *pb){
                int temp = *pa;
                *pa = *pb;
                *pb = temp;
            }
        }
    }

}

int main()
{

    //write a program to find the summation of element stored in an array
    int x[10] ;
    for(int i = 0 ; i < 10 ;i++){
        x[i] = 1+ rand()%99;
    }
    for(int i = 0 ; i < 10 ;i++){
        cout << x[i] << " ";
    }
    nl;nl;
    int sum = 0;
    /*
    for(int i = 0 ; i < (sizeof(x)/sizeof(x[0])); i++){
        sum += x[i];
    }
    cout << sum;
    nl;
    */
    cout << "Summation of elements: ";
    sum =0;
    int *ptr;
    ptr = x;

    for(int i = 0 ; i < sizeof(x)/ sizeof(x[0]) ; i++){
        sum += *(ptr);
        ptr++;
    }
    cout << sum;
    nl;nl;

    //even odd using pointer

    int even = 0 , odd = 0;
    int *px;
    px = x;
    for(int i = 0 ; i <10 ;i++){
        if(*px % 2== 0) even++;
        else odd++;

        px++;
    }
    cout << "Even Elements: "<< even;nl;
    cout << "Odd Elements: " << odd;

    nl;nl;

    int *pp , mm[10] , j =0;
    pp = x;
    for(int i = 0 ; i < 10 ; i++){
        if(*pp %5 == 0 && *pp % 10 ==0){
            mm[j++] = *pp;
        }
        pp++;
    }
    cout << "Multiple of 5 and 10: ";
    for(int i = 0 ; i < j ;i++){
        cout << mm[i] << " ";
    }
    nl;nl;


    //Bubble sort

    BubbleSort(x, 10);
    cout << "After Sorting: ";
    for(int i = 0 ; i < 10 ;i++){
        cout << x[i] << " ";
    }
    nl;nl;


    cout << "Enter a item to find: ";
    int a; cin >> a;


    //binary search using pointer

    cout << "Using Binary Search: ";
    int *p , *q , *m;
    int l = 0 , r = 9;
    p = &l;
    q = &r;



    bool found = false;

    while(*p <= *q){
        int mid = *p+ (*q-1) /2;
        m = &x[mid];
        if(*m == a){
            cout << "Item found!";
            found = true;
            break;

        }
        if(*m < a){
            *p= mid+1;
        }
        else{
            *q = mid-1;
        }
    }


    if(found == false) cout << "Item not found";
    nl;nl;

    //Linear Search

    cout << "Using Linear Search: ";
    for(int i = 0 ; i < 10 ; i++){
        if(*m == a){
            cout << "Item Found!!";
            found = true;
            break;
        }
    }
    if(found == false) cout << "Item Not Found";

    nl;nl;


    //K-th Maximum K-th Minimum
    cout << "Enter K-th Number: ";
    int qq;
    cin >> qq;

    cout << qq << "-th maximum number: " << x[10-qq];nl;
    cout << qq << "-th minimum number: " << x[qq-1];


    return 0;
}
