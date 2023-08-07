#include <stdio.h>

int main(int argc, char const *argv[])
{
    int B, T;
    float area;
    int resultado;

    scanf("%d", &B);
    scanf("%d", &T);

    if(B == 0 || T == 0 ){
        if(B == 0 && T != 0 ){
            area = 35*T;
        }
        if(B != 0 && T == 0 ){
            area = 35*B;
        }      
    }else if(B == T){
            area = 70*B;
    }else{
            area = (B+T)*35;
    }

    if(area == 5600){
        resultado =0;
    }
    if(area > 5600){
        resultado =1;
    }
    if(area < 5600){
        resultado =2;
    }
    printf("%d", resultado);


    return 0;
}
