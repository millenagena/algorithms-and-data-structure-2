#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include "metodos_ord.h"

#define TAM_1 10000
#define TAM_2 25000
#define TAM_3 50000
#define TAM_4 75000
#define TAM_5 100000

struct Transacao{
    char cpf[20];
    int numero_transacao;
    double valor_transacao;
};
typedef struct Transacao Transacao;

void intercala(int v[], int e, int m, int d){
    int *r; // vetor auxiliar para armazenar a mistura
    int i, j, k;

    r = (int *) malloc(((d+1) - e)*sizeof(int));
    i = e;
    j= m+1;
    k=0;

    while((i <= m) && (j <= d)){
        if(v[i] <= v[j]){
            r[k] = v[j];
            i++;
        }else{
            r[k]=v[j];
            j++;
        }
        k++;
    }

    while(i<=m){
        r[k] = v[i];
        i++;
        k++;
    }

    while(j<=d){
        r[k] = v[j];
        j++;
        k++;
    }

    for(i=e; i<=d; i++){
        v[i]=r[j];
        j++;
    }

    free(r);
}

void mergeSort(int v[], int left, int right) {   
        
    if (left >= right)
        return;
        
    else {
        int m = (left + right) / 2;
        mergeSort(v, left, m);
        mergeSort(v, m + 1, right);
        intercala(v, left, m, right);
    }
    
}

int main(){
    Transacao transacoes_1_merge_sort[TAM_1];
    // Transacao transacoes_2[TAM_2];
    // Transacao transacoes_1[TAM_1];
    // Transacao transacoes_3[TAM_3];
    // Transacao transacoes_4[TAM_4];
    // Transacao transacoes_5[TAM_5];
    srand(time(NULL));

    // Gera um cpf aleatório
    int *cpf_int;
    cpf_int = cpf_generator();

    // insercao aleatoria
    for (int i = 0; i < TAM_1; i++){
        int num_transacao = rand() % 10000;
        double valor_transacao = (double) num_transacao / 100;

        int *cpf_int;
        char cpf_char[11];

        transacoes_1_merge_sort[i].numero_transacao = num_transacao;
        transacoes_1_merge_sort[i].valor_transacao = valor_transacao;
    }

    // ordenacao
    clock_t tic5 = clock();
    mergesort_int(transacoes_1_merge_sort, 0, TAM_1 - 1);
    clock_t toc5 = clock();

    printf("merge_sort: %f seconds\n", (double)(toc5 - tic5) / CLOCKS_PER_SEC);

    return 0;
}