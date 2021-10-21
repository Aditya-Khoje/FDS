/* Problem Statement :  To simulate a simple calculator that performs basic tasks such as addition, subtraction,
multiplication, and division. */


#include <stdio.h>

int main()
{
    int response;
    float a,b;

    printf("\n----  ARITHMETIC CALCULATOR  ----\n");
    printf("\nWhich operation do you want to perform :- \n");
    printf("\nEnter 1 for Addition");
    printf("\nEnter 2 for Subtraction");
    printf("\nEnter 3 for Multiplication");
    printf("\nEnter 4 for Division");
    printf("\nEnter 5 to Exit\n");

label1:

    printf("\n\nWhich operation do you want to perform\nYour response : ");
    scanf("%d",&response);

    switch(response)
    {
    case 1:
        printf("\nEnter the first number : ");
        scanf("%f",&a);
        printf("Enter the second number : ");
        scanf("%f",&b);
        printf("\n%0.4f + %0.4f = %0.4f\n",a,b,a+b);
        goto label1;
        break;

    case 2:
        printf("\nEnter the first number : ");
        scanf("%f",&a);
        printf("Enter the second number : ");
        scanf("%f",&b);
        printf("\n%0.4f - %0.4f = %0.4f\n",a,b,a-b);
        goto label1;
        break;

    case 3:
        printf("\nEnter the first number : ");
        scanf("%f",&a);
        printf("Enter the second number : ");
        scanf("%f",&b);
        printf("\n%0.4f * %0.4f = %0.4f\n",a,b,a*b);
        goto label1;
        break;

    case 4:
        printf("\nEnter the first number : ");
        scanf("%f",&a);
        printf("Enter the second number : ");
        scanf("%f",&b);
        printf("\n%0.4f / %0.4f = %0.4f\n",a,b,a/b);
        goto label1;
        break;

    case 5 :
        printf("Thank You :)");
        break;

    default :
        printf("\n---- ! INVALID INPUT ! ----\n");
        printf("\n---- ! TRY AGAIN ! ----\n");
        goto label1;
        break;

    }
    return 0;
}
