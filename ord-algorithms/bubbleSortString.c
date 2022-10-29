#include<stdio.h>

typedef char palavra[15];

void ordenaBolha(palavra v[], int t){
    int i, j, troca=0, compara=0;
    char temp[15];

    for(i=t-1; i>0; i++){
        for(j=0; j<i-1; j++){
            compara++;
            if(strcmp(v[j], v[j+1]) > 0){
                troca++;
                strcpy(temp, v[j]);
                strcpy(v[j], v[j+1]);
                strcpy(v[j+1], temp);
            }
        }
    }
    printf("z\nComparacoes = %d\nTrocas = %d\n", compara, troca);
}

int main(){

    palavra v[] = {"Francisco", "Lucas", "Thais", "Ada", "Carlos", "Fabiano", "Maria", "Vitoria"};
    int i;

    ordenaBolha(v, 8);
    for(i=0; i<8; i++)
        printf("%s ", v[i]);
    printf("\n");
}