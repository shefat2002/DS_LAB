#include <bits/stdc++.h>
using namespace std;
#define nl cout << endl

/*****************************************************************************/

int main()
{
    int sub = 5 , student = 10 , sum = 0;
    int marks[5][10];

    for(int i = 0; i < 5 ; i++){
        for(int j = 0 ;j < 10 ; j++){
            marks[i][j] = rand()%100;

        }
    }
    cout << "***************************************************************";nl;
    cout << "* Subject *" << setw(35) << "Student's Marks" << setw(17) << "*";nl;
    cout << "*   Code  *" << setw(6) << "S1 |" << setw(5) << "S2 |" << setw(5)<< "S3 |" << setw(5)<< "S4 |" << setw(5)<< "S5 |" << setw(5)<< "S6 |" << setw(5)<< "S7 |" << setw(5)<< "S8 |" << setw(5)<< "S9 |" << setw(5)<< "S10 " << "*";
    nl;
    cout << "***************************************************************";nl;
    for(int i = 0; i < 5 ; i++){
        cout << "*" << setw(5) << i << setw(6) << "* ";
        for(int j = 0 ;j < 9 ; j++){
            cout << setw(3) << marks[i][j] << " |";
        }
        cout << setw(4) << marks[4][9] << " *";nl;
        if(i <4){
            cout << "*" <<"---------*---------------------------------------------------*";nl;
        }
    }
    cout << "***************************************************************";nl;nl;

    cout << "Enter a Subject Code(0-4): ";
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
    nl;
    cout << "Maximum Number: " << mx ;nl;
    cout << "Minimum Number: " << mn;nl;
    cout << "Average: " << fixed << setprecision(2) <<  (float)sum/10;
    nl;



    return 0;
}
