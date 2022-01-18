// Name : Aditya Khoje
// Roll No : SYITA156

/*
Department maintains student information. The file contains roll, name, division, and address. To create a sequential file to store and maintain student data. add, delete information of the student.
*/

#include <stdio.h>
#include <string.h>

int n;

struct Student
{
    char name[20];
    int roll_no;
    char Division;
    char Address[50];
};

void Accept_Student_Data(struct Student e[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the Name , Roll Number , Division , Address of the Student : ");
        scanf(" %s %d %c %s", e[i].name, &e[i].roll_no, &e[i].Division, e[i].Address);
    }
    n++;
}

void Write_to_File(struct Student e[], int n)
{
    FILE *fp;
    fp = fopen("Student.txt", "a");
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%s %d %c %s", e[i].name, e[i].roll_no, e[i].Division, e[i].Address);
            fputs("\n", fp);
        }
    }
    fclose(fp);
}

void Read_File(int n)
{
    FILE *fp;
    fp = fopen("Student.txt", "r");
    struct Student StuData;
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s %d %c %s", StuData.name, &StuData.roll_no, &StuData.Division, StuData.Address);
            fputs("\n", fp);
            printf("%s\t%d\t%c\t%s\t\n", StuData.name, StuData.roll_no, StuData.Division, StuData.Address);
        }
    }
    fclose(fp);
}

void Search_File(int n)
{
    FILE *fp;
    fp = fopen("Student.txt", "r");
    struct Student StuData[10];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s %d %c %s", StuData[i].name, &StuData[i].roll_no, &StuData[i].Division, StuData[i].Address);
        }
    }
    fclose(fp);
    char name[20];
    printf("Enter the name of Student : ");
    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(StuData[i].name, name) == 0)
        {
            printf("%s %d %c %s.\n", StuData[i].name, StuData[i].roll_no, StuData[i].Division, StuData[i].Address);
        }
    }
}

void Delete()
{
    int i, j;
    FILE *fp;
    fp = fopen("Student.txt", "r");
    struct Student StuData[50];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        i = 0;
        while (fscanf(fp, "%s %d %c %s", StuData[i].name, &StuData[i].roll_no, &StuData[i].Division, StuData[i].Address) != EOF)
        {
            i++;
        }
    }
    fclose(fp);

    for (j = 0; j < i; j++)
    {
        printf("\n%s %d %c %s\n", StuData[j].name, StuData[j].roll_no, StuData[j].Division, StuData[i].Address);
    }

    char name[20];
    printf("Enter the name of Student : ");
    scanf("%s", name);
    FILE *f2;
    f2 = fopen("Student.txt", "w");
    if (f2 == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(StuData[j].name, name) == 0)
            {
                continue;
            }
            else
            {
                fprintf(f2, "%s %d %c %s", StuData[j].name, StuData[i].roll_no, StuData[i].Division, StuData[i].Address);
                fputs("\n", f2);
            }
        }
    }
    fclose(f2);
    n--;
}

int main()
{
    struct Student e[50];
    int choice;

    printf("\n\nEnter the total number of students : ");
    scanf("%d", &n);

    do
    {
        printf("\n 1) Accept the data");
        printf("\n 2) Write to the file");
        printf("\n 3) Read the file ");
        printf("\n 4) Search the file");
        printf("\n 5) Delete from the file");
        printf("\n 6) Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Accept_Student_Data(e, n);
            break;

        case 2:
            Write_to_File(e, n);
            break;

        case 3:
            Read_File(n);
            break;

        case 4:
            Search_File(n);
            break;

        case 5:
            Delete();
            break;

        case 6:
            printf("\n  Thank You :) \n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }

    } while (choice != 6);

    return 0;
}