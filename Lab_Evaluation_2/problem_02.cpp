#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define MAXINT 10000009


int main()
{
    int n, m;
    cout << "Enter Matrix row and column numbers: ";
    cin >> n >> m;
    int matrix[n][m];
    cout << "Enter Matrix elements:";nl;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ;j++){
            cin >> matrix[i][j];
        }
    }

    int upper_sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (i <= j) {
                upper_sum += matrix[i][j];
            }
        }
    }
    cout << "the summation of the elements of the upper triangular matrix = " << upper_sum;
    nl;

    int mx= -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (j <= i) {
                if(mx <matrix[i][j]) mx = matrix[i][j];
            }
        }
    }

    cout << "maximum number among the elements of the lower diagonal matrix= " << mx;

    nl;

    return 0;
}
