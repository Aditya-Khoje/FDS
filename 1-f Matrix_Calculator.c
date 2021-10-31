#include <stdio.h>

void matrix_calculator()
{
    printf("\n----  SQUARE MATRIX CALCULATOR  ----\n");
    int response,Order;

    do
    {
        printf("\nWhich operation do you want to perform :- \n");
        printf("\nEnter 1 for Addition");
        printf("\nEnter 2 for Subtraction");
        printf("\nEnter 3 for Multiplication");
        printf("\nEnter 4 to Exit \n");

        printf("\nYour response : ");
        scanf("%d",&response);

label1 :
        if(response < 4)
        {

            printf("\nEnter order of square matrix n : ");
            scanf("%d",&Order);
        }

        float a[Order][Order],b[Order][Order],result[Order][Order];

        if(Order>3)
        {
            printf("Please, Enter order from 1 to 3");
            goto label1;
        }

        if(response==1 || response==2 || response==3)
        {
            printf("\nEnter the first matrix :-\n");
            for (int i=0; i<Order; i++)
            {
                for (int j=0; j<Order; j++)
                {
                    printf(" a[%d][%d] = ",i+1,j+1);
                    scanf("%f",&a[i][j]);
                }
            }
            printf("\nEnter the second matrix :-\n");
            for (int i=0; i<Order; i++)
            {
                for (int j=0; j<Order; j++)
                {
                    printf(" b[%d][%d] = ",i+1,j+1);
                    scanf("%f",&b[i][j]);
                }
            }
        }

        switch(response)
        {
        case 1:
            printf("\nAddition of matrices is :- \n");
            for (int i=0; i<Order; i++)
            {
                for (int j=0; j<Order; j++)
                {
                    result[i][j]=a[i][j]+b[i][j];
                    printf(" %0.4f \t",result[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            printf("\nSubtraction of matrices is :- \n");
            for (int i=0; i<Order; i++)
            {
                for (int j=0; j<Order; j++)
                {
                    result[i][j]=a[i][j]-b[i][j];
                    printf(" %0.4f \t",result[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            printf("\nMultiplication of matrices is :- \n");
            for(int i=0; i<Order; i++)
            {
                for(int j=0; j<Order; j++)
                {
                    result[i][j]=0;
                    for(int k=0; k<Order; k++)
                    {
                        result[i][j]+=a[i][k]*b[k][j];
                    }
                }
            }
            for (int i=0; i<Order; i++)
            {
                for (int j=0; j<Order; j++)
                {
                    printf(" %0.4f \t",result[i][j]);
                }
                printf("\n");
            }
            break;

        case 4:
            printf("\n Thank You :) \n");
            break;

        default :
            printf("\n---- ! INVALID INPUT ! ----\n");
            printf("\n---- ! TRY AGAIN ! ----\n");
            break;
        }
    }
    while ( response != 4);
}

int main()
{
    matrix_calculator();
}
