/*Problem Statement : Pass two parameters to function as(start and end), and display all prime numbers between two
Intervals. */

#include <stdio.h>

void fun(int firstNum, int lastNum)
{
    int flag;

    for(int i=firstNum; i<lastNum; i++)
    {
        if(i==1)
        {
            continue;
        }
        flag=0;
        for(int j=2; j<i; j++)
        {

            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d\n",i);
        }
    }

}

int main()
{
    int a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the last number : ");
    scanf("%d",&b);

    fun(a, b);
    return 0;
}
