#include <bits/stdc++.h>
using namespace std;
#define nl cout << endl

int main()
{
    int sub = 5 , student = 10 , sum = 0;
    int marks[5][10];

    for(int i = 0; i < 5 ; i++){
        for(int j = 0 ;j < 10 ; j++){
            marks[i][j] = rand()%100;

        }
    }
    cout << "Subject Code" << setw(5) << "S1" << setw(3) << "S2" << setw(3)<< "S3" << setw(3)<< "S4" << setw(3)<< "S5" << setw(3)<< "S6" << setw(3)<< "S7" << setw(3)<< "S8" << setw(4)<< "S9" << setw(4)<< "S10";
    nl;
    for(int i = 0; i < 5 ; i++){
        cout << setw(3) << i+1 << setw(12);
        for(int j = 0 ;j < 10 ; j++){
            cout << setw(3) << marks[i][j] << setw(3);
        }
        nl;
    }

    cout << "Enter Subject Code: ";
    cin >> sub;
    int mx = -1 , mn=101 , avg;

    for(int i = 0 ; i < 10 ; i++){
        if(marks[sub][i] > mx) mx = marks[sub][i];
    }
    for(int i = 0 ; i < 10 ; i++){
        if(marks[sub][i] < mn) mn = marks[sub][i];
    }
    for(int i = 0 ; i < 10 ; i++){
        sum += marks[sub][i];
    }
    cout << "Maximum: " << mx ;nl;
    cout << "Minimum: " << mn;nl;
    cout << "Average: " << fixed << setprecision(2) <<  (float)sum/10;
    nl;



    return 0;
}
