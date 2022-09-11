#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define nl      cout << "\n";

/*-------------------------------------------------------------------------------------------------------------------------*/


//Sorting(ascending order) User-Defined Function
void BubbleSort(int arr[] , int a);

int mul[3][3] ;
void solve()
{
    //Task #01(a)
    //Assign 100 random elements in One-Dimensional Array using rand() function.
    int a[1000];
    for(int i = 0 ; i < 100 ; i++){
        a[i] = rand()%1000;
    }

    //Task #01(b)
    //Assign 100 random elements in Two-Dimensional Array using rand() function.
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
    nl;nl;
    cout << "Display of 2D array elements: ";nl;
    for(int i = 0 ; i < 10 ;i++){
        for(int j = 0 ; j < 10; j++){
            cout << setw(3) << b[i][j]<< "  ";
        }
        nl;
    }
    nl;

    //Task #02
    //Counting even and odd numbers in one-dimensional array
    int cnt = 0;
    cout << "Even Numbers: ";
    for(int i = 0 ; i < 100 ; i++){
        if(a[i] % 2 ==0) cnt++ ;
    }
    cout << cnt << endl;
    cnt = 0;
    cout << "Odd Numbers: ";
    for(int i = 0 ; i < 100 ; i++){
        if(a[i] % 2 ==1) cnt++;
    }
    cout << cnt;
    nl;nl;


    //Task #03
    //Output the numbers that multiplied by 5 and 10 in two dimensional array
    cout << "Numbers that multiplied by 5 and 10:\n";
    for(int i = 0 ; i < 10 ;i++){
        if(i % 5 == 0 && i % 10 == 0){
            for(int j = 0 ; j < 10; j++){
                if(i % 5 == 0 && i % 10 == 0){
                    cout << b[i][j] << ' ' ;
                }

            }
        }
    }
    nl; nl;


    //Task #04
    //Finding a number Occurrences in 1D and 2D array.
    int x , c1 = 0 , c2 = 0;
    cout << "Enter a Number to find Occurrences in 1D array: ";
    cin >> x;
    cout << "Number of occurrences in one dimensional: ";
    for(int i = 0 ; i < 100 ; i++){
        if(a[i] == x) c1++;
    }
    cout << c1 ;
    nl;
    cout << "Enter a Number to find Occurrences in 2D array: ";
    cin >> x;
    cout << "Number of occurances in two dimensional: ";
    for(int i = 0 ; i < 10 ;i++){
        for(int j = 0 ; j < 10; j++){
             if(b[i][j] == x) c2++;
         }
    }
    cout << c2;
    /*
    for(int i = 0 ; i< 10 ; i++){
        cout << endl;
        for(int j = 0; j< 10 ; j++){
            cout << b[i][j] << ' ';
        }
    }
    nl;nl;
    */
    nl;nl;

    //Task #05(a)
    //Calculation of Diagonal numbers from Two-Dimensional Array.
    int   sum1 = 0 ,sum2 = 0;
    for(int i = 0 ; i< 10 ; i++){
        for(int j = i; j< i+1 ; j++){
            sum1 += b[i][j];
        }
    }
    cout << "Diagonal Numbers summation = " << sum1;
    nl;

    //Task #05(b)
    //Calculation of Non-Diagonal numbers from Two-Dimensional Array.
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0; j< 10 ; j++){
            if(j != i) sum2 += b[i][j];
        }
    }
    cout << "Non-Diagonal Numbers summation = " << sum2 ;
    nl;nl;



    //Task #06
    //Matrix Multiplication
    cout << "Matrix:\n";
    int m1[3][3] , m2[3][3];

    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3; j++){
            m1[i][j] = rand()% 10;
        }
    }
    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3; j++){
             m2[i][j] = rand()% 10;
        }
    }

    cout << "First Matrix:\n";
    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3; j++){
            cout <<setw(3) << m1[i][j] << " ";
        }
        nl;
    }
    cout << "Second Matrix:\n";
    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3; j++){
            cout << setw(3) << m2[i][j] << " ";
        }
        nl;
    }

    cout << "Matrix Multiplication:\n";

    for(int i = 0 ; i < 3 ; i++){
        for(int j  = 0 ; j < 3 ;j++){
            for(int k = 0 ;  k < 3 ;k++){
                mul[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    for(int i = 0 ; i< 3 ;i++){
        for(int j = 0 ; j < 3 ; j++){
            cout << setw(3) << mul[i][j]  << ' ';
        }
        nl;
    }
    nl;


    //Task #07
    //merge
    cout << "Before Merge:\n";
    int arr1[5] , arr2[5];
    for(int i = 0 ; i < 5;i++){
        arr1[i] = rand()%10;
    }
    for(int i = 0 ; i < 5;i++){
        arr2[i] = rand()%10;
    }
    cout << "arr1 = ";
    for(int i = 0 ; i < 5;i++){
        cout << arr1[i] << ' ';
    }
    nl;
    cout << "arr2 = ";
    for(int i = 0 ; i < 5;i++){
        cout << arr2[i] << ' ';
    }

    nl;
    int mergearray[10] , k = 0;

    for(int i = 0 ; i < 5; i++){
        mergearray[i] = arr1[i];
        k = i+1;
    }
    for(int i = 0 ; i < 5 ;i++ ){
        mergearray[k] = arr2[i];
        k++;
    }

    cout << "After Merge: ";
    for(int i = 0 ; i < 10 ; i++){
        cout << mergearray[i] << ' ';
    }
    nl;nl;

    //Task #08
    //Sorting
    cout << "Sorting\n";
    cout << "Before Sorting: ";
    for(int i = 0 ; i < 100 ; i++){
        cout << a[i] <<   ' ';
    }
    nl;
    BubbleSort(a , 100);
    cout << "After Sorting: ";
    for(int i = 0 ; i < 100 ; i++){
        cout << a[i] <<   ' ';
    }
    nl;nl;
}

int main()
{
    solve();
    return 0;
}

void BubbleSort(int arr[] , int a)
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
