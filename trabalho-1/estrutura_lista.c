#include "metodos_ord.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

listaTransacao *cria_lista() {
  listaTransacao *lst;
  lst = (listaTransacao *)malloc(sizeof(listaTransacao));

  if (lst != NULL) {
    lst->fim = 0;
  }
  return lst;
}

int lista_vazia(listaTransacao *lst) {
  if (lst->fim == 0)
    return 1;
  else
    return 0;
}

int lista_cheia(listaTransacao *lst) {
  if (lst->fim == MAX)
    return 1;
  else
    return 0;
}

int insere_transacao(listaTransacao *lst, char *cpf, int numero_transacao,
                     double valor_transacao) {
  transacao t;
  if (lst == NULL || lista_cheia(lst) == 1) {
    return 0;
  }
  strcpy(t.cpf, cpf);
  t.numero_transacao = numero_transacao;
  t.valor_transacao = valor_transacao;
  lst->no[lst->fim] = t;
  lst->fim++;
  return 1;
}

int insere_transacao_aleatorio(listaTransacao *lst, int tam) {
  if (lst == NULL) {
    return 0; // falha na insercao
  }
  for (int i = 0; i < tam; i++) {
    int num_transacao = rand() % 10000;
    int val_transacao = rand() % 10000;
    double valor_transacao = (double)val_transacao / 100;
    lst->no[lst->fim].numero_transacao = num_transacao;
    lst->no[lst->fim].valor_transacao = valor_transacao;
    strcpy(lst->no[lst->fim].cpf, "12331");
    lst->fim++;
  }
  return 1; // sucesso na insercao
}

int copia_lista(listaTransacao *listabase, listaTransacao *listaDestino,
                int tam) {
  if (listabase == NULL || listaDestino == NULL) {
    return 0; // falha na copia
  }
  for (int i = 0; i < tam; i++) {
    listaDestino->no[listaDestino->fim].numero_transacao =
        listabase->no[i].numero_transacao;
    listaDestino->no[listaDestino->fim].valor_transacao =
        listabase->no[i].valor_transacao;
    strcpy(listaDestino->no[listaDestino->fim].cpf, listabase->no[i].cpf);
    listaDestino->fim++;
  }
  return 1; // sucesso na copia
}

void imprime_lista(listaTransacao *lst) {
  if (lst == NULL || lista_vazia(lst) == 1) {
    printf("\n Lista nula ou sem registros");
  } else {
    for (int i = 0; i < lst->fim; i++) {
      printf("\n CPF: %s -", lst->no[i].cpf);
      printf(" Numero transacao: %d -", lst->no[i].numero_transacao);
      printf(" Valor transacao: %.2lf", lst->no[i].valor_transacao);
    }
  }
}