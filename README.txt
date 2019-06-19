The library hasn't error checking. Though, it wouldn't be hard to implement.


Matrix   matrix_create(unsigned int lRow,unsigned int lCol);
	: This function returns a Matrix variable type that contains a matrix M(lRow,lCol).

void     matrix_free(Matrix M);
	: This function does free to the parameter M.

int      matrix_get(Matrix M,int i,int j);
	: As the elements of a Matrix type are opaqued, we need a function 		that access to those elements. This is that function. 

int      matrix_set(Matrix M, int new, int i, int j);
	: Pretty similar to matrix_get, tough this function changes the 		value of a element at the positions i,j.

void     matrix_print(Matrix M);
	: Prints the actual content of M.

int      matrix_max(Matrix M);
	: Returns the max value in M.

int      matrix_min(Matrix M);
	: Returns the min value in M.

Matrix   matrix_transpose(Matrix M);
	: Returns a new Matrix, the Matrix that's the transpose of M.

int      *matrix_toArray(Matrix M);
	: Returns a array that contains all of the elements in M, row by row.

int      matrix_lenRow(Matrix M);
	: Returns the length of rows in M

int      matrix_lenCol(Matrix M);
	: Returns the length of columns in M