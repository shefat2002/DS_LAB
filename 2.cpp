#include <bits/stdc++.h>
using namespace std;

#define nl cout << "\n";

int checkOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence (char ch)
{
  switch (ch)
    {
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

void infixtoprefix(string s)
{
    
}

int main()
{
    string s;
    cin >> s;
    
}