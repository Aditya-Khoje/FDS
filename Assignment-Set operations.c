#include <stdio.h>

void union_set(int a[], int b[], int c[], int n1, int n2);
void intersection(int a[], int b[], int c[], int n1, int n2);
void difference(int a[], int b[], int c[], int n1, int n2);
void symmetric_diff(int a[], int b[], int c[], int n1, int n2);

// main fuction
int main()
{
    int ch;
    int a[25], b[25], c[25] = {0};
    int n1, n2;

    do
    {
        printf("\nWhich operation do you want to perform : \n");
        printf("1 : Create Sets \n");
        printf("2 : Union \n");
        printf("3 : Intersection \n");
        printf("4 : Difference \n");
        printf("5 : Symmetric difference of two sets \n");
        printf("6 : Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the no. of elements of set A : ");
            scanf("%d", &n1);

            printf("Enter the no. of elements of set B : ");
            scanf("%d", &n2);

            printf("\nEnter elements in first set : ");
            for (int i = 0; i < n1; i++)
            {
                scanf("%d", &a[i]);
            }

            printf("Enter elements in second set : ");
            for (int i = 0; i < n2; i++)
            {
                scanf("%d", &b[i]);
            }

            printf("The elements of set A are : \n");
            printf("A = { ");
            for (int i = 0; i < n1; i++)
            {
                printf("%d ", a[i]);
            }
            printf("} \n");

            printf("The elements of set B are : \n");
            printf("B = { ");
            for (int i = 0; i < n2; i++)
            {
                printf("%d ", b[i]);
            }
            printf("} \n");
            break;

        case 2:
            union_set(a, b, c, n1, n2);
            break;

        case 3:
            intersection(a, b, c, n1, n2);
            break;

        case 4:
            difference(a, b, c, n1, n2);
            break;

        case 5:
            symmetric_diff(a, b, c, n1, n2);
            break;

        case 6:
            printf("\n\n Thank You :) \n\n");
            break;

        default:
            printf("*** Invalid Input *** \n");
            break;
        }

    } while (ch != 6);

    return 0;
}

// function to find union set
void union_set(int a[], int b[], int c[], int n1, int n2)
{
    int k = 0, q;
    // operation to perform union
    for (int i = 0; i < n1; i++)
    {
        c[k] = a[i];
        k++;
    }
    for (int i = 0; i < n2; i++)
    {
        q = 1;
        for (int j = 0; j < n2; j++)
        {
            if (b[i] == a[j])
            {
                q = 0;
                break;
            }
        }
        if (q == 1)
        {
            c[k] = b[i];
            k++;
        }
    }
    // printing union set
    printf("\nUnion set is = { ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("}\n");
}

// function to find intersection set
void intersection(int a[], int b[], int c[], int n1, int n2)
{
    // operation to perform intersection
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                c[k] = a[i];
                k++;
            }
        }
    }
    // printing intersection of sets
    printf("\nIntersection set is = { ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("}\n");
}

// function to find difference set
void difference(int a[], int b[], int c[], int n1, int n2)
{
    int k = 0, q;
    for (int i = 0; i < n1; i++)
    {
        q = 0;
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                q = 1;
                break;
            }
        }
        if (q == 0)
        {
            c[k] = a[i];
            k++;
        }
    }

    printf("\nC = A - B = { ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("}\n");

    k = 0;
    for (int i = 0; i < n2; i++)
    {
        q = 0;
        for (int j = 0; j < n1; j++)
        {
            if (b[i] == a[j])
            {
                q = 1;
                break;
            }
        }
        if (q == 0)
        {
            c[k] = b[i];
            k++;
        }
    }

    printf("\nC = B - A = { ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("}\n");
}

// function to perform symmetric difference
void symmetric_diff(int a[], int b[], int c[], int n1, int n2)
{
    int k = 0, q;
    for (int i = 0; i < n1; i++)
    {
        q = 0;
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j])
            {
                q = 1;
                break;
            }
        }
        if (q == 0)
        {
            c[k] = a[i];
            k++;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        q = 0;
        for (int j = 0; j < n1; j++)
        {
            if (b[i] == a[j])
            {
                q = 1;
                break;
            }
        }
        if (q == 0)
        {
            c[k] = b[i];
            k++;
        }
    }

    printf("\nSymmetric difference = { ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("}\n");
}
