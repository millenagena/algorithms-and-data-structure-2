#include<stdio.h>
#include<stdlib.h>

void troca(int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int esq, int dir){
    int i, pivo;
    pivo = esq;

    for(i=esq+1; i<=dir; i++){
        if(v[i]<v[esq]){
            pivo += 1;
            troca(v, pivo, i);
        }
    }
    troca(v, esq, pivo);
    return pivo;
}

void quickSort_mediana_tres(int v[], int esq, int dir){
    int i;
    if(dir <= esq) return;

    troca(v, (esq+dir)/2, esq+1);
    if(v[esq] > v[esq+1])
        troca(v, esq, esq+1);
    if(v[esq] > v[dir])
        troca(v, esq, dir);
    if(v[esq+1] > v[dir])
        troca(v, esq+1, dir);
    
    i = particao(v, esq, dir);
    quickSort_mediana_tres(v, esq, i-1);
    quickSort_mediana_tres(v, i+1, dir);
}