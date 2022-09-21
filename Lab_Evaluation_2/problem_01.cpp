#include <bits/stdc++.h>
using namespace std;
#define nl cout << "\n";
#define MAXINT 10000009

void sieve(int n)
{
    bool prime[n+10];
    memset(prime, true, sizeof(prime));

    for(int i = 2; i * i <= n; i++) {
        if(prime[i] == true) {
            for(int j = i * i; j <= n ; j+= i)
                prime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++)
        if (prime[i] == true)
            cout << i << " ";
}


int main()
{
    int n;
    cin >> n;
    sieve(n);
    nl;

    return 0;
}
