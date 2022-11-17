#include <bits/stdc++.h>
using namespace std;

#define nl      cout << "\n";
#define N 21
/*---------------------------------------------------------------------------*/


int main()
{
    int tree[N] ={0,1,2,3,4,5,0,6,0,0,0,0,0,0,7,0,0,0,0,0,0};

    ///for(int i = 0 ; i < N ;i++) cin >> tree[i];


    ///root
    cout << tree[1] << endl;

    ///internal nodes
    for(int i=1; i < N ;i++){
        if((tree[i]!=0) && (tree[2*i] || tree[2*i+1])){
            //cout << tree[i] << " ";
            cout << tree[i] <<  "->" << "internal node";nl;
        }
    }
    nl;
    ///external nodes
    for(int i=1; i < N ;i++){
        if((tree[i] != 0) && tree[2*i] ==0 && tree[2*i+1]==0){
            //cout << tree[i] << " ";
            cout << tree[i] <<  "->" << "external node";nl;
        }
    }

    ///child
    cout << "Enter the value to print it's child:";
    int a; cin >> a;
    for(int i = 0; i < N ; i++){
        if(tree[i] == a && (tree[2*i] !=0 || tree[2*i+1] !=0)){
            if(tree[2*i] !=0 ) cout << tree[2*i] << ' ';
            if(tree[2*i+1] !=0 ) cout << tree[2*i+1];nl;
            break;
        }
    }

    ///siblings
    cout << "Enter the value to print it's siblings:";
    cin >> a;
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

    ///ancestor
    cout << "Ancestor: ";
    for(int i = 0 ; i< N ; i++){
        if((tree[2*i] || tree[2*i+1]) && tree[i] != 0) cout << tree[i] << ' ';
    }
    nl;

    ///descendant
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

    ///level
    int h;
    cout << "Level of each node:";
    for(int i = 1 ; i < N ;i++){
        if(tree[i] !=0) {
            cout << tree[i] << " -> "  >> "Level: " >> pow(2, 1/tree[i]) -1;nl;
            h = pow(2, 1/tree[i]) -1;
        }
    }
    nl;
    ///height
    cout << "Height of the tree: " << h;nl;


    return 0;
}
