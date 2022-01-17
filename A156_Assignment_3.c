// Name : Aditya Khoje
// Roll No. : SYITA156

/* Implement a sparse matrix with operations like initialize empty sparse matrix, insert an element, 
add two matrices, transpose a matrix. */

#include <stdio.h>

int main()
{
    void input(int matrix[20][3], int row, int col, int val);
    void display(int matrix[][3], int v);
    void addition(int a[][3], int b[][3], int r[][3], int row1, int column1, int value1, int row2, int column2, int value2);
    void simple_transpose(int a[][3], int b[][3], int row1, int column1, int value1);
    void fast_transpose(int a[][3], int b[][3], int m, int n, int v);

    // variables for additions
    int a[20][3], b[20][3], result[20][3];
    int row1, column1, value1;
    int row2, column2, value2;

    // variables for fast transpose
    int m, n, v;
    int temp;

    do
    {
        printf("\nWhich operation do you want to perform :- \n");
        printf("1) Addition \n");
        printf("2) Simple Transpose \n");
        printf("3) Fast Transpose \n");
        printf("4) Exit \n");
        printf("\nYour response : ");
        scanf("%d", &temp);

        switch (temp)
        {
        case 1:
            printf("\nEnter the number of rows, columns and value for matrix 1 : ");
            scanf("%d %d %d", &row1, &column1, &value1);
            input(a, row1, column1, value1);

            printf("\nEnter the number of rows, columns and value for matrix 2 : ");
            scanf("%d %d %d", &row2, &column2, &value2);
            input(b, row2, column2, value2);

            printf("\nMatrix A is :- ");
            display(a, value1);

            printf("\nMatrix B is :- ");
            display(b, value2);
            addition(a, b, result, row1, column1, value1, row2, column2, value2);
            break;

        case 2:
            printf("\nEnter the number of rows, columns and value for matrix 1 : ");
            scanf("%d %d %d", &row1, &column1, &value1);
            input(a, row1, column1, value1);

            printf("\nMatrix A is :- ");
            display(a, value1);

            simple_transpose(a, b, row1, column1, value1);

            break;

        case 3:
            printf("Enter no. of rows ,columns and values for matrix :");
            scanf("%d %d %d", &m, &n, &v);
            input(a, m, n, v);

            printf("\nEntered matrix in sparse form :-");
            display(a, v);

            fast_transpose(a, b, m, n, v);
            break;

        case 4:
            printf("\n\n Thank You :) \n\n");
            break;

        default:
            printf("\nInvalid response \n");
            break;
        }

    } while (temp != 4);

    return 0;
}

void input(int matrix[20][3], int row, int col, int val)
{
    matrix[0][0] = row;
    matrix[0][1] = col;
    matrix[0][2] = val;
    printf("\nEnter matrix values : \n");

    for (int i = 1; i <= val; i++)
    {
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }
}

void display(int matrix[][3], int v)
{
    printf("\nr\tc\tv\n");
    for (int i = 0; i <= v; i++)
    {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

void addition(int a[][3], int b[][3], int result[][3], int row1, int column1, int value1, int row2, int column2, int value2)
{
    if (a[0][0] != b[0][0] && a[0][1] != b[0][1])
    {
        printf("\nAddition is not possible\n");
    }

    int i = 1, j = 1, k = 0;
    while (i <= value1 && j <= value2)
    {
        if (a[i][0] < b[j][0])
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
            k++;
        }
        else if (a[i][0] > b[j][0])
        {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
            k++;
        }
        else if (a[i][1] < b[j][1])
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
            k++;
        }
        else if (a[i][1] > b[j][1])
        {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
            k++;
        }
        else
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
            k++;
        }
    }

    while (i <= value1)
    {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= value2)
    {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++;
        k++;
    }

    printf("\nAddition of matrices is :- ");
    display(result, k - 1);
}

void simple_transpose(int a[][3], int b[][3], int row1, int column1, int value1)
{
    int col_num, non_zero_val, co, it, q = 1;

    if (non_zero_val == 0)
    {
        printf("\nTranspose of matrix is not possible\n");
    }

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    for (co = 0; co < column1; co++)
    {
        for (it = 1; it <= value1; it++)
        {
            if (a[it][1] == co)
            {
                b[q][0] = a[it][1];
                b[q][1] = a[it][0];
                b[q][2] = a[it][2];
                q++;
            }
        }
    }
    printf("\nSimple transpose of matrix A is :- \n");
    display(b, value1);
}

void fast_transpose(int a[][3], int b[][3], int m, int n, int v)
{
    int total[20], index[20];
    int col, p;

    for (int i = 0; i < n; i++)
    {
        total[i] = 0;
    }

    for (int i = 1; i <= v; i++)
    {
        col = a[i][1];
        total[col]++;
    }
    index[0] = 1;
    for (int i = 1; i < n; i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    for (int i = 1; i <= v; i++)
    {
        col = a[i][1];
        p = index[col];
        index[col]++;
        b[p][0] = a[i][1];
        b[p][1] = a[i][0];
        b[p][2] = a[i][2];
    }

    printf("\nFast transpose of Matrix A is :- \n");
    printf("\nrow\t clos\t values\n");
    for (int i = 0; i <= v; i++)
    {
        printf("%d\t %d\t %d\n", b[i][0], b[i][1], b[i][2]);
    }
}
