int encaixa(int a, int b){
    int quantidadeA = 0, quantidadeB =0, quantDigitos = 0;
    int retorno, armazenaNum, potencia = 1;
    int equalizaCasa;

    armazenaNum = b;
    while(b>=1){
        b=b/10;
        quantDigitos++;
    }

    b = armazenaNum;

    for(int i = 0; i<quantDigitos; i++){
        potencia = 10*potencia;
    }
    equalizaCasa = a%potencia;

    if(equalizaCasa == b){
        retorno = 1;
    }else{
        retorno = 0;
    }

    return retorno;
}