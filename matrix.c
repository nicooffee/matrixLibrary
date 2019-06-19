#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct Matrix{
    int **matrix;
    unsigned int row;
    unsigned int col;
};




Matrix matrix_create(unsigned int lRow,unsigned int lCol){
    struct Matrix *M = NULL;
    register int i;
    if(lRow<=0 || lCol<=0) return M;
    M = (struct Matrix*) calloc(1,sizeof(struct Matrix));
    M->row = lRow;
    M->col = lCol;
    M->matrix = (int**) calloc(lRow,sizeof(int*));
    for(i=0 ; i<lRow ; i++)
        (M->matrix)[i] = (int*) calloc(lCol,sizeof(int));
    return M;
}




void matrix_free(Matrix M){
    register int i;
    for(i=0 ; i<M->row ; i++)
        free((M->matrix)[i]);
    free(M->matrix);
    free(M);
}




int matrix_get(Matrix M,int i,int j){
    if(0<=i && i<M->row && 0<=j && j<M->col)
        return M->matrix[i][j];
    return 0; //ERROR
}




int matrix_set(Matrix M, int new, int i, int j){
    if(0<=i && i<M->row && 0<=j && j<M->col)
        (M->matrix)[i][j] = new+(M->matrix)[i][j] - (new = (M->matrix)[i][j]);
    return new;
}




void matrix_print(Matrix M){
    register int i,j;
    for(i=0;i<M->row;i++){
        for(j=0;j<M->col;j++)
            printf("%d ",(M->matrix)[i][j]);
        printf("\n");
    }
    return;
}




int matrix_max(Matrix M){
    register int i,j;
    int maxVal = matrix_get(M,0,0);
    for(i=0;i<M->row;i++)
        for(j=0;j<M->col;j++)
            if(maxVal<matrix_get(M,i,j))
                maxVal = matrix_get(M,i,j);
    return maxVal;
}




int matrix_min(Matrix M){
    register int i,j;
    int minVal = matrix_get(M,0,0);
    for(i=0;i<M->row;i++)
        for(j=0;j<M->col;j++)
            if(minVal>matrix_get(M,i,j))
                minVal = matrix_get(M,i,j);
    return minVal;
}




Matrix matrix_transpose(Matrix M){
    register int i,j;
    Matrix new = matrix_create(M->col,M->row);
    for(i=0;i<M->row;i++)
        for(j=0;j<M->col;j++)
            matrix_set(new,matrix_get(M,i,j),j,i);
    return new;
}



int *matrix_toArray(Matrix M){
    int *A = (int*) calloc(M->row*M->col,sizeof(int));
    register int i,j;
    for(i=0;i<M->row;i++)
        for(j=0;j<M->col;j++)
            A[(i*M->col)+j] = matrix_get(M,i,j);
    return A;
}




int matrix_lenRow(Matrix M){
    return M->row;
}
int matrix_lenCol(Matrix M){
    return M->col;
}