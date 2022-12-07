#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";

struct Node{
    int data;
    Node *next;
};

void InsertAtTheBegin(int new_data, Node** head)
{
    Node* newNode;
    newNode -> data = new_data;
    newNode -> next = head;
    head = newNode;
}

void InsertAtTheend(int new_data, Node** head)
{
    Node* newNode;
    Node* last = *head;
    newNode-> data = new_data;
    newNode->next = NULL;

    while(last->next != NULL){
        last = last->next;
    }
    last ->next = newNode;
}

void insertion(int new_data, Node** head)
{
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    Node* last = *head;
    newNode-> data = new_data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last ->next = newNode;
}
void deletion(int x, Node** head)
{
    
}

int summation(Node *head)
{
    Node *nextNode = head;
    int sum=0;
    while(nextNode -> next != NULL){
        sum += nextNode -> data;
    }
    return sum;
}




int main()
{
    Node* head = NULL;

    cout << "Enter size: ";
    int n;
    cin >> n;

    cout << "Enter " << n << " numbers as input: ";
    while(n--){
        int x;
        cin >> x;
        insertion(x , &head);
    }
    InsertAtTheBegin(3, &head);
    
    InsertAtTheend(10, &head);
    cout << summation(head);nl;
    Deletion(3, &head);

    
}