/*
- nao eh adaptavel, pois nao muda mesmo se o arquivo estiver parcialmente ordenado
- nao eh estavel, pois dependendo das trocas, esse algoritmo nao mantem a ordem relativa dos valores iguais
- eh in-place porque a ordenacao eh feita rearranjando os elementos no proprio array
- O(n²)
*/

#include<stdio.h>
#include<stdlib.h>

void troca(int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void ordSelecao(int v[], int tam){
    int minimo, menor;
    int trocas=0, compara=0;
    int i, j;

    for(i=0; i<tam-1; i++){
        minimo=i;
        for(j=i+1; j<tam; j++){
            if(v[j]<v[minimo])
                minimo=j;
        }
        //troca(v, minimo, j);
        menor = v[minimo];
        v[minimo] = v[i];
        v[i] = menor;
    }
}

int main(){
    int v1[]={5,3,6,2,7,8,1,4},
        v2[]={1,2,3,4,5,6,7,8,9,10},
        v3[]={5,4,3,2,1};
    int i;

    ordSelecao(v1,8);
    for (i=0;i<8;i++) printf("%d ",v1[i]);
    printf("\n");

    ordSelecao(v2,10);
    for (i=0;i<10;i++) printf("%d ",v2[i]);
    printf("\n");

    ordSelecao(v3,5);
    for (i=0;i<5;i++) printf("%d ",v3[i]);
    printf("\n");
}