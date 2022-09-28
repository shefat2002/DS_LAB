#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

void print(Node *head)
{
    while(head != NULL){
        cout <<head ->data << endl  ;
        head = head ->link;
    }
}

void insertAtBeginning(int x, Node head_ref)
{

    Node* new_node ;
    new_node = (Node*)malloc(sizeof(Node));

    new_node ->data = x;
    new_node -> link = NULL;

    new_node -> link = head_ref;
    head_ref = new_node;

}

int main()
{
    Node *head;
    head = (Node*)malloc(sizeof(Node));

    int x;
    cin >> x;
    insertAtBeginning(x, head);

    print(head);



    return 0;
}
