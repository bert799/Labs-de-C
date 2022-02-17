#include <stdio.h>

#define TYPE "P2"
#define MAX_GRAY 255

typedef struct {
    int width;
    int height;
    int matrix[640][480];
} imagem;

void le_imagem (char *filename, imagem *pimg, int *max_gray, char *type) {
    FILE *fptr;

    fptr = fopen(filename, "r");
    fscanf(fptr, "%s", type);
    fscanf(fptr, "%d", &pimg->width);
    fscanf(fptr, "%d", &pimg->height);
    fscanf(fptr, "%d", max_gray);
    for (int i = 0; i < pimg->width; i++){
        for (int j = 0; j < pimg->height; j++){
            fscanf(fptr, "%d", &pimg->matrix[i][j]);
        }
    }
    fclose(fptr);
}

void escreve_imagem (imagem img, int max_gray, char type[]) {
    FILE *fptr;

    fptr = fopen("cat1.pgm", "wb");
    fprintf(fptr, "%s\n", type);
    fprintf(fptr, "%d ", img.width);
    fprintf(fptr, "%d\n", img.height);
    fprintf(fptr, "%d\n", max_gray);
    for (int i = 0; i < img.width; i++){
        for (int j = 0; j < img.height; j++){
            fprintf(fptr, "%d ", img.matrix[i][j]);
        }
    }
    fclose(fptr);
}

int main() {
    imagem img;
    char type[3];
    int max_gray;

    le_imagem("cat.pgm", &img, &max_gray, type);
    printf("%d\n", img.height);
    printf("%d\n", img.width);
    printf("%s\n", type);
    printf("%d\n", max_gray);
    escreve_imagem(img, max_gray, type);
    // /* Display the matrix */
    // for (int i = 0; i < img.width; i++)
    // {
    //     for (int j = 0; j < img.height; j++)
    //     {
    //         printf("%d\t", img.matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}