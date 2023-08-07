#include <stdio.h>
#include <stdlib.h>

#define key(A) (A.codigo)
#define less(A, B) (A.quantVotos == B.quantVotos ? key(A) > key(B) : A.quantVotos > B.quantVotos)
#define exch(A, B)  {candidato t = B; B = A; A = t;}
#define cmpexch(A, B) {if (less(B, A)) exch(A, B)}

typedef struct candidato{
    int codigo;
    int quantVotos;
} candidato;

candidato presidente[91], senador[901], federal[9001], estadual[90001];
int quantCandPres = 0, quantCandSen = 0, quantCandFed = 0, quantCandEst = 0;

int main()
{
    long long quantSenEleitos, quantFedEleitos, quantEstEleitos;
    scanf("%lld %lld %lld", &quantSenEleitos, &quantFedEleitos, &quantEstEleitos);

    int validos = 0, invalidos = 0, presporc = 0, votoLido, casas;
    while (scanf("%d%n", &votoLido, &casas) != EOF){ 
        if (votoLido < 0){
            invalidos++;
            continue;
        }

        switch (casas){ 
        case 3: 
            presidente[votoLido - 10].codigo = votoLido;
            presidente[votoLido - 10].quantVotos++;
            presporc++;
            break;
        case 4:
            senador[votoLido - 100].codigo = votoLido;
            senador[votoLido - 100].quantVotos++;
            break;
        case 5:
            federal[votoLido - 1000].codigo = votoLido;
            federal[votoLido - 1000].quantVotos++;
            break;
        default:
            estadual[votoLido - 10000].codigo = votoLido;
            estadual[votoLido - 10000].quantVotos++;
        }
        validos++;
    }

    for (int i = 0; i < 91; i++){
        if (presidente[i].quantVotos){
            presidente[quantCandPres++] = presidente[i];
        }   
    }
        
    for (int i = 0; i < 901; i++){
        if (senador[i].quantVotos){
            senador[quantCandSen++] = senador[i];
        }     
    }
        
    for (int i = 0; i < 9001; i++){
        if (federal[i].quantVotos){
            federal[quantCandFed++] = federal[i];
        }  
    }
        
    for (int i = 0; i < 90001; i++){
        if (estadual[i].quantVotos){
            estadual[quantCandEst++] = estadual[i];
        }
    }

    printf("%d %d\n", validos, invalidos);

    quicksort(presidente, 0, quantCandPres - 1);
    quicksort(senador, 0, quantCandSen - 1);
    quicksort(federal, 0, quantCandFed - 1);
    quicksort(estadual, 0, quantCandEst - 1);

    if ((double)presidente[0].quantVotos/presporc >= 0.51){
        printf("%d\n", presidente[0].codigo);
    } else{
        printf("Segundo turno\n");
    }   

    for (int i = 0; i < quantSenEleitos; i++){
        printf("%d%c", senador[i].codigo, " \n"[i == quantSenEleitos - 1]);
    }
        
    for (int i = 0; i < quantFedEleitos; i++){
        printf("%d%c", federal[i].codigo, " \n"[i == quantFedEleitos - 1]);
    }
        
    for (int i = 0; i < quantEstEleitos; i++){
        printf("%d%c", estadual[i].codigo, " \n"[i == quantEstEleitos - 1]);
    }

    return 0;
}

int separa(candidato *v, int l, int r)
{
    int i = l;
    candidato c = v[r];
    for (int j = l; j < r; j++){
        if (less(v[j], c)){
            exch(v[i], v[j]);
            i++;
        }
    }
    exch(v[i], v[r]);
    return i;
}

void quicksort(candidato *v, int l, int r){
    if (l >= r) return;
    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);
    int j = separa(v, l, r);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}
