int move(int *v, int i, int elem){
    if(i<0 || v[i] <= elem){
        return i;
    }
    v[i+1] = v[i];
    move(v, i-1, elem);
}

void ordena(int *v, int n){
    if(n <= 1){
        return;
    }
    ordena(v, n-1);
    int elem = v[n-1];
    int i = move(v, n-2, elem);
    v[i+1] = elem;
}
