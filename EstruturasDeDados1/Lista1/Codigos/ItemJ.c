#include <stdio.h>

int tamanhoString(char string[]);
void separaCartas(int tamanho, char string[]);

typedef struct Cartas{
    char digitos[2];
    char naipe;
}Cartas;

Cartas cartas[52];
int j = 0;

int main(int argc, char const *argv[])
{
    int tamanho,j=0;
    char baralho[200];
    
    scanf("%s", &baralho);
    tamanho = tamanhoString(baralho);
    separaCartas(tamanho, baralho);
    contaCartas();

    return 0;
}
int tamanhoString(char string[]){
    int numCaracteres = 0;

    while(string[numCaracteres] != '\0'){
        numCaracteres++;
    }

    return numCaracteres;
}

void separaCartas(int tamanho, char string[]){
    

    for(int i = 0; i<tamanho-2; i=i+3){
        cartas[j].digitos[0] = string[i];
        cartas[j].digitos[1] = string[i+1];
        cartas[j].naipe = string[i+2];  
        j++;
    }

}
 void contaCartas(){
    int copas = 0, espadas = 0, ouros = 0, paus = 0;
    for(int i = 0; i< j; i++){
        switch(cartas[i].naipe){
            case 'C':
                copas++;
                break;
            case 'E':
                espadas++;
                break;
            case 'U':
                ouros++;
                break;
            default:
                paus++;
        }
    }

    for(int a = 0; a < j; a++){
        for(int b = 0; b < j; b++){
            if(a != b){
                if(cartas[a].digitos[0] == cartas[b].digitos[0] && cartas[a].digitos[1] == cartas[b].digitos[1]){
                    if(cartas[a].naipe == cartas[b].naipe){
                        switch(cartas[a].naipe){
                            case 'C':
                                copas=copas+14;
                                break;
                            case 'E':
                                espadas=espadas+14;
                                break;
                            case 'U':
                                ouros=ouros+14;
                                break;
                            default:
                                paus=paus+14;
                        }
                    }
                }
            }
        }
    }
    if(copas<=13){
        printf("%d\n", (13-copas));
    }else{
        printf("erro\n");
    }
    if(espadas<=13){
        printf("%d\n", (13-espadas));
    }else{
        printf("erro\n");
    }
    if(ouros<=13){
        printf("%d\n", (13-ouros));
    }else{
        printf("erro\n");
    }
    if(paus<=13){
        printf("%d\n", (13-paus));
    }else{
        printf("erro\n");
    }
 }