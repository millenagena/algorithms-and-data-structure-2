#include<stdio.h>
#include<stdlib.h>
#include"metodos_ord.h"

void intercala_int(int v[], int e, int m, int d){
    int *r; // vetor auxiliar dinâmico para armazenar a mistura
    int i, j, k;

    r = (int *)malloc(((d + 1) - e) * sizeof(int));

    i = e;
    j = m + 1;
    k = 0;

    while ((i <= m) && (j <= d))
    {
        if (v[i] <= v[j]){ //(trocar por <)
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

    while (i <= m){
        r[k] = v[i];
        i++;
        k++;
    }
    while (j <= d){
        r[k] = v[j];
        j++;
        k++;
    }

    // Copia do vetor auxiliar (contendo os dados ordenados) sobre o vetor original
    j = 0;
    for (i = e; i <= d; i++){
        v[i] = r[j];
        j++;
    }
    free(r);
    }

    void mergesort_int(int v[], int e, int d)
    {
        int m;
        if (e < d){
            m = (e + d) / 2;
            mergesort_int(v, e, m);
            mergesort_int(v, m + 1, d);
            intercala_int(v, e, m, d);
        }
}