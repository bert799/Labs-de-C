#include <stdio.h>


int main() {
    long mat[5][4] = {{1,2,3,4},{0,0,0,4},{5,6,7,0},{9,1,0,0},{0,0,0,0}};
    int indice = 0;
    for(int i=0; i<5; i++){
        long contador =0;
        for(int j=0; j<4; j++){
            contador += mat[i][j];
            indice++;
        }
        printf("%ld \n",contador);
        printf("maior indice da coluna%d: %d \n", i, indice);
    }
   return 0;
}