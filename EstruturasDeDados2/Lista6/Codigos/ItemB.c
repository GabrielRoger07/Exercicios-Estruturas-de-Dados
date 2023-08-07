#include <stdio.h>
#include <stdlib.h>

#define min(A, B) (A < B ? A : B)
#define max(A, B) (B < A ? A : B)
#define key(A) (A->valor)
#define less(A, B) (key(A) > key(B))
#define exch(A, B) {Item aux = A; A = B; B = aux;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

struct Item{
    int indice;
    int valor;
};

typedef struct Item *Item;
Item NULL_ITEM = NULL;

typedef struct fila{
    Item *heap;
    size_t tamanho, capacidade;
} fila;

int main(int argc, char const *argv[]){
    int n, k;
    while(scanf("%d %d", &n, &k) == 2 && n!=0 && k!=0){
        resolve(n, k);
    }
    return 0;
}

void fixUp(Item *heap, int i){
    for (; i > 1 && less(heap[i / 2], heap[i]); i /= 2){
        exch(heap[i], heap[i / 2]);
        heap[i]->indice = i;
        heap[i / 2]->indice = i / 2;
    }
}

void fixDown(Item *heap, size_t tamanho, int i){
    for (int maior = i * 2; i * 2 <= tamanho; i = maior, maior = i * 2){
        if (maior < tamanho && less(heap[maior], heap[maior + 1])) maior++;
        if (!less(heap[i], heap[maior])) break;
        exch(heap[i], heap[maior]);
        heap[i]->indice = i;
        heap[maior]->indice = maior;
    }
}

fila PQinit(size_t capacidade){
    fila pq = {.capacidade = capacidade, .tamanho = 0};
    pq.heap = malloc((capacidade + 1) * sizeof(Item));
    return pq;
}

void PQfree(fila pq){
    free(pq.heap);
}

int PQEmpty(fila pq){
    return pq.tamanho == 0;
}

void PQGaranteCapacidade(fila *pq, size_t CapacidadeAtualizada){
    if (CapacidadeAtualizada <= pq->capacidade) return;
    pq->capacidade *= 4;
    pq->heap = realloc(pq->heap, (pq->capacidade + 1) * sizeof(Item));
}

void PQinsert(fila *pq, Item x){
    PQGaranteCapacidade(pq, pq->tamanho + 1);
    pq->heap[++pq->tamanho] = x;
    x->indice = pq->tamanho;
    fixUp(pq->heap, pq->tamanho);
}

Item PQespia(fila pq){
    return pq.heap[1];
}

Item PQremove(fila *pq, int i){
    if (i < 1 || i > pq->tamanho) return NULL_ITEM;
    Item removido = pq->heap[i];
    pq->heap[i] = pq->heap[pq->tamanho--];
    fixDown(pq->heap, pq->tamanho, i);
    return removido;
}

void resolve(int n, int k){
    Item v = malloc(n * sizeof(struct Item));
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i].valor);
    fila pq = PQinit(k);
    for (int i = 0; i < k - 1; i++)
        PQinsert(&pq, &v[i]);
    for (int i = k - 1; i < n; i++){
        PQinsert(&pq, &v[i]);
        printf("%d%c", PQespia(pq)->valor, " \n"[i == n-1]);
        PQremove(&pq, v[i - k + 1].indice);
    }
    PQfree(pq);
}
