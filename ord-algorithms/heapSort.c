#include<stdio.h>

void troca(int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int esq(int pos){
    return (pos*2)+1;
}

int dir(int pos){
    return (pos*2)+2;
}

int parent(int pos){
    return (pos-1)/2;
}

void heap_maximo_pos(int *A, int pos, int tam_heap){
    int e, d, maior;
    e = esq(pos);
    d = dir(pos);

    if((e <= tam_heap) && (A[e] > A[pos]))
        maior = e;
    else maior = pos;

    if((d <= tam_heap) && (A[d] > A[maior]))
        maior = d;
    
    if(maior != pos){
        troca(A, pos, maior);
        heap_maximo_pos(A, maior, tam_heap);
    }
}

void construir_heap_max(int *A, int fim){
    int i;
    for(i = (fim-1)/2; i>=0; i--){
        heap_maximo_pos(A, i, fim);
    }
}

void heapsort(int *A, int fim){
    int i, j, tam_heap;
    tam_heap = fim;
    construir_heap_max(A, fim);

    printf("\n\nHeap maximo:\n");
    for(i=0; i<=fim; i++)
        printf("%d ", A[i]);
    printf("\n");

    for(i=fim; i>=0; i--){
        troca(A, 0, i);
        tam_heap--;
        heap_maximo_pos(A, 0, tam_heap);
    }
}