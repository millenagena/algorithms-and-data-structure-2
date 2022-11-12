#include<stdio.h>
#include"metodos_ord.h"

int max_element(listaTransacao *lst, int tam){
  printf("aaaaaaa");
  int i=0, max;

  max = lst->no[i].numero_transacao;
  for(i=0; i<tam; i++){
    if(lst->no[i].numero_transacao > max)
      max = lst->no[i].numero_transacao;
  }
  
  return max;
}

void counting_sort(listaTransacao *lst, int n){
  
  int K = max_element(lst, n);
  int i, j, k;
  int baldes[K];
  //transacao aux;
  
  printf("\n\noi");
  for(i=0; i<n; i++)
    baldes[i] = 0;

  for(i=0; i<n; i++)
    baldes[lst->no[i].numero_transacao]++;

  for(i=0, j=0; j<K; j++){
    for(k=baldes[j]; k>0; k--){
      printf("%d ", j);
      lst->no[i++].numero_transacao = j;
    }
  }
  
}