// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa6.c"

#include <stdio.h>

// TODO implemente seu programa aqui

void mult_3_5_while(int num){
    int i;
    i = 1;
    while (i <= num){
        if (i % 5 == 0 && i % 3 == 0){
            printf("por três e por cinco \n");
        }
        else if (i % 5 == 0){
            printf("apenas por cinco \n");
        }
        else if (i % 3 == 0){
            printf("apenas por três \n");
        }
        else {
            printf("nenhum \n");
        }
        i ++;
    }
}

void mult_3_5_for(int num){
    for (int i = 1; i <= num; i++){
        if (i % 5 == 0 && i % 3 == 0){
            printf("por três e por cinco \n");
        }
        else if (i % 5 == 0){
            printf("apenas por cinco \n");
        }
        else if (i % 3 == 0){
            printf("apenas por três \n");
        }
        else {
            printf("nenhum \n");
        }
    }
}
int main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);
    mult_3_5_while(num);
    mult_3_5_for(num);
    return 0;
}
