typedef struct Matrix * Matrix;

extern Matrix   matrix_create(unsigned int lRow,unsigned int lCol);
extern void     matrix_free(Matrix M);
extern int      matrix_get(Matrix M,int i,int j);
extern int      matrix_set(Matrix M, int new, int i, int j);
extern void     matrix_print(Matrix M);
extern int      matrix_max(Matrix M);
extern int      matrix_min(Matrix M);
extern Matrix   matrix_transpose(Matrix M);
extern int      *matrix_toArray(Matrix M);
extern int      matrix_lenRow(Matrix M);
extern int      matrix_lenCol(Matrix M);