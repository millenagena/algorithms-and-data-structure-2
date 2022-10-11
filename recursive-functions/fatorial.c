#include<stdio.h>
#include<stdlib.h>

int fatorial(int n){
    if(n == 0 || n == 1){
        return ;
    }
    return n * fatorial(n-1);
}

int main(){
    int num;
    printf("Informe o numero: ");
    scanf("%d", &num);
    int res = fatorial(num);
    printf("Fatorial de %d: %d", num, res);
}