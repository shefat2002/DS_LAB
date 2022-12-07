#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n"
#define N 35

int a[N][N] , que[N];
bool visited[N];
int n,f=0,r=-1;

void bfs(int v)
{
    for(int i = 0; i <n; i++){
        if(a[v][i] && !visited[i]) que[++r] = i;
    }
    if(f<=r){
        visited[que[f]] = true;
        bfs(que[f++]);
    }
}

void dfs(int v)
{
    visited[v] =1;
    int i;
    for(i =0 ; i < n;i++){
        if(a[v][i]&& !visited[i]){
            cout << v << " ->> " << i;nl;
            dfs(i);
        }
    }

}

int main()
{
    //bfs
    cout << "***BFS***";nl;
    cout << "Number of Nodes: ";
    cin >> n;
    memset(que , 0, sizeof(que));
    memset(visited , 0, sizeof(visited));

    cout << "Enter the graph as matrix representation: ";nl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;i++){
            cin >> a[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    int v; cin >> v;
    bfs(v);

    for(int i = 0 ; i < n ;i++){
        if(visited[i]) cout << i << ' ';
    }
    nl;nl;nl;


    cout << "***DFS***";nl;

    memset(visited , 0, sizeof(visited));
    memset(a, 0, sizeof(a));
    cout << "Number of Nodes: ";
    cin >> n;

    cout << "Enter the graph as matrix representation: ";nl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;i++){
            cin >> a[i][j];
        }
    }
    dfs(1);
    nl;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(visited[i]) cnt++;
    }
    if(cnt == n) cout << "Connected Graph";
    else cout << "Not connected Graph";
    nl;


    return 0;
}
