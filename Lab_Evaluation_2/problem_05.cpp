#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define MAXINT 10000009


int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= m ;i++){
        if(i%n == 0){
            cout << i << " ";
        }
    }
    nl;

    return 0;
}
