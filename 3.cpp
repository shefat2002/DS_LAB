#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";



int main()
{
    int a;
    int tree[] ={0,1,2,3,4,5,0,6,0,0,0,0,0,0,7,0};

    int N = sizeof(tree)/ sizeof(tree[0]);

    //internal nodes
    cout << "internal nodes: ";nl;
    for(int i=1; i < N ;i++){
        if((tree[i]!=0) && (tree[2*i] || tree[2*i+1])){
            //cout << tree[i] << " ";
            cout << tree[i] <<  "->" << "internal node";nl;
        }
    }
    nl;
    ///external nodes
    cout << "external nodes: ";
    for(int i=1; i < N ;i++){
        if((tree[i] != 0) && tree[2*i] ==0 && tree[2*i+1]==0){
            cout << tree[i] <<  " ";
        }
    }
    nl;
    ///siblings
    cout << "Enter a value to find it's siblings:";
    cin >> a;
    cout << "Siblings of " << a << ": ";
    for(int i = 0; i < N ;i++){
        if(tree[i] ==a){
            int p;
            if(i % 2){
                p = (i-1)/2;
                if(p%2 && tree[2*p] !=0) cout << tree[2*p] << ' ';
                else if(p%2 ==0 && tree[2*p+1] !=0) cout << tree[2*p+1];
            }
            else{
                p = i/2;
                if(p%2 && tree[2*p+1] !=0) cout << tree[2*p+1] << ' ';
                else if(p%2 ==0 && tree[2*p] !=0) cout << tree[2*p];
            }


        }
    }
    nl;
    ///ancestor
    cout << "Ancestor: ";
    for(int i = 0 ; i< N ; i++){
        if((tree[2*i] || tree[2*i+1]) && tree[i] != 0) cout << tree[i] << ' ';
    }
    nl;

    ///descendant
    cout << "descendant: ";
    for(int i = 1 ; i < N ; i++){
        if((tree[i] != 0) && tree[2*i] ==0 && tree[2*i+1]==0){
            //cout << tree[i] << " ";
            cout << tree[i] << ' ';
        }
    }
    nl;

    ///generation
    cout << "Enter a generation: ";
    cin >> a;
    for(int i = pow(2,a-1) ; i < pow(2, a) ;i++){
        if(tree[i] !=0) cout << tree[i] << ' ';
    }
    nl;
    ///level
    int h;
    cout << "Level of each node:";nl;
    cout << 1 << " -> " << 0;nl; 
    for(int i = 2 ; i < N ;i++){
        if(tree[i] !=0) {
            int l = floor(sqrt(i));
            cout << tree[i] << " -> " << l ;nl;
            h = l;
        }
    }
    nl;
    ///height
    cout << "Height of the tree: " << h;nl;


}