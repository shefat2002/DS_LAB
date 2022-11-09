#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define nl      cout << "\n";
#define fast    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void file();
/*----------------------------------------------------------------------------------------------------------------------------------------*/

///Using Array

void solve()
{
    int a[20],top = 0;
    for(int i = 0 ; i < 4 ; i++){
        cin >> a[i];
        top++;
    }
    cout << "Stack elements: ";
    for(int i = 0 ; i <top ; i++){
        cout << a[i] << ' ';
    }
    cout << top-1;
    nl;

    int x;
    cout << "Push: ";
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> a[top];
        top++;
    }
    cout << "After Push: ";
    for(int i = 0 ; i <top ; i++){
        cout << a[i] << ' ';
    }
    cout << top-1;
    nl;

    cout << "Pop: ";
    cin >> x;
    for(int i = 0; i < x; i++){
        top--;
    }
    cout << "After Pop: ";
    for(int i = 0 ; i <top ; i++){
        cout << a[i] << ' ';
    }
    cout << top-1;
    nl;

    nl;
    fast;
    int n; cin >> n;
    int a[n];
    int f = 0 ,r =0;
    //initial value
    for(int i = 0; i < 5 ; i++){
        cin >> a[i];
        r++;
    }
    for(int i = 0 ; i< r ; i++){
        cout << a[i] << ' ';
    }
    nl;
    cout << f << ' ' << r-1;
    nl;

    //delete
    int del; cin >> del;
    f+=del;
    cout << f << ' ';
    for(int i = f ; i< r ; i++){
        cout << a[i] << ' ';
    }
    nl;
    
    //insert
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x ; cin >> x;
        a[r] = x;
        r++;
    }
    cout << r-1 << ' ';
    for(int i = f ; i < r ; i++){
        cout << a[i] << ' ';
    }
    nl;

}

//using linked list

///Task#01: Push and pop Operation in Linked List Representation
struct Stack
{
    int data;
    Stack *next;
};
Stack *top = NULL;

void push(int value)
{
    Stack *newStack;
    newStack = (Stack*)malloc(sizeof(Stack));
    newStack -> data = value;
    if(top == NULL)
        newStack -> next = NULL;
    else{
        newStack -> next = top;
    }
    top = newStack;
}

void pop()
{
    if(top ==NULL)
        cout << "No element to pop!";
    else{
        Stack *temp = top;
        int temp_data = top -> data;
        top = top ->next;
        free(temp);
    }
}

void display()
{
    if(top == NULL)
        cout << "No elements!";
    else{
        Stack *temp = top;
        while(temp ->next !=NULL){
            cout << temp-> data << ' ';
            temp = temp ->next;
        }
        cout << temp-> data << ' ';
    }
    nl;
}

void Stack()
{
    ///push
    for(int i = 0 ; i < 4 ; i++){
        int x;
        cin >> x;
        push(x);
    }
    ///display after push
    display();

    ///pop
    int p;
    cin >> p;
    while(p--)
        pop();

    ///display after pop
    display();
}

///Task#02: Enqueue and dequeue operations in Linked List Representation

struct Queue
{
    int data;
    Queue *next;
};

Queue *front = NULL, *rear = NULL;

void insert(int item)
{
    Queue *ptr;
    ptr = (Queue*)malloc(sizeof(Queue));
    ptr -> data = item;
    ptr -> next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = ptr;
    }
    else{
        rear -> next = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    if(front == NULL){
        cout << "Overflow"; nl;
        return;
    }
    else{
        Queue *temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
    }

}

void QueueDisp()
{
    Queue *tempq;
    if(front == NULL && rear == NULL){
        cout << "Queue is empty!";
    }
    else{
        tempq = front;
        while(tempq){
            cout << tempq -> data << ' ';
            tempq = tempq ->next;
        }
    }
    nl;
}

void Queue()
{

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        insert(x);
    }
    QueueDisp();

    cin >> n;
    while(n--)
        dequeue();

    QueueDisp();
}


//Infix to Postfix and prefix

char Stack[N];
int top =-1;



int isEmpty(){
    return top == -1;
}
int isFull(){
    return top == N - 1;
}

char peek(){
    return Stack[top];
}
char pop()
{
    if(isEmpty()) return -1;
    char c = Stack[top];
    top--;
    return c;
}
void push(char c)
{
    if(isFull()){}
    else{
        top++;
        Stack[top] = c;
    }
}


int operand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int priority(char c)
{
    switch(c){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int InfixToPostfix(char* s)
{
    int j = -1;
    for (int i = 0; s[i]; ++i)
    {

        if (operand(s[i]))
            s[++j] = s[i];

        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(s[i]);
        else if (s[i]==')' || s[i]=='}'  || s[i]==']')
        {
            if(s[i]==')'){
                while (!isEmpty() && peek() != '(') s[++j] = pop();
                pop();
            }
            if(s[i]==']'){
                while (!isEmpty() && peek() != '[')
                    s[++j] = pop();
                pop();
            }
           if(s[i]=='}'){
                while (!isEmpty() && peek() != '{')
                    s[++j] = pop();
                pop();
            }
        }
        else {
            while (!isEmpty() && priority(s[i]) <= priority(peek()))
                s[++j] = pop();
            push(s[i]);
        }

    }
    while(!isEmpty()) s[++j] = pop();
    s[++j] = '\0';
    //cout << s;
}

void reverse(char *s){

    int size = strlen(s);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(s[i]!='\0')
    {
        temp[j] = s[i];
        j--;
        i++;
    }
    strcpy(s,temp);
}
void brackets(char* s){
    int i = 0;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
        i++;
    }
}
void InfixToPrefix(char *s){

    int size = strlen(s);

    reverse(s);
    brackets(s);
    InfixToPostfix(s);
    reverse(s);
}


int main()
{
    //fast;
    //file();
    solve();
    nl;
    Stack();
    Queue();
    
    return 0;
}

void file()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r", stdin);
    freopen("out.txt" , "w", stdout);
    #endif
}
