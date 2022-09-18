#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";

int a[1000];
void insertion(int x)
{
    int pos;
    for(int i = 0 ; i < 9 ; i++){
        if(a[i] <= x){
            pos = i;
            break;
        }
    }
    for(int i = 10 ; i > pos ; i--){
        a[i] = a[i-1];
    }
    a[pos] = x;
}

int b[1000];
bool binarysearch(int x)
{
    int l = 0;
    int r = 7;
    while(l <= r){
        int mid = l+(r-1)/2;
        if(b[mid] == x) return true;
        if(b[mid] < x) l= mid+1;
        else r = mid - 1;
    }
    return false;
}




int main()
{
    ///Problem 01
    for(int i = 0 ; i < 9 ; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    insertion(x);

    for(int i = 0 ; i < 10 ; i++){
        cout << a[i] << ' ';
    }
    nl;nl;

    ///Problem 02
    for(int i = 0 ; i < 7 ;i++){
        cin >> b[i];
    }
    cin >> x;
    if(binarysearch(x) == true){
        cout << "Congratulations! You are selected for the scholarship.\n";
    }
    else{
        cout << "Sorry! Hope for the Best Next Time.\n";
    }

    nl;

    ///Problem 03
    int freq[1001] = {0};
    int mark[1001] = {0};
    int mn = 1001, mx = 99;
    int c[1001];
    for(int i = 0 ; i < 15; i++){
        cin >> c[i];
        freq[c[i]]++;
        if(freq[c[i]] >1) mark[i]=1;
        if(c[i] > mx) mx = c[i];
        if(c[i] < mx) mn = c[i];
    }
    cout << 15;nl;
    int te[1001] = {0};
    for(int i = 0 ; i < 15 ; i++){
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
