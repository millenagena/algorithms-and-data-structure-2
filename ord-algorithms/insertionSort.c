/*
- nao eh adaptavel, pois nao muda mesmo se o arquivo estiver parcialmente ordenado
- eh estavel, pois mantem a ordem relativa dos valores iguais
- eh in-place porque a ordenacao eh feita rearranjando os elementos no proprio array
- O(n²)
*/
#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *v, int tam){

    int i, j, aux;

    for(int i=1; i<tam; i++){
        aux = v[i];
        j = i-1;
        while((j >= 0) && (aux < v[j])){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

int main(){
    int tam=0, vet[tam];
    scanf("%d", &tam); // tamanho
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]); // elementos
    }
    insertionSort(vet, tam);
    for(int i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}