#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";



int main()
{
    int v = 4;
    int a[4][4]= {{0,1,0,1},
                {1,0,1,0},
                {1,1,0,0},
                {1,0,0,0}};

    int deg[v] = {0};
    int e=0;
    for(int i = 0 ; i < v ; i++){
        for(int j = 0; j < v ; j++){
            if(a[i][j] == 1|| a[j][i] == 1)  deg[i]++;
            e++;
        }
    }
    cout << "Number of Vertices: " << v;nl;
    cout << "Number of Edges: " << e/4;nl;
    cout << "Number of Degrees: ";nl;
    for(int i = 0 ; i < v ; i++){
        cout << i << " --> " << deg[i];nl;
    }
    cout << "Total degrees: " << e/2;nl;nl;
    bool complete=true;
    for(int i = 0 ; i< 4 ; i++){
        for(int j = 0 ; j < 4 ;j++){
            if(i != j && a[i][j] ==0) complete = false;
        }
    }
    if(complete==true) cout << "It is a complete graph";
    else cout << "It's not a complete graph";
    nl;nl;
}