#include "metodos_ord.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_1 20
#define TAM_2 25000
#define TAM_3 50000
#define TAM_4 75000
#define TAM_5 100000

int main() {
  srand(time(NULL));
  listaTransacao *transacoes_1_quick_sort_int;
  listaTransacao *transacoes_1_heap_sort_int;
  listaTransacao *transacoes_1_counting_sort_int;
  
  listaTransacao *transacoes_1_heap_sort_float;
  listaTransacao *transacoes_1_quick_sort_float;

  listaTransacao *transacoes_aleatoria_base_TAM1;

  transacoes_1_quick_sort_int = cria_lista();
  transacoes_1_heap_sort_int = cria_lista();
  transacoes_1_counting_sort_int = cria_lista();
  
  transacoes_1_heap_sort_float = cria_lista();
  transacoes_1_quick_sort_float = cria_lista();

  transacoes_aleatoria_base_TAM1 = cria_lista();

  // insercao aleatoria
  insere_transacao_aleatorio(transacoes_aleatoria_base_TAM1, TAM_1);

  // for (int K = 0; K < 10; K++) {

  copia_lista(transacoes_aleatoria_base_TAM1, transacoes_1_quick_sort_int, TAM_1);
  copia_lista(transacoes_aleatoria_base_TAM1, transacoes_1_heap_sort_int, TAM_1);
  copia_lista(transacoes_aleatoria_base_TAM1, transacoes_1_counting_sort_int,TAM_1);
  
  copia_lista(transacoes_aleatoria_base_TAM1, transacoes_1_quick_sort_float,TAM_1);
  copia_lista(transacoes_aleatoria_base_TAM1, transacoes_1_heap_sort_float,TAM_1);

  // ===== TAM_1 =====
  // ======== INT ========

  // ordenacao quick sort basico
  // quick_sort_int(transacoes_1_quick_sort_int, 0, TAM_1 - 1);

  // ordenacao heap sort
  // heap_sort_int(transacoes_1_heap_sort_int, TAM_1 - 1);

  // ordenacao counting sort
  imprime_lista(transacoes_1_counting_sort_int);
  printf("\n\nLISTA ORDENADA COM COUNTING SORT\n");
  counting_sort(transacoes_1_counting_sort_int, TAM_1);
  imprime_lista(transacoes_1_counting_sort_int);

  // ======== FLOAT ========
  // ordenacao quick sort basico
  // quick_sort_float(transacoes_1_quick_sort_float, 0, TAM_1 - 1);

  // ordenacao heap sort
  // heap_sort_float(transacoes_1_heap_sort_float, TAM_1 - 1);
  

  // ===== TAM_2 =====


  // }

  return 0;
}
