#include<stdio.h>

int max_element(int lst[], int tam){
  int i=0, max;

  max = lst[i];
  for(i=0; i<tam; i++){
    if(lst[i] > max)
      max = lst[i];
  }
  
  return max;
}
#define K 100

void countingSort(int *v, int n){
    int i, j, k;
    //int K = max_element(v, n);
    printf("%d ", K);
    int baldes[K];

    // preenche o vetor auxiliar com zeros
    // serve para contar quantas vezes cada valor ocorre
    for(i=0; i<K; i++){
        baldes[i] = 0;
    }

    // valor a ser ordenado é tratado como indice
    for(i=0; i<n; i++){
        baldes[v[i]]++;
    }

    // percorre o vetor auxiliar verificando quais valores existem e coloca no array ordenado
    for(i=0, j=0; j<K; j++){
        for(k=baldes[j]; k>0; k--){
            v[i++] = j;
        }
    }
}

int main(){
    int v1[]={5,3,6,2,7,8,1,4},
        v2[]={1,2,3,4,5,6,7,8,9,10},
        v3[]={5,4,3,2,1};
    int i;

    countingSort(v1,8);
    for (i=0;i<8;i++) printf("%d ",v1[i]);
    printf("\n");

    countingSort(v2,10);
    for (i=0;i<10;i++) printf("%d ",v2[i]);
    printf("\n");

    countingSort(v3,5);
    for (i=0;i<5;i++) printf("%d ",v3[i]);
    printf("\n");
}