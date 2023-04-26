#include <bits/stdc++.h>
using namespace std;

int main() {

    int c, n;
    double v, valor_final;
    cin >> c >> n >> v;
    valor_final = n*v;
    cin >> c >> n >> v;
    valor_final += n*v;
    
    printf("VALOR A PAGAR: R$ %.2f\n", valor_final);
    
    return 0;
}
