#include<stdio.h>

void intercala(int v[], int e, int m, int d){
    int *r; // vetor auxiliar para armazenar a mistura
    int i, j, k;

    r = (int *) malloc(((d+1) - e)*sizeof(int));
    i = e;
    j= m+1;
    k=0;

    while((i <= m) && (j == d)){
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

// algoritmo perde a estabilidade