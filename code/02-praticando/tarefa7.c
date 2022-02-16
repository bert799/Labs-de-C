// Configurações do mutirão. Não mexer.
#include "../macros_correcoes.h"
#define LABNUM "lab2-"
#define SOLUTIONFILE "tarefa7.c"

#include <stdio.h>

// TODO implemente seu programa aqui
void cria_arvore(int num){
    int num_lin;
    int num_lad;

    num_lin = 1;
    while (num_lin <= num){
        num_lad = num_lin - 1;
        for(int i = num - num_lin; i > 0; i--){
            printf(" ");
        }
        if (num_lad > 0) {
            for(int i =0; i<num_lad; i++){
                printf("/");
            }
            printf("|");
            for(int i = 0; i<num_lad; i++){
                printf("\\");
            }
            printf("\n");
        }
        else {
            printf("| \n");
        }
        num_lin ++;
    }

}
int main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);
    cria_arvore(num);
    return 0;
}
