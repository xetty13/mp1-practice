#include <stdio.h>
#include "HUser_Matrix.h"

int choice(CMatrix* matrix1) {
    int choice;
    
    do {
        printf("Choose: 0) for kill the programm 1) matrix+const; 2) matrix * conts; 3) matrix + matrix; 4) matrix * matrix; \n");
        scanf("%d", &choice);
        
        //functions
        if (choice == 1) {

            int user_const;
            printf("Input a number ");
            scanf("%d", &user_const);

            CMatrix* ans = add_const(matrix1, user_const);
            mprint(ans);
            free_matrix(ans);
        }
        if (choice == 2) {
            int user_const;
            printf("Input a number ");
            scanf("%d", &user_const);

            CMatrix* ans = multi_const(matrix1, user_const);
            mprint(ans);
            free_matrix(ans);
        }
        if (choice == 3) {

            //second matrix
            int size2;
            CMatrix* matrix2;
            printf("Input a size of the second square matrix: ");
            scanf("%d", &size2);
            allocate_matrix(&matrix2, size2);
            allocate_matrix(&matrix2, size2);
            fill_matrix(matrix2);
            
            printf("\n The First matrix: \n");
            mprint(matrix1);

            printf("The Second matrix:\n ");
            mprint(matrix2);

            CMatrix* ans = add_matrix(matrix1, matrix2);
            if (ans == NULL) {
                continue;
            }
            printf("Answer: ");
            mprint(ans);
            free_matrix(ans);
            free_matrix(matrix2);
            
        }
        if (choice == 4) {

            //second matrix
            int size2;
            CMatrix* matrix2;
            printf("Input a size of the second square matrix: ");
            scanf("%d", &size2);
            allocate_matrix(&matrix2, size2);
            fill_matrix(matrix2);

            printf("\n The First matrix: \n");
            mprint(matrix1);

            printf("The Second matrix:\n ");
            mprint(matrix2);
            
            CMatrix* ans = multi_matrix(matrix1, matrix2);
            if (ans == NULL) {
                continue;
            }
            printf("\n Answer: ");
            mprint(ans);
            free_matrix(ans);
            free_matrix(matrix2);
        }
        if (choice == 0) {
            return 0;
        }
    } while (choice != 0);
}

int main()
{
    CMatrix* matrix1, * matrix2;
    int size1;

    //input data + memory 
    printf("Input a size of the first square matrix: ");
    scanf("%d", &size1);
    
    //first matrix  // ћожно было сделать main в 1 строку, но как-то не красиво
    allocate_matrix(&matrix1, size1);
    fill_matrix(matrix1);
    mprint(matrix1);
    choice(matrix1);
    free_matrix(&matrix1);
}