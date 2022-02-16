#include <stdio.h>


void retangulo(int altura, int comprimento, int *pper, int *parea){
    *pper = 2*altura*comprimento;
    *parea = altura*comprimento;
}


int main() {
    int altura;
    int comprimento;
    int per;
    int area;
    int *pper;
    int *parea;

    // per = 0;
    // area = 0;
    pper = &per;
    parea = &area;

    printf("insira a altura: ");
    scanf("%d", &altura);
    printf("insira o comprimento: ");
    scanf("%d", &comprimento);

    retangulo(altura, comprimento, pper, parea);
    printf("Perímetro: %d \n", per);
    printf("Área: %d \n", area);
}