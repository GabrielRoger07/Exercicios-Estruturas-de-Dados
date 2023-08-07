#include <stdio.h>

int main(int argc, char const *argv[])
{
    int quantRegistros, quantAlunos = 0, repetido = 0;
    long long alunos[100000];
    long long registroInserido;

    scanf("%d", &quantRegistros);
    for(int i = 0; i < quantRegistros; i++){
        scanf("%lld", &registroInserido);
        for(int j = 0; j <= quantAlunos; j++){
            if(alunos[i] == alunos[j]){
                repetido++;
            }
        }
        if(repetido == 0){
            alunos[quantAlunos] = registroInserido;
            quantAlunos++;
        }
        repetido = 0;
    }
    printf("%d\n", quantAlunos);
    return 0;
}

int buscaBinaria(long long alunos[], long long numInserido){
    int meio, e = -1;
    long long d = numInserido;
        while(e != (d-1)){
            meio = (e+d)/2;
            if(numInserido > alunos[meio]){
                e = meio;
            }else{
                d = meio;
            }
        }
        if(numInserido == alunos[d]){
            //já existe
            return 0;
        }else{
            return 1;
        }
}
