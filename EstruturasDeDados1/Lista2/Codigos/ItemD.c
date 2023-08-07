long long int aux[90];

long int fibonacci(int n){
    aux[0] = 1;
    aux[1] = 1;
    if(aux[n-1] == 0){
        aux[n-1] = fibonacci(n-2) + fibonacci(n-1);
    }
    return aux[n-1];
}
