#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define ll long long;

const int N = 1e3+10;

int a[N][N];






int main()
{
    int n,m=0;

    int a[4][4] =  {{0,1,1,0}, 
                    {1,0,1,1}, 
                    {1,1,1,0},
                    {0,1,0,1}};
    /*
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            
        }
    }
    */
    cout << "Adjacency Matrix Representation:";nl;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0; j < 4 ; j++){
            cout << a[i][j] << ' ';
        }
        nl;
    }
    nl;

    int deg =0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0; j < 4 ; j++){
            if(a[i][j] == 1|| a[j][i] == 1)  deg++;
        }
    }
    cout << "Number of degrees: " << deg;nl;
    cout << "Number of edges: " << deg/2;nl;

    bool complete=true;
    for(int i = 0 ; i< 4 ; i++){
        for(int j = 0 ; j < 4 ;j++){
            if(i != j && a[i][j] ==0) complete = false;
        }
    }
    bool isolated = 1;
    for(int i = 0 ; i< 4 ; i++){
        for(int j = 0 ; j < 4 ;j++){
            if(a[i][j] ==1) isolated=0;
        }
        if(!isloated) 
    }
    if(complete==true) cout << "It is a complete graph";
    else cout << "It's not a complete graph";
    nl;


    int b[4][4] =  {{0,3,0,7}, 
                    {8,0,2,0}, 
                    {5,0,0,1},
                    {2,0,0,0}};

    
    for(int k = 0 ; k < 4 ; k++){
        for(int i = 0 ;i <4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                if(b[i][j] > b[i][k]+b[k][j]) b[i][j] = b[i][k]+b[k][j];
                //b[i][j] = b[i][j] & (b[i][j] ^ b[k][j]);
            }
        }
    }
    deg = 0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(b[i][j] || b[j][i]) deg++;
        }
    }
    cout << deg;nl;
    
    deg = 0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(a[j][i] || a[i][j])  deg++;
        }
    }

    cout << deg;nl;

    cout << "Path Matrix Representation:";nl;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0; j < 4 ; j++){
            cout << b[i][j] << ' ';
        }
        nl;
    }
    nl;





    return 0;
}
