#include <stdio.h>
#include "HUser_Matrix.h"

int main()
{
    int i = 0;
    CMatrix data;
    CMatrix* matrix1, * matrix2;
    int size1, size2;

    //input data + memory 
    printf("Input a size of the first square matrix: ");
    scanf("%d", &size1);

    printf("Input a size of the second square matrix: ");
    scanf("%d", &size2);
    //first matrix 
    allocate_matrix(&matrix1, size1);
    fill_matrix(matrix1);
    mprint(matrix1);
    free_vector(&matrix1);
    
   
    int choice;
    printf("Choose: 1) matrix+const; 2) matrix * conts; 3) matrix + matrix; 4) matrix * matrix; 5) ALL at once (âñ¸)) \n");
    scanf("%d", &choice);

    //functions
    if (choice == 1) {
        int user_const;
        printf("Input a number ");
        scanf("%d", &user_const);
        CMatrix* ans = add_const(matrix1, user_const);
        fill_matrix(ans);
    }
    if (choice == 2) {
        int user_const;
        printf("Input a number ");
        scanf("%d", &user_const);
        CMatrix* ans = multi_const(matrix1, user_const);
        fill_matrix(ans);
    }
    if (choice == 3) {
       
        //second matrix
        allocate_matrix(&matrix2, size2);
        allocate_matrix(&matrix2, size2);
        fill_matrix(matrix2);
        mprint(matrix2);

        CMatrix* ans = add_matrix(matrix1, matrix2);
        fill_matrix(ans);
    }
    if (choice == 4) {
        //second matrix
        allocate_matrix(&matrix2, size2);
        allocate_matrix(&matrix2, size2);
        fill_matrix(matrix2);
        mprint(matrix2);

        CMatrix* ans = multi_matrix(matrix1, matrix2);
        fill_matrix(ans);
    }
    if (choice == 5) {
        //second matrix
        allocate_matrix(&matrix2, size2);
        allocate_matrix(&matrix2, size2);
        fill_matrix(matrix2);
        mprint(matrix2);

    }

}
    add_matrix(matrix1, matrix2);
    mprint(res);
    free_vector(&res);

    res = add_const(v1, 5.5f);
    mprint(res);
    free_vector(&res);

    res_dotprod = multi_vector(v1, v2);
    printf("%f\n", res_dotprod);

    res = multi_const(v1, 2.0f);
    mprint(res);
    free_vector(&res);

    free_vector(&v1);
    free_vector(&v2);
    return 0;

