#include <iostream>
 
using namespace std;
 
int main() {
 
    string nome;
    double s, v;
    cin >> nome >> s >> v;
    
    printf("TOTAL = R$ %.2f\n", s + (15*v)/100);
 
    return 0;
}
