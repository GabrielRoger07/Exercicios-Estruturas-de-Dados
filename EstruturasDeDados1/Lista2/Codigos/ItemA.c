#include <stdio.h>

float potencia(int a, int b){

    //if (a == 0 && b <= 0){
    //    return 0;
    if(b == 0){
        return 1;
    }else if(b < 0){
        return 1/potencia(a, -b);
    }else {
        return (float) a * potencia (a, b-1);
  }
}

int main(int argc, char const *argv[])
{
    int base, expoente;
    scanf("%d", &base);
    scanf("%d", &expoente);
    if(base == 0 && expoente <= 0){
        printf("indefinido");
    }else{
        printf("%.3f", potencia(base, expoente));
    }
    return 0;
}
