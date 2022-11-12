#define MAX 20
struct Transacao {
  int numero_transacao;
  double valor_transacao;
  char cpf[20];
};
typedef struct Transacao transacao;

struct listaTransacao {
  transacao no[MAX];
  int fim;
};
typedef struct listaTransacao listaTransacao;

listaTransacao *cria_lista();
int lista_vazia(listaTransacao *lst);
int lista_cheia(listaTransacao *lst);
int insere_transacao(listaTransacao *lst, char *cpf, int numero_transacao,
                     double valor_transacao);
int insere_transacao_aleatorio(listaTransacao *lst, int tam);
int copia_lista(listaTransacao *listabase, listaTransacao *listaDestino,
                int tam);
void imprime_lista(listaTransacao *lst);

//void merge_sort_int(listaTransacao *v, int e, int d);
//void shell_sort_int(listaTransacao *lst, int n);
void quick_sort_int(listaTransacao *lst, int esq, int dir);
void quick_sort_float(listaTransacao *lst, int esq, int dir);
void heap_sort_int(listaTransacao *lst, int fim);
void heap_sort_float(listaTransacao *lst, int fim);
void counting_sort(listaTransacao *lst, int n);
