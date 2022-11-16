#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n"
#define ll long long

//tree traversal
//binary search tree

struct node
{
    int data;
    node *lchild, *rchild;
};

node *newNode(int val)
{
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = val;
    temp -> lchild = temp ->rchild = NULL;
    return temp;
}

int search(node *root, int val)
{
    while(root != NULL){
        if(val > root ->data) root = root ->rchild;
        else if(val < root -> data ) root = root -> lchild;
        else return 1;
    }
    return 0;
}

void inorder(node *root)
{
    if(root == NULL) return ;
    inorder(root -> lchild);
    cout << root -> data << " ";
    inorder(root -> rchild);
}

void preorder(node *root)
{
    if(root == NULL) return ;

    cout << root -> data << " ";
    preorder(root -> lchild);
    
    preorder(root -> rchild);
}
void postorder(node *root)
{
    if(root == NULL) return ;
    postorder(root -> lchild);
    
    postorder(root -> rchild);
    cout << root -> data << " ";
}


int main()
{
    node *root = newNode(21);
    root ->lchild = newNode(16);
    root ->rchild = newNode(25);
    root -> lchild-> lchild =  newNode(10);
    root ->lchild->rchild =  newNode(18);
    root ->rchild->lchild =  newNode(22);
    root ->rchild->rchild = newNode(28);
    root ->lchild->lchild->lchild =  newNode(8);
    root ->lchild->lchild->rchild =  newNode(12);
    

    cout << "Preorder travarsal: ";
    preorder(root); nl;

    cout << "Ineorder travarsal: ";
    inorder(root); nl;
    cout << "Postorder travarsal: ";
    postorder(root); nl;

    cout << "Enter a value to search: ";
    int n; cin >> n;
    
    if(search(root,n)) cout << "Item found!\n";
    else cout << "Item Not Found\n";
    
    return 0;
}
