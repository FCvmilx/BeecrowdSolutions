// o algoritmo abaixo pode ser encontrado em https://pc.oberlan.com/ed2/#otimizacoes-do-union-find
// acesse o link para mais informações
#include <stdio.h>
// #include <sys/time.h>

#define endl '\n'




#define MAXN 50000
long long pai[MAXN];
// long long tamanho[MAXN];

long long nComponentes;

void init(long long N) {
    nComponentes = N;
    for (long long i = 0; i <= N; i++) {
        pai[i] = i;
        // tamanho[i] = 1;
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
        // if (tamanho[a] < tamanho[b]) {
        //     // swap a e b manualmente
        //     long long temp = a;
        //     a = b;
        //     b = temp;
        // }
        pai[b] = a;
        // tamanho[a] += tamanho[b];
        nComponentes--;
    }
}


int main() {
    // struct timeval inicio, fim;
    // gettimeofday(&inicio, NULL);

    long long N, M;
    long long i = 0;
    scanf("%lld %lld", &N, &M);
    init(N);
    long long X, Y;
    while(i < M) {
        scanf("%lld %lld", &X, &Y);
        join(X, Y);

        i++;
    }
    printf("%lld\n", nComponentes);

    // gettimeofday(&fim, NULL);

    // double tempo_execucao = (fim.tv_sec - inicio.tv_sec) +
    //                         (fim.tv_usec - inicio.tv_usec) / 1e6;

    // printf("Tempo de execução: %.6f segundos\n", tempo_execucao);

	return 0;
}
