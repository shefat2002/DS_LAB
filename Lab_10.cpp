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

node* insert(node* root, int val)
{
    if(root == NULL) return newNode(val);
    if(val < root -> data) root ->lchild = insert(root ->lchild, val);
    else if(val > root -> data) root ->rchild = insert(root ->rchild, val);
    return  root;
}

node* minval(node *root)
{
    node* current = root;
    while(current && current ->lchild !=NULL) current = current ->lchild;
    return current;
}

node* deletion(node *root, int x)
{
    if(root == NULL) return root;
    if(x < root ->data) root ->lchild = deletion(root->lchild, x);
    else if(x > root ->data) root ->rchild = deletion(root ->rchild, x);
    else{
        if(root ->lchild == NULL && root ->rchild == NULL) return NULL;
        else if(root -> lchild == NULL){
            node *temp = root ->rchild;
            free(root);
            return temp;
        }
        else if(root -> rchild == NULL){
            node *temp = root ->lchild;
            free(root);
            return temp;
        }
        node *temp = minval(root -> rchild);
        root ->data = temp ->data;
        root ->rchild = deletion(root ->rchild, temp ->data);
    }
    return root;
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
    cout << "Enter a value to insert in BST:";
    cin >>n ;
    insert(root, n);
    nl;
    cout << "After insertion Ineorder travarsal: ";
    inorder(root); nl;

    cout << "Enter a value to delete from BST:";
    cin >>n ;
    deletion(root, n);
    nl;
    cout << "After deletion Ineorder travarsal: ";
    inorder(root); nl;
    
    return 0;
}
