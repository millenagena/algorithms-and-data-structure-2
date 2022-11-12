#include<stdio.h>
#include<stdlib.h>

int pivo_aleatorio(int esq, int dir){
    double r;
    r = (double) rand()/RAND_MAX;
    return (int) (esq + r*(dir-esq));
}

void troca(int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int esq, int dir){
    int i, pivo;
    pivo = esq;
    for(i = esq+1; i<=dir; i++){
        if(v[i] < v[esq]){
            pivo += 1;
            troca(v, pivo, i);
        }
    }
    troca(v, esq, pivo);
    return pivo;
}

void quickSort_aleatorizado(int v[], int esq, int dir){
    int i;
    if(dir <= esq) return;
    troca(v, pivo_aleatorio(esq, dir), esq);

    i = particao(v, esq, dir);
    quickSort_aleatorizado(v, esq, i-1);
    quickSort_aleatorizado(v, i+1, dir);
}