#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";

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

int main()
{

    Node *newNode, *head;
    int data;

    head = (Node *)malloc(sizeof(Node));

    if(head == NULL) cout <<"Not enough memory";

    cout << "Enter Linked List Size: ";
    int n ;
    cin >> n;

    cout << "Enter value 1: ";
    cin >> data;

    head->data = data;
    head->link = NULL;

    Node* temp;
    temp = head;
    for(int i = 1 ; i < n ;i++){
        newNode= (Node*)malloc(sizeof(Node));
        if(head == NULL) cout <<"Not enough memory\n";

        cout << "Enter value " << i+1 << " : ";
        cin >> data;

        newNode->data = data;
        newNode->link = NULL;
        temp->link = newNode;
        temp = newNode;

    }

    print(head);



    printf("Insert a node at the beggining.\n");
    newNode = (Node *)malloc(sizeof(Node));
    cout << "Enter a value to insert at beginning: ";
    cin >> data;
    newNode->data = data;
    newNode->link = head;
    head = newNode;

    if(head == NULL)
    {
        cout << "List is empty\n";
    }

    temp = head;

    print(head);
    nl;



    cout << "Insert at the end: \n";
    Node *temp2=head;
    while((temp2!=NULL)&&(temp2->link !=NULL))

    temp2=temp2->link;

    newNode = (Node *)malloc(sizeof(Node));
    cout << "Enter a value to insert at beginning: ";
    cin >> data;
    newNode->data = data;
    newNode->link = NULL;
    temp2->link = newNode;
    if(head == NULL)
    {
        cout << "List is empty\n";
        return 0;
    }

    temp2 = head;

    print(head);

    cout << "Insert at a specific Position: \n";

    cout << "Enter position to insert: ";
    int pos; cin >> pos;
    cout << "Enter value: ";
    int x; cin >> x;


    newNode = (Node *)malloc(sizeof(Node));
    if(pos == head -> data){
        newNode -> link = head->link;
        head-> link = newNode;
    }
    else{
        Node *temp3 = head;
        while(temp3 -> data != pos){
            temp3 = temp3 -> link;
            if(temp3 == NULL){
                cout << "Can not insert!";
                return 0;
            }
        }
        newNode -> data = x;
        newNode -> link = temp3 ->link;
        temp3 -> link = newNode;
    }

    print(head);

    return 0;
}
