#include <stdio.h>

int quant = 0;
void contaSete(char *num, int i){
    if(num[i] != '\0'){
        if(num[i] == '7'){
           quant++; 
        }
        contaSete(num, i+1);
    }else{
        return;
    }
}

int main(int argc, char const *argv[]){
    char numero[13];

    scanf(" %s", numero);
    contaSete(numero, 0);
    printf("%d", quant);
    return 0;
}
