#include <bits/stdc++.h>
#define mdc(a, b) (__gcd((a), (b)))

using namespace std;

int main() {

    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long f1, f2;
        cin >> f1 >> f2;
        cout << mdc(f1, f2) << '\n';
    }
    return 0;
}
