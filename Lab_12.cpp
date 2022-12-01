#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define ll long long;
#define INF 99999
const int N = 1e3+10;

int a[N][N];


int main()
{
    int n,m=0;
    int v = 4;
    int a[v][v] =  {{0,1,1,0}, 
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
    for(int i = 0 ; i < v ; i++){
        for(int j = 0; j < v ; j++){
            cout << a[i][j] << ' ';
        }
        nl;
    }
    nl;

    int deg[v] = {0};
    int e=0;
    for(int i = 0 ; i < v ; i++){
        for(int j = 0; j < v ; j++){
            if(a[i][j] == 1|| a[j][i] == 1)  deg[i]++;
            e++;
        }
    }
    cout << "Number of Vertices: " << v;nl;
    cout << "Number of Edges: " << e/2;nl;
    cout << "Number of Degrees: ";nl;
    for(int i = 0 ; i < v ; i++){
        cout << i << " --> " << deg[i];nl;
    }
    cout << "Total degrees: " << e;nl;nl;
    

    bool complete=true;
    for(int i = 0 ; i< 4 ; i++){
        for(int j = 0 ; j < 4 ;j++){
            if(i != j && a[i][j] ==0) complete = false;
        }
    }
    if(complete==true) cout << "It is a complete graph";
    else cout << "It's not a complete graph";
    nl;nl;

    // Warshall's algorithm
    int b[4][4] =  { { 0, 5, INF, 6 },
                        { INF, 0, 3, INF },
                        { INF, 6, 0, INF },
                        { 7, INF, INF, 0 } };

    
    for(int k = 0 ; k < 4 ; k++){
        for(int i = 0 ;i <4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                if((b[i][j] > (b[i][k]+b[k][j])) &&(b[k][j] != INF && b[i][k] != INF)) b[i][j] = b[i][k]+b[k][j];
                //b[i][j] = b[i][j] & (b[i][j] ^ b[k][j]);
            }
        }
    }
    
    cout << "All Pair shortest Path:";nl;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0; j < 4 ; j++){
            if(b[i][j] == INF) cout << setw(4) << "INF ";
            else cout << setw(3) << b[i][j] << ' ';
        }
        nl;
    }
    nl;

    return 0;
}
