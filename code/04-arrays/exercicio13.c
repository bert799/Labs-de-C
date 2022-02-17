#include <stdio.h>

double avg(long vec[100], int n){
    double soma = 0;
    double media = 0;
    for(int i=0; i < n; i++){
        soma += vec[i];
    }
    media = soma/n;
    return media;
}

double var(long vec[100], long media, int n){
    double soma = 0;
    double variancia = 0;
    for(int i=0; i < n; i++){
        soma += (vec[i]-media)*(vec[i]-media);
    }
    variancia = (double) soma/n;
    return variancia;
}

int main(){
    int n;
    double media;
    double variancia;
    long vec[100];
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%ld", &vec[i]);
    }
    media = avg(vec, n);
    variancia = var(vec, media, n);
    printf("%f \n%f \n", media, variancia);
    return 0;
}