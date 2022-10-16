#include<stdio.h>

void ordSelecaoRec(int v[], int ini, int tam){
    int min, j, menor;

    if(ini == tam)
        return;
    else{
        min = ini;
        for(int i=ini+1; i<tam; i++){
            min =i;
        }
    menor = v[min];
    v[min] = v[ini];
    v[ini] = menor;
    ordSelecaoRec(v, ini+1, tam);
    }
}

int main(){
    int v1[]={5,3,6,2,7,8,1,4},
        v2[]={1,2,3,4,5,6,7,8,9,10},
        v3[]={5,4,3,2,1};
    int i;

    ordSelecaoRec(v1,0,8);
    for (i=0;i<8;i++) printf("%d ",v1[i]);
    printf("\n");

    ordSelecaoRec(v2,0,10);
    for (i=0;i<10;i++) printf("%d ",v2[i]);
    printf("\n");

    ordSelecaoRec(v3,0,5);
    for (i=0;i<5;i++) printf("%d ",v3[i]);
    printf("\n");
}