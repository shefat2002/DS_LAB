#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";

struct Node{
    int data;
    Node *link;
};

struct Marks{
    int student, subject, mark;
    Marks *next;
};

void insertion(int new_data, Node** head)
{
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head;
    new_node-> data = new_data;
    new_node->link = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(last->link != NULL){
        last = last->link;
    }
    last ->link = new_node;
}

void print(Node *node)
{
    while(node != NULL){
        cout << node->data << ' ';
        node = node->link;
    }
}

int maximum(Node* head)
{
    int mx = -9999999;
    Node* current = head;
    while(current != NULL){
        if(current ->data > mx){
            mx = current ->data;
        }
        current = current ->link;
    }
    return mx;
}

int minimum(Node* head)
{
    int mn = 99999999;
    Node* current = head;
    while(current != NULL){
        if(current ->data < mn){
            mn = current ->data;
        }
        current = current ->link;
    }
    return mn;
}

bool search(int x, Node* head)
{
    Node* current = head;
    while(current != NULL){
        if(current ->data == x){
            return true;
        }
        current = current ->link;
    }
    return false;
}

int frequency(int x, Node* head)
{
    int freq = 0;
    Node* current = head;
    while(current != NULL){
        if(current ->data == x){
            freq+=1;
        }
        current = current ->link;
    }
    return freq;
}

void print_even(Node *node)
{
    while(node != NULL){
        if(node->data %2 ==0) cout << node->data << ' ';
        node = node->link;
    }
}

void print_odd(Node *node)
{
    while(node != NULL){
        if(node->data %2) cout << node->data << ' ';
        node = node->link;
    }
}

void InsertMark(int sub, int stu , int mark, Marks** head)
{
    Marks *ins = (Marks*)malloc(sizeof(Marks));
    ins -> subject = sub;
    ins -> student = stu;
    ins -> mark = mark;
    ins -> next = NULL;

    if(*head == NULL){
        *head = ins;
        return;
    }
    else{
        Marks* c = *head;
        while(c->next != NULL){
            c = c->next;
        }
        c ->next = ins;
    }
}

double subavg(int i, Marks** head)
{
    double sum = 0;
    Marks* p = *head;
    while(p){
        if(p-> subject == i){
            sum +=(double)p ->mark;
        }
        p = p -> next;
    }
    return sum;
}

double stuavg(int i, Marks** head)
{
    double sum = 0;
    Marks* p = *head;
    while(p){
        if(p->student == i){
            sum +=(double) p ->mark;
        }
        p = p -> next;
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

    cout << "The values you have entered: ";
    print(head);
    nl;nl;

    cout << "The largest number: ";
    cout << maximum(head);
    nl;
    cout << "The smallest number: ";
    cout << minimum(head);
    nl;nl;

    cout << "Enter an number to search: ";
    int x;
    cin >> x;
    if(search(x, head)){
        cout << "Item found!";
    }
    else cout << "Item not found!";
    nl;nl;

    cout << "Enter a number to count it's frequency: ";
    cin >>x;
    cout << "Frequency of " << x << " is: " << frequency(x, head);

    nl;nl;

    cout << "Even Numbers: ";
    print_even(head);
    nl;

    cout << "Odd Numbers: ";
    print_odd(head);
    nl;nl;

    Marks *header = NULL;

    Marks *new_marks = (Marks*)malloc(sizeof(Marks));

    for(int i = 0 ; i < 5 ; i++){
        cout << "Enter Subject " << i+1 << " marks: ";
        for(int j = 0 ; j < 5 ;j++){
            int mark;
            cin >> mark;
            InsertMark(i,j,mark, &header);
        }
    }

    cout << "Enter a Subject(0-4) to find average mark: ";
    int m; cin >> m;
    double sum = 0, avg = 0;

    cout << "Average Mark of Subject " << m << ": " << subavg(m, &header)/5;
    nl;nl;
    cout << "Enter a Student(0-4) to find average mark: ";
    cin >> m;
    sum = 0, avg = 0;

    cout << "Average Mark of Student " << m << ": " << stuavg(m, &header)/5;
    nl;nl;

    return 0;
}
