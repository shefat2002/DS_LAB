#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define MAXINT 10000009


int main()
{
    int n;
    cin >> n;
    int freq[1001] = {0};
    int mark[1001] = {0};
    int mn = 1000000, mx = -1;
    int c[1001];
    for(int i = 0 ; i < n; i++){
        cin >> c[i];
        freq[c[i]]++;
        if(freq[c[i]] >1) mark[i]=1;
        if(c[i] > mx) mx = c[i];
        if(c[i] < mx) mn = c[i];
    }
    cout << n;nl;
    int te[1001] = {0};
    for(int i = 0 ; i < n ; i++){
        if(freq[c[i]] > 1 && te[c[i]] == 0){
            cout << freq[c[i]] << " -- " << c[i];nl;
            te[c[i]] = 1;
        }
        else if(freq[c[i]] == 1){
            cout << freq[c[i]] << " -- " << c[i];nl;
        }
    }
    cout << mx << " -- " << mn;
    nl;



    return 0;
}
