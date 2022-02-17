#include <stdio.h>

#define TYPE "P2"
#define MAX_GRAY 255
#define LIMIAR 127

typedef struct {
    int width;
    int height;
    int matrix[640][480];
} imagem;

typedef struct {
    int x;
    int y;
} ponto;


void le_imagem (char *filename, imagem *pimg, int *max_gray, char *type) {
    FILE *fptr;

    fptr = fopen(filename, "r");
    fscanf(fptr, "%s", type);
    fscanf(fptr, "%d", &pimg->width);
    fscanf(fptr, "%d", &pimg->height);
    fscanf(fptr, "%d", max_gray);
    for (int i = 0; i < pimg->height; i++){
        for (int j = 0; j < pimg->width; j++){
            fscanf(fptr, "%d", &pimg->matrix[i][j]);
        }
    }
    fclose(fptr);
}

void escreve_imagem (imagem img) {
    FILE *fptr;
    int new_pixel;

    fptr = fopen("cat6.pgm", "wb");
    fprintf(fptr, "%s\n", TYPE);
    fprintf(fptr, "%d ", img.width);
    fprintf(fptr, "%d\n", img.height);
    fprintf(fptr, "%d\n", MAX_GRAY);
    for (int i = 0; i < img.height; i++){
        for (int j = 0; j < img.width; j++){
            fprintf(fptr, "%d ", img.matrix[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}

void limiar (imagem img, int max_gray, char type[]) {
    FILE *fptr;
    int new_pixel;

    fptr = fopen("cat4.pgm", "wb");
    fprintf(fptr, "%s\n", type);
    fprintf(fptr, "%d ", img.width);
    fprintf(fptr, "%d\n", img.height);
    fprintf(fptr, "%d\n", max_gray);
    for (int i = 0; i < img.height; i++){
        for (int j = 0; j < img.width; j++){
            
            if(LIMIAR <= img.matrix[i][j]){
                new_pixel = 255;
            }
            else{
                new_pixel = 0;
            }
            fprintf(fptr, "%d ", new_pixel);
        }
    }
    fclose(fptr);
}

void crop (imagem img, imagem *crop, ponto pinit, ponto pend) {
    for(int i=pinit.y; i < pend.y; i++){
        for(int j=pinit.x; j < pend.x; j++){
            crop->matrix[i-pinit.y][j-pinit.x] = img.matrix[i][j];
        }
    }
}

void blur (imagem img, imagem *pblrimg) {
    pblrimg->width = img.width;
    pblrimg->height = img.height;
    for(int i=0; i < img.height; i++){
        for(int j=0; j < img.width; j++){
            if(i != 0 && i !=img.height && j !=0 && j != img.width){
                pblrimg->matrix[i][j] = (img.matrix[i-1][j]+img.matrix[i+1][j]+img.matrix[i][j-1]+img.matrix[i][j+1]+img.matrix[i-1][j-1]+img.matrix[i-1][j+1]+img.matrix[i+1][j-1]+img.matrix[i+1][j+1])/8;
            }
            else {
                pblrimg->matrix[i][j] = img.matrix[i][j];
            }
        }
    }
}

det_bord(imagem img, imagem *pdetectborder){
    pdetectborder->width = img.width;
    pdetectborder->height = img.height;
    for(int i=0; i < img.height; i++){
        for(int j=0; j < img.width; j++){
            // pegar modulo
            pdetectborder->matrix[i][j] = (4*img.matrix[i][j])-(img.matrix[i-1][j] + img.matrix[i+1][j] + img.matrix[i][j-1] + img.matrix[i][j+1]);
        }
    }
}

int main() {
    imagem img, cimg, blrimg, detectborder;
    imagem *pcimg, *pblur, *pdetectborder;
    char type[3];
    int max_gray;
    ponto pinit;
    ponto pend;

    pinit.x = 20;
    pinit.y = 30;

    pend.x = 80;
    pend.y = 60;

    cimg.width = pend.x - pinit.x;
    cimg.height = pend.y - pinit.y;



    pcimg = &cimg;
    pblur = &blrimg;
    pdetectborder = &detectborder;

    le_imagem("cat.pgm", &img, &max_gray, type);
    det_bord(img, pdetectborder);
    escreve_imagem(detectborder);
    limiar(img, MAX_GRAY, TYPE);

    return 0;
}