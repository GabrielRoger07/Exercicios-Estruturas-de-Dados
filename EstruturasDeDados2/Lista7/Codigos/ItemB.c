#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V, E, **adj;
}Graph;

typedef struct Edge{
    int v, w;
}Edge;

Edge EDGE(int v, int w){
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

int **MATRIXinit(int V, int valorInicial){
    int **matrix = malloc(V*sizeof(int*));

    for(int i = 0; i < V; i++){
        matrix[i] = malloc(V*sizeof(int));
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            matrix[i][j] = valorInicial;
        }
    }
    return matrix;
}

Graph *graphInit(int V){
    Graph *G = malloc(sizeof(Graph));
    G->V = V;
    G->E = 0;
    G->adj = MATRIXinit(V, 0);
    return G;
}

int pre[5001];

void graphInsertE(Graph *G, Edge e){
    int v = e.v, w = e.w;

    if(G->adj[v][w] == 0){
        G->E++;
    }
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void dfsR(Graph *G, Edge e){
    int v = e.v, w = e.w;
    pre[w] = 1;
    for(v = 0; v < G->V; v++){
        if(pre[v] == 0 && G->adj[w][v]){
            dfsR(G, EDGE(w, v));
        }
    }
}

int compConexos(Graph *G){
    int quantConexos = 0;
    for(int i = 0; i < G->V; i++){
        if(pre[i] == 0){
            dfsR(G, EDGE(i, i));
            quantConexos++;
        }
    }
    return quantConexos;
}

int main(int argc, char const *argv[]){
    
    int quantCidades, estradaV, estradaW;
    scanf("%d", &quantCidades);
    Graph *grafo = graphInit(quantCidades);
    memset(pre, 0, sizeof(int)*5001);

    while(scanf("%d %d", &estradaV, &estradaW) != EOF){
        Edge aresta = EDGE(estradaV, estradaW);
        graphInsertE(grafo, aresta);
    }
    printf("%d\n", compConexos(grafo));

    return 0;
}
