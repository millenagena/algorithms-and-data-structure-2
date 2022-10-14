#include<stdio.h>
#include<stdlib.h>

void metodoBolha(int vet[], int tam){
    int aux;
    for(int i=tam-1; i >= 1; i--) {
        for(int j=0; j < i ;j++) {
            if (vet[j+1] < vet[j]) {
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux; 
            }
        }
    }
}

int main(){
    int vet[100], qntd, i;
    
    // informa quantidade de numeros
    scanf("%d", &qntd);

    // informa os numeros do vetor
    for(i=0; i<qntd; i++){
        scanf("%d", &vet[i]);
    }

    // ordenando pelo metodo bolha
    metodoBolha(vet, qntd);

    // printando os elementos ordenados
    for(i=0; i<qntd; i++){
        printf("\n%d ", vet[i]);
    }
}