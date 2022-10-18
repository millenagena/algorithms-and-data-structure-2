/*
Millena Gená Pereira
12111BCC055
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int vet[], int tam){
    int aux;
    for(int i=tam-1; i >= 1; i--) {
        for(int j=0; j < i ;j++) {
            if (vet[j+1] < vet[j]) {
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux; 
            }
        }
    }
}

void selectionSort(int *v, int tam){
    int troca=0, compara=0;
    for(int i=0; i<tam-1; i++){
        int i_menor = i;
        for(int j=i+1; j<tam; j++){
            compara++;
            if(v[j] < v[i_menor])
                i_menor = j;
        }
        troca++;
        int aux = v[i];
        v[i] = v[i_menor];
        v[i_menor] = aux;
    }
}

void insertionSort(int v[], int tam){
    for (int i = 1; i < tam; i++){
        int j = i;
        while((j > 0) && (v[j] < v[j-1]))
        {
            int aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j -= 1;
        }
    }
}

void troca(int v[], int i, int j){
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

int particao(int v[], int esq, int dir){
    int i, fim;
    fim=esq;
    for(i=esq+1; i<=dir; i++){
        if(v[i]<v[esq]){
            fim=fim+1;
            troca(v, fim, i);
        }
    }
    troca(v, esq, fim);
    return fim;
}

void quickSort(int v[], int esq, int dir){
    int i;
    if(esq >= dir)
        return;
    i = particao(v, esq, dir);
    quickSort(v, esq, i-1);
    quickSort(v, i+1, dir);
}

void intercala(int v[], int e, int m, int d)
{
    int *r; // vetor auxiliar para armazenar a mistura
    int i, j, k;
    r = (int *)malloc(((d + 1) - e) * sizeof(int));
    i = e;
    j = m + 1;
    k = 0;
    while ((i <= m) && (j <= d))
    { // intercala enquanto nenhuma das partes do vetor
        if (v[i] <= v[j])
        { // foi consumida totalmente
            r[k] = v[i];
            i++;
        }
        else
        {
            r[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        r[k] = v[i];
        i++;
        k++;
    } // termina de intercalar se sobrou à esquerda
    while (j <= d)
    {
        r[k] = v[j];
        j++;
        k++;
    } // termina de intercalar se sobrou à direita
    // Cópia do vetor auxiliar (contendo os dados ordenados) sobre o vetor original
    j = 0;
    for (i = e; i <= d; i++)
    {
        v[i] = r[j];
        j++;
    }
    free(r);
}

void mergeSort(int v[], int e, int d)
{
    int m;
    if (e < d)
    {
        m = (e + d) / 2;
        mergeSort(v, e, m);
        mergeSort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

void imprime(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
}

void abcSort(int v[], int i, int j){
    int k;
    if(v[i] > v[j])
        troca(v, i, j);
    if((i+1) >= j)
        return;
    k = (j-i+1)/3;
    abcSort(v, i, j-k);
    abcSort(v, i+k, j);
    abcSort(v, i, j-k);
}

#define TAM 100000
int main(){
    int i, valorGerado, a[TAM], b[TAM], c[TAM], d[TAM], e[TAM], f[TAM];

    printf("\n===== VETOR DE TAMANHO 100.000 =====\n");
    for(i=0; i<TAM; i++){ 
        valorGerado=rand()%10000;
        a[i] = valorGerado;
        b[i] = valorGerado;
        c[i] = valorGerado;
        d[i] = valorGerado;
        e[i] = valorGerado;
        f[i] = valorGerado;
    }
    
    clock_t begin = clock();
    bubbleSort(a, TAM);
    clock_t end = clock();
    printf("Bubble Sort: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    clock_t begin1 = clock();
    selectionSort(b, TAM);
    clock_t end1 = clock();
    printf("Selection Sort: %lf\n", (double)(end1 - begin1) / CLOCKS_PER_SEC);

    clock_t begin2 = clock();
    insertionSort(c, TAM);
    clock_t end2 = clock();
    printf("Insertion Sort: %lf\n", (double)(end2 - begin2) / CLOCKS_PER_SEC);

    clock_t begin3 = clock();
    quickSort(d, 0, TAM-1);
    clock_t end3 = clock();
    printf("Quick Sort: %lf\n", (double)(end3 - begin3) / CLOCKS_PER_SEC);

    clock_t begin4 = clock();
    mergeSort(e, 0, TAM-1);
    clock_t end4 = clock();
    printf("Merge Sort: %lf\n", (double)(end4 - begin4) / CLOCKS_PER_SEC);

    clock_t begin5 = clock();
    abcSort(f, 0, TAM-1);
    clock_t end5 = clock();
    printf("ABC Sort: %lf\n", (double)(end5 - begin5) / CLOCKS_PER_SEC);
}