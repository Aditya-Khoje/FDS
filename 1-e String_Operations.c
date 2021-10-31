/*  Problem Statement :  Accept a string from the user and perform the following string operations –
i. Calculate the length of string ii. String reversal iii. Equality check of two strings iv. Check
palindrome v. Check substring (Pointer to strings).  */


#include<stdio.h>
#include <string.h>


int length( char *str)
{
    int i=0,count=0;
    while(str[i]!='\0')
    {
        i++;
        count++;
    }
    return count;
}


void substring(char *str, int a,int b)
{
    printf("The required Substring is : ");
    for(int i=a-1 ; i<(a+b-1) ; i++)
    {
        printf("%c",*(str+i));
    }
    printf("\n\n");
}


void palindrome(char *str)
{
    int temp = 1;
    for (int i = 0; i < length(str); i++)
    {
        if (str[i] != str[length(str) - 1 - i])
        {
            temp = 0;
        }
    }
    if (temp)
    {
        printf("\nThe entered string is Palindrome\n\n");
    }
    else
    {
        printf("\nThe entered string is not Palindrome\n\n");
    }
}


void compare(char *str1, char *str2)
{
    int temp = 1;
    for (int i = 0; i < length(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            temp = 0;
        }
    }
    if (temp)
    {
        printf("Strings are identical\n\n");
    }
    else
        printf("Strings are not identical\n\n");
}

void reverse_string(char *str1)
{
    char reverse_str[100];
    int str_len=length(str1);
    int j=str_len-1;
    for (int i = 0; i<str_len; i++)
    {
        reverse_str[i]=str1[j];
        j--;
    }

    printf("The reverse of entered string is : %s\n\n",reverse_str);
}

int main()
{
    int response;
    char string1[100],string2[100];

    int position,len;
    char *p;

    do
    {

        printf("\nWhich Operation do you want to perform :-----\n");
        printf("1 : String length\n2 : Reverse\n3 : Compare\n4 : Palidrome\n5 : Substring\n6 : Exit\n\n");
        printf("Your response : ");
        scanf("%d",&response);


        switch(response)
        {

        case 1:
            printf("\nEnter First String : ");
            scanf("%s",string1);
            int strlng=length(string1);
            printf("The length of string is %d\n",strlng);
            break;

        case 2:
            printf("\nEnter First String : ");
            scanf("%s",string1);

            reverse_string(string1);
            break;

        case 3:
            printf("\nEnter First String : ");
            scanf("%s",string1);

            printf("Enter second string to compare : ");
            scanf("%s",string2);
            compare(string1, string2);
            break;

        case 4:
            printf("\nEnter First String : ");
            scanf("%s",string1);

            palindrome(string1);
            break;

        case 5:
            printf("\nEnter First String : ");
            scanf("%s",string1);

            printf("\nEnter the Position and Length of substring : ");
            scanf("%d %d",&position,&len);
            p=string1;
            substring(p,position,len);
            break;

        case 6:
            printf("\n Thank You :) \n ");
            break;

        default:
            printf("Invalid response\n");
            break;
        }
    }
    while (response != 6);

    return 0;
}
