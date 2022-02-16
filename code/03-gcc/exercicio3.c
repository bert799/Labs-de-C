#include <stdio.h>
#include <stdbool.h> 

int main(int argc, char *argv[]) {
    bool cont = true;
    while(cont){
        int num1;
        int num2;
        int ret;
        printf(" escreva um número \n");
        ret = scanf("%d", &num1);
        printf(" escreva um outro número \n");
        ret = scanf("%d", &num2);
        
        if (num1 == 0 && num2 ==0){
            cont = false;
            printf("Terminando \n");
        }
        else if(num2 == 0){
            printf("Erro, segundo número é zero. digite um número válido \n");
        }
        else if(num1 % num2 == 0){
            printf("O número %d é múltiplo de %d \n", num1, num2);
        }
        else{
            printf("O número %d não é múltiplo de %d \n", num1, num2);
        }
    }
    

    return 0;
}
