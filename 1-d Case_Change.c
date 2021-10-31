/*Problem Statement : Accept a string and change the case of each character of the string. Example “THIs Is a C
Program” changes to “thiS iS A c pROGRAM”. */

#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]", str);

    int i=0;
    while(str[i]!='\0')
    {

        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }

    printf("String after changing case : %s", str);
    return 0;
}
