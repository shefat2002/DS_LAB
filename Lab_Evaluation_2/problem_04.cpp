#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define MAXINT 10000009


int main()
{
    int row1, col1;
    cout << "Enter Matrix 1 row and column numbers: ";
    cin >> row1 >> col1;
    int m1[row1][col1];
    cout << "Enter Matrix 1 elements:";
    nl;
    for(int i = 0 ; i < row1 ;i++){
        for(int j = 0 ; j < col1 ;j++){
            cin >> m1[i][j];
        }
    }

    int row2, col2;
    cout << "Enter Matrix 2 row and column numbers: ";
    cin >> row2 >> col2;
    int m2[row2][col2];
    cout << "Enter Matrix 2 elements:";
    nl;
    for(int i = 0 ; i < row2 ;i++){
        for(int j = 0 ; j < col2 ;j++){
            cin >> m2[i][j];
        }
    }
    int M[col1][row2];
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++)
        {
            M[i][j]=0;
        }
    }
    if(col2 != row1){
        cout << "Can not multiply!";
    }


    else{

        for(int i = 0 ; i <row1  ; i++){
            for(int j  = 0 ; j < col2  ;j++){
                for(int k = 0 ;  k < col1  ;k++){
                    M[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        for(int i = 0 ; i < row1 ;i++){
            for(int j = 0 ; j < col2 ;j++){
                cout << M[i][j] << ' ';
            }
            nl;
        }
        nl;
        cout << "Transpose Matrix:"; nl;
        for(int i = 0 ; i < col2 ;i++){
            for(int j = 0 ; j < row1 ;j++){
                cout << M[j][i] << ' ';
            }
            nl;
        }
        nl;


    }







    return 0;
}
