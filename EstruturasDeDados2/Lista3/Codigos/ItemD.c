#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int tamanhoVetor, quantBusca;
    scanf("%d", &tamanhoVetor);
    scanf("%d", &quantBusca);
    int *vetor = malloc(tamanhoVetor*sizeof(int));
    int *numBuscados = malloc(quantBusca*sizeof(int));

    for(int i = 0; i < tamanhoVetor; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < quantBusca; i++){
        scanf("%d", &numBuscados[i]);
    }
    buscaBinaria(vetor, numBuscados, quantBusca, tamanhoVetor);

    free(vetor);
    free(numBuscados);

    return 0;
}

void buscaBinaria(int *vetor, int *numBuscados, int quant, int tamV){
    int meio, e, d;
    for(int i = 0; i < quant; i++){
        e = -1;
        d = tamV;
        while(e != d-1){
            meio = (e+d)/2;
            if(numBuscados[i] <= vetor[meio]){
                d = meio;
                if(numBuscados[i] == vetor[meio]){
                    e = d-1;
                }  
            }else{
                e = meio;
            }
        }
        printf("%d\n", d);
    }
}
