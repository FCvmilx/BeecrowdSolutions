// o algoritmo abaixo pode ser encontrado em https://pc.oberlan.com/ed2/#otimizacoes-do-union-find
// acesse o link para mais informações
#include <stdio.h>

#define endl '\n'




#define MAXN 100
long long pai[MAXN];
long long tamanho[MAXN];

long long nComponentes = 0;

void init(long long N) {
    nComponentes = N;
    for (long long i = 0; i <= N; i++) {
        pai[i] = i;
        tamanho[i] = 1;
    }
}

long long find(long long x) {
    if(x == pai[x])
        return x;
    else
        return pai[x] = find(pai[x]);
}
void join(long long a, long long b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (tamanho[a] < tamanho[b]) {
            // swap a e b manualmente
            long long temp = a;
            a = b;
            b = temp;
        }
        pai[b] = a;
        tamanho[a] += tamanho[b];
        nComponentes--;
    }
}


int main() {
	long long T;
	scanf("%lld", &T);
	for (long long i = 0; i < T; i++) {
		long long N, M;
		scanf("%lld %lld", &N, &M);
		init(N);

		for (long long j = 0; j < M; j++) {
			long long X, Y;
			scanf("%lld %lld", &X, &Y);
			join(X, Y);
		}
		if (nComponentes == 1) printf("Caso #%lld: a promessa foi cumprida\n", i + 1);
		else printf("Caso #%lld: ainda falta(m) %lld estrada(s)\n", i + 1, nComponentes - 1);
		}


	return 0;
}
