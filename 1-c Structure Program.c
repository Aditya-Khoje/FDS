#include <stdio.h>

struct product
{
    int code;
    char name[50];
    float price;
} p[100];

void getData();
void showData(int n);

void getData()
{
    int n;

    printf("Enter the number of items : ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        printf("\nEnter the details of item %d :- \n", i+1);

        printf("code : ");
        scanf("%d", &p[i].code);

        printf("Name : ");
        scanf("%s", p[i].name);

        printf("price : ");
        scanf("%f", &p[i].price);
    }
    showData(n);
}

void showData(int n)
{
    int r;
    printf("\nFollowing items are available in store : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d) %s \n",i+1,p[i].name);
    }

    printf("\nWhich product do you want to purchase : ");
    scanf("%d",&r);

    printf("\nYour purchase details are :- \n");
    printf("Code : %d \n",p[r-1].code);
    printf("Name : %s \n",p[r-1].name);
    printf("Price : %f Rs.\n",p[r-1].price);
}

int main()
{
    getData();

    return 0;
}
