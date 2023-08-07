#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A > B)
#define exch(A, B) {int aux = A; A = B; B=aux;}
int valorNulo = -1;

typedef struct fila{
    int *pq;
    size_t tamanho, capacidade;
}fila;

void fixUp(int *pq, int i){
    for (; i > 1 && less(pq[i/2], pq[i]); i/=2)
        exch(pq[i], pq[i/2]);
}

void fixDown(int *pq, size_t tamanho, int i){
    for (int maior = i * 2; i * 2 <= tamanho; i = maior, maior = i * 2){
        if (maior < tamanho && less(pq[maior], pq[maior + 1])) maior++;
        if (!less(pq[i], pq[maior])) break;
        exch(pq[i], pq[maior]);
    }
}

fila PQinit(size_t capacidade){
    fila PQ = {.capacidade = capacidade, .tamanho = 0};
    PQ.pq = malloc((capacidade + 1) * sizeof(int));
    return PQ;
}

void PQfree(fila PQ){
    free(PQ.pq);
}

int PQEmpty(fila PQ){
    return PQ.tamanho == 0;
}

void PQGaranteCapacidade(fila *PQ, size_t newCapacidade){
    if (newCapacidade <= PQ->capacidade) return;
    PQ->capacidade *= 4;
    PQ->pq = realloc(PQ->pq, (PQ->capacidade + 1) * sizeof(int));
}

void PQinsert(fila *PQ, int x){
    PQGaranteCapacidade(PQ, PQ->tamanho + 1);
    PQ->pq[++PQ->tamanho] = x;
    fixUp(PQ->pq, PQ->tamanho);
}

int PQespia(fila PQ){
    return PQ.pq[1];
}

int PQdelmax(fila *PQ){
    if (PQEmpty(*PQ)) return valorNulo;
    int x = PQespia(*PQ);
    PQ->pq[1] = PQ->pq[PQ->tamanho--];
    fixDown(PQ->pq, PQ->tamanho, 1);
    return x;
}

int main(int argc, char const *argv[]){

    fila pq = PQinit(16);
    int operacao, numero, v[100];

    while (scanf(" %d %d", &operacao, &numero) == 2){
        if (operacao == 1)
            PQinsert(&pq, numero);
        else{
            int j;
            for (j = 0; j < numero; j++){
                int x = PQdelmax(&pq);
                if (x == valorNulo) break;
                v[j] = x;
            }
            for (int i = 0; i < j; i++){
                printf("%d%c", v[i], " \n"[i == j-1]);
                PQinsert(&pq, v[i]);
            }
        }
    }
    PQfree(pq);
    
    return 0;
}
