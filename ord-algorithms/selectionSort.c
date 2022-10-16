/*
- nao eh adaptavel, pois nao muda mesmo se o arquivo estiver parcialmente ordenado
- nao eh estavel, pois dependendo das trocas, esse algoritmo nao mantem a ordem relativa dos valores iguais
- eh in-place porque a ordenacao eh feita rearranjando os elementos no proprio array
- O(n²)
*/

#include<stdio.h>
#include<stdlib.h>

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

int main(){
    int tam=0, vet[tam];
    scanf("%d", &tam); // tamanho
    for(int i=0; i<tam; i++){
        scanf("%d", &vet[i]); // elementos
    }
    selectionSort(vet, tam);
    for(int i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}