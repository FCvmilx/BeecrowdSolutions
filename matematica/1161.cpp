#include <bits/stdc++.h>

using namespace std;

vector<long long> facts(21, 0);

long long fatorial(int n) {
    if(n == 1 || n == 0) return 1;
    if(facts[n]) return facts[n];
    facts[n] = n * fatorial(n-1);
    return facts[n];
}

int main()
{
    
    int a, b;
    while(cin >> a >> b){
        cout << fatorial(a) + fatorial(b) << endl;
    }

    return 0;
}
