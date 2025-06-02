#include <stdio.h>
#include <stdlib.h>

#define INF 100000

typedef struct grafo {
    int V;       // número de vértices
    int E;       // número de arestas
    int **adj;   // matriz de adjacência, adj[u][v] = peso (distância) ou INF
} Grafo;

int **alocaMatrizAdj(int r, int c, int val) {
    int i, j;
    int **m = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++) {
        m[i] = (int *)malloc(c * sizeof(int));
        for (j = 0; j < c; j++) {
            m[i][j] = val;
        }
    }
    return m;
}

Grafo *criaGrafo(int V) {
    Grafo *G = (Grafo *)malloc(sizeof(Grafo));
    G->V = V;
    G->E = 0;
    G->adj = alocaMatrizAdj(V, V, INF);
    return G;
}

void insereAresta(Grafo *G, int u, int v, int d) {
    if (u != v && G->adj[u][v] == INF) {
        G->adj[u][v] = d;
        G->adj[v][u] = d;
        G->E++;
    }
}

long long Prim_MST(Grafo *G) {
    int n = G->V;
    int visited[n], key[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        key[i] = INF;
    }
    key[0] = 0; 
    long long soma = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, menor = INF;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < menor) {
                menor = key[v];
                u = v;
            }
        }
       
        if (u == -1 || menor == INF) {
            return -1; 
        }
        visited[u] = 1;
        soma += menor;

        // relaxa vizinhos
        for (int w = 0; w < n; w++) {
            int peso = G->adj[u][w];
            if (!visited[w] && peso < key[w]) {
                key[w] = peso;
            }
        }
    }
    return soma;
}


int main() {

    int N;
    long long M;
    while(scanf("%d", &N) != EOF) {

        scanf("%lld", &M);

        Grafo* G = criaGrafo(N);

        for ( int i = 0; i < M; i++ ) {
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);
            insereAresta(G, A-1, B-1, C);

        }
        if (M < N - 1) {
            printf("impossivel\n");
            continue;
        }
        long long custo = Prim_MST(G);
        if (custo < 0) {
            printf("impossivel\n");
        } else {
            printf("%lld\n", custo);
        }


        for (int i = 0; i < G->V; i++) {
            free(G->adj[i]);
        }
        free(G->adj);
        free(G);
    }
    return 0;
}
