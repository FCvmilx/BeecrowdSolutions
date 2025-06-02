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

long long Prim_MST(Grafo *G, int r) {
    int n = G->V;
    int *visited = (int *)malloc(n * sizeof(int));
    int *key     = (int *)malloc(n * sizeof(int));
    long long soma = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        key[i] = INF;
    }
    key[r] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int menor = INF;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < menor) {
                menor = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        soma += key[u];  // adiciona o peso da aresta que conecta u à MST

        for (int w = 0; w < n; w++) {
            int peso = G->adj[u][w];
            if (!visited[w] && peso < key[w]) {
                key[w] = peso;
            }
        }
    }

    free(visited);
    free(key);
    return soma;
}

int main() {

    int N;
    long long M;

    scanf("%d %lld", &N, &M);

    Grafo* G = criaGrafo(N);
    int O;
    scanf("%d", &O);

    for ( int i = 0; i < M; i++ ) {
        int U, V, D;
        scanf("%d %d %d", &U, &V, &D);
        insereAresta(G, U-1, V-1, D);

    }
    long long pesoMST = Prim_MST(G, O);

    long long resposta = 2LL * pesoMST;
    printf("%lld\n", resposta);


    for (int i = 0; i < G->V; i++) {
        free(G->adj[i]);
    }
    free(G->adj);
    free(G);
    return 0;
}
