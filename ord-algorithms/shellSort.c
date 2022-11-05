#include<stdio.h>
#include<stdlib.h>

void shellSort(int v[], int n){
    int i, j, h=1;
    int aux;

    // calculando o h inicial
    do{
        h = h*3+1;
    }while(h < n);

    do{
        h = (h-1)/3;
        for(i=h; i<n; i++){
            aux = v[i];
            j = i;

            // efetua comparacoes entre elementos com distancia h
            while(v[j-h] > aux){
                v[j] = v[j-h];
                j -= h;
                if(j<h)
                    break;
            }
            v[j] = aux;
        }
    }while(h != 1);
}

int main(){
    int v1[]={5,3,6,2,7,8,1,4},
        v2[]={1,2,3,4,5,6,7,8,9,10},
        v3[]={5,4,3,2,1};
    int i;

    shellSort(v1,8);
    for (i=0;i<8;i++) printf("%d ",v1[i]);
    printf("\n");

    shellSort(v2,10);
    for (i=0;i<10;i++) printf("%d ",v2[i]);
    printf("\n");

    shellSort(v3,5);
    for (i=0;i<5;i++) printf("%d ",v3[i]);
    printf("\n");
}