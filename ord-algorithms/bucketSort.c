#include<stdio.h>

void insertionSort(int v[], int tam){
    int i, j, aux;

    for(i=1; i<tam; i++){
        j = i; //elem que quero inserir ordenado
        while((j>0) && (v[j]<v[j-1])){
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
    }
}

#define TAM 5
struct balde{
    int qtd;
    int valores[TAM];
};

void bucketSort(int *v, int n){
    int i, j, maior, menor, nroBaldes, pos;
    struct balde *bd;

    // acha maior e menor valor
    maior = menor = v[0];
    for(i=1; i<n; i++){
        if(v[i] > maior) maior = v[i];
        if(v[i] < menor) menor = v[i];
    }

    // inicializa baldes
    nroBaldes = (maior - menor) / TAM+1;
    bd = (struct balde *) malloc(nroBaldes * sizeof(struct balde));
    for(i=0; i<nroBaldes; i++)
        bd[i].qtd=0;
    
    // distribui os valores nos baldes
    for(i=0; i<n; i++){
        pos = (v[i] - menor) / TAM;
        bd[pos].valores[bd[pos].qtd] = v[i];
        bd[pos].qtd++;
    }

    // ordena baldes e coloca no array
    pos=0;
    for(i=0; i<nroBaldes; i++){
        insertionSort(bd[i].valores, bd[i].qtd);
        for(j=0; j<bd[i].qtd; j++){
            v[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
}