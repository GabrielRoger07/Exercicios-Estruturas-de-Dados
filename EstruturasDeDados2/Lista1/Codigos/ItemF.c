#include <stdio.h>

long long verificaSete(long long num){   
    if(num < 1){
        return 0;
    }
    if(num%10 == 7){
        return 1 + verificaSete(num/10);
    }else{
        return verificaSete(num/10);
    }    
}

int main(int argc, char const *argv[])
{
    long long num;
    scanf("%lld", &num);
    printf("%lld\n", verificaSete(num));
    return 0;
}