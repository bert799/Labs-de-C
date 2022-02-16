#include <stdio.h>


void sum_sub(int a, int b, int *psum, int *psub) {
    *psum = a + b;
    *psub = a - b;
}


int main() {
    int num1;
    int num2;
    int sum;
    int sub;
    int *psum;
    int *psub;

    sum = 0;
    sub = 0;
    psum = &sum;
    psub = &sub;

    printf("insira o primeiro número: ");
    scanf("%d", &num1);
    printf("insira o segundo número: ");
    scanf("%d", &num2);

    sum_sub(num1, num2, psum, psub);
    printf("Sum: %d \n", sum);
    printf("Sub: %d \n", sub);
}