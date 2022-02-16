#include <stdio.h>

typedef struct {
    int x;
    int y;
} ponto;

int modulo(int num){
    if (num>0){
        return num;
    }
    num = -num;
    return num;
}

int manhattan(ponto p1, ponto p2){
    int distancia;
    distancia = modulo(p1.x - p2.x) + modulo(p1.y - p2.y);
    return distancia;
}

int main() {
    ponto p1;
    ponto p2;
    int distancia;

    printf("insira valor x de p1: ");
    scanf("%d", &p1.x);
    printf("insira valor y de p1: ");
    scanf("%d", &p1.y);
    printf("insira valor x de p2: ");
    scanf("%d", &p2.x);
    printf("insira valor y de p2: ");
    scanf("%d", &p2.y);

    distancia = manhattan(p1, p2);
    printf("distância: %d \n", distancia);
}