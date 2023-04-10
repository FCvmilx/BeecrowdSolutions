
#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef pair<int,int> pii;
typedef vector<ll> vll;


#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)



#define endl '\n'

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vll pai;
vll tamanho;

ll nComponentes;

void init(ll N) {
    pai.resize(N + 1);
    tamanho.resize(N + 1, 1);
    iota(pai.begin(), pai.end(), 0);
    nComponentes = N;
}

ll find(ll x) {
    if(x == pai[x])
        return x;
    else
        return pai[x] = find(pai[x]);
}
void join(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (tamanho[a] < tamanho[b])
            swap(a, b);
        pai[b] = a;
        tamanho[a] += tamanho[b];
        nComponentes--;
    }
}


int main() {
	FASTIO;
	ll T;
	cin >> T;
	FOR(i, 0, T) {
		ll N, M;
		cin >> N >> M;
		init(N);
		FOR(j, 0, M) {
			ll X, Y;
			cin >> X >> Y;
			join(X, Y);
		}
		if (nComponentes == 1) cout << "Caso #" << i + 1  << ":" << " a promessa foi cumprida" << endl;
		else cout << "Caso #" << i + 1  << ":" << " ainda falta(m) " << nComponentes - 1 << " estrada(s)" << endl;
	}


	return 0;
}