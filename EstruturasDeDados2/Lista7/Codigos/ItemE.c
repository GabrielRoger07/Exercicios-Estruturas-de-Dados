#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    int V;
    int E;
    int **adj;
}Graph;

typedef struct Edge{
    int v;
    int w;
}Edge;

Edge EDGE(int v, int w){
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

int **MATRIXinit(int V, int x){
    int **matrix = malloc(V*sizeof(int*));

    for(int i = 0; i < V; i++)
        matrix[i] = malloc(V*sizeof(int));
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++)
            matrix[i][j] = x;

    }
    return matrix;
}

Graph *GraphInit(int v){
    Graph *G = malloc(sizeof(Graph));
    G->V = v;
    G->E = 0;
    G->adj = MATRIXinit(v, 0);
    return G;
}

void graphInsertE(Graph *G, Edge e){
    int v = e.v, w = e.w;
    if(G->adj[v][w] == 0)
        G->E++;

    G->adj[v][w] = 1;
}

void verificaConex(Graph *G, int **c){
    for(int i = 0; i < G->V; i++){
        for(int j = 0; j < G->V; j++){
            if(G->adj[i][j] != 0){
                c[i][j] = 1;
            } else{
                c[i][j] = 0;
            }
        c[i][i] = 1;
        }
    }

    for(int i = 0; i < G->V; i++){
        for(int j = 0; j < G->V; j++){
            if(c[j][i] == 1){ 
                for(int k = 0; k < G->V; k++){
                    if(c[i][k] == 1)
                        c[j][k] = 1;
                
                }
            }
        }
    }
}

void solve(){
    int n, m;
    scanf("%d", &n);
    if(n == 0){
        return;
    }

    scanf("%d", &m);

    Graph *G = GraphInit(n);

    int v, w, p;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &v, &w, &p);
        v--;
        w--;

        Edge E1 = EDGE(v, w);
        graphInsertE(G, E1);
        if(p == 2){ 
            Edge E2 = EDGE(w, v);
            graphInsertE(G, E2);
        }
    }

    int **conex = MATRIXinit(n, 0);

    verificaConex(G, conex);

    for (int i = 0; i < G->V; i++){
        free(G->adj[i]);
    }
    free(G->adj);

    int conexo = 1;
    for(int i = 0; i < n && conexo==1; i++){
        for(int j = 0; j < n && conexo==1; j++){
            if(conex[i][j] == 0){ 
                conexo = 0;
            }
        }
    }

    printf("%d\n", conexo);

    solve();
}

int main(void){
    solve();

    return 0;
}
