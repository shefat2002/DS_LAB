#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define nl      cout << "\n";
#define fast    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void file();
/*----------------------------------------------------------------------------------------------------------------------------------------*/

///Using Array

void solve()
{
    int a[20],top = 0;
    for(int i = 0 ; i < 4 ; i++){
        cin >> a[i];
        top++;
    }
    cout << "Stack elements: ";
    for(int i = 0 ; i <top ; i++){
        cout << a[i] << ' ';
    }
    cout << top-1;
    nl;

    int x;
    cout << "Push: ";
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> a[top];
        top++;
    }
    cout << "After Push: ";
    for(int i = 0 ; i <top ; i++){
        cout << a[i] << ' ';
    }
    cout << top-1;
    nl;

    cout << "Pop: ";
    cin >> x;
    for(int i = 0; i < x; i++){
        top--;
    }
    cout << "After Pop: ";
    for(int i = 0 ; i <top ; i++){
        cout << a[i] << ' ';
    }
    cout << top-1;
    nl;

    nl;
    fast;
    int n; cin >> n;
    int a[n];
    int f = 0 ,r =0;
    //initial value
    for(int i = 0; i < 5 ; i++){
        cin >> a[i];
        r++;
    }
    for(int i = 0 ; i< r ; i++){
        cout << a[i] << ' ';
    }
    nl;
    cout << f << ' ' << r-1;
    nl;

    //delete
    int del; cin >> del;
    f+=del;
    cout << f << ' ';
    for(int i = f ; i< r ; i++){
        cout << a[i] << ' ';
    }
    nl;
    
    //insert
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x;
        a[r] = x;
        r++;
    }
    cout << r-1 << ' ';
    for(int i = f ; i < r ; i++){
        cout << a[i] << ' ';
    }
    nl;

}




int main()
{
    //fast;
    //file();
    solve();
    return 0;
}

void file()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r", stdin);
    freopen("out.txt" , "w", stdout);
    #endif
}
