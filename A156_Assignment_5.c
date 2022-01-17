// Name : Aditya Khoje
// Roll No. : SYITA156

/* Implement any database using a doubly-linked list with the following options
a) Insert a record
b) delete a record
c) modify a record
d) Display list forward
e) Display list backward
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char name[20];
    char dept[20];
    int id_no;
    int salary;
    int mobile_no;
    struct employee *prev;
    struct employee *next;
};

struct employee *head;
struct employee *last = NULL;
void insertion_at_beginning();
void insertion_at_last();
void insertion_specific_place();
void insertion_more();
void deletion_beginning();
void deletion_last();
void deletion_specific();
void display();
void search();
void reverse();

void main()
{
    int choice;

    printf("\n------   Employee Database   ------\n\n");
    do
    {
        printf("\nWhich operation do you want to perform :-\n");
        printf("\n 1) Insert in begining");
        printf("\n 2) Insert at last");
        printf("\n 3) Insert at specific location");
        printf("\n 4) Insert more than one data");
        printf("\n 5) Delete from Beginning");
        printf("\n 6) Delete from last");
        printf("\n 7) Delete the node after the given data");
        printf("\n 8) Search");
        printf("\n 9) Display");
        printf("\n10) Display backward");
        printf("\n11) Exit");

        printf("\nEnter your choice : ");
        scanf("\n%d", &choice);

        switch (choice)
        {
        case 1:
            insertion_at_beginning();
            break;
        case 2:
            insertion_at_last();
            break;
        case 3:
            insertion_specific_place();
            break;
        case 4:
            insertion_more();
            break;
        case 5:
            deletion_beginning();
            break;
        case 6:
            deletion_last();
            break;
        case 7:
            deletion_specific();
            break;
        case 8:
            search();
            break;
        case 9:
            display();
            break;
        case 10:
            reverse();
            break;
        case 11:
            printf("\n\n    THANK YOU :) \n\n");
            break;
        default:
            printf("\nInvalid choice \n");
        }
    } while (choice != 11);
}

void insertion_at_beginning()
{
    struct employee *temp;
    char c[20];
    temp = (struct employee *)malloc(sizeof(struct employee));
    if (temp == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {

        printf("\nEnter data of employee :- ");
        printf("\nID No. : ");
        scanf("%d", &temp->id_no);
        printf("Name : ");
        scanf("%s", c);
        strcpy(temp->name, c);
        printf("Department : ");
        scanf("%s", c);
        strcpy(temp->dept, c);
        printf("Salary : ");
        scanf("%d", &temp->salary);
        printf("Mobile No. : ");
        scanf("%d", &temp->mobile_no);

        if (head == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
        }
        else
        {
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        printf("\nNode inserted\n");
    }
}
void insertion_at_last()
{
    char c[20];
    struct employee *temp, *p;
    int item;
    temp = (struct employee *)malloc(sizeof(struct employee));
    if (temp == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter data of employee :- ");
        printf("\nID No. : ");
        scanf("%d", &temp->id_no);
        printf("Name : ");
        scanf("%s", c);
        strcpy(temp->name, c);
        printf("Department : ");
        scanf("%s", c);
        strcpy(temp->dept, c);
        printf("Salary : ");
        scanf("%d", &temp->salary);
        printf("Mobile No. : ");
        scanf("%d", &temp->mobile_no);
        if (head == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
            temp->next = NULL;
        }
    }
    printf("\nData inserted\n");
}

void insertion_specific_place()
{
    char c[20];
    struct employee *temp, *p;
    int position, i;
    temp = (struct employee *)malloc(sizeof(struct employee));
    if (temp == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        p = head;
        printf("Enter the position at which song is to be inserted : ");
        scanf("%d", &position);
        for (i = 1; i < position; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("\n Invalid input\n");
                return;
            }
        }

        printf("\nEnter data of employee :- ");
        printf("\nID No. : ");
        scanf("%d", &temp->id_no);
        printf("Name : ");
        scanf("%s", c);
        strcpy(temp->name, c);
        printf("Department : ");
        scanf("%s", c);
        strcpy(temp->dept, c);
        printf("Salary : ");
        scanf("%d", &temp->salary);
        printf("Mobile No. : ");
        scanf("%d", &temp->mobile_no);

        p->prev->next = temp;
        temp->prev = p->prev;
        temp->next = p;
        p->prev = temp;

        printf("\nData at position %d inserted\n", position);
    }
}

void insertion_more()
{
    int no;
    char c[20];
    struct employee *temp, *p;

    p = (struct employee *)malloc(sizeof(struct employee));
    p = head;

    printf("How many number data to add : ");
    scanf("%d", &no);

    for (int i = 0; i < no; i++)
    {
        temp = (struct employee *)malloc(sizeof(struct employee));

        printf("\nEnter data of employee :- ");
        printf("\nID No. : ");
        scanf("%d", &temp->id_no);
        printf("Name : ");
        scanf("%s", c);
        strcpy(temp->name, c);
        printf("Department : ");
        scanf("%s", c);
        strcpy(temp->dept, c);
        printf("Salary : ");
        scanf("%d", &temp->salary);
        printf("Mobile No. : ");
        scanf("%d", &temp->mobile_no);
        if (head == NULL)
        {
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
            p = head;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            temp->next = NULL;
            temp->prev = p;
            p->next = temp;
            p = p->next;
        }
    }
}
void deletion_beginning()
{
    struct employee *temp;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nFirst data node deleted\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("\nFirst data node deleted\n");
    }
}
void deletion_last()
{
    struct employee *temp;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nLast data node deleted\n");
    }
    else
    {
        temp = head;
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("\nLast data node deleted\n");
    }
}

void deletion_specific()
{
    struct employee *p, *temp;
    int no;

    printf("\n Enter the employee ID which is to be deleted : ");
    scanf("%d", &no);

    p = head;
    while (p->id_no != no - 1)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        printf("\nData is not present in database\n");
    }
    else if (p->next->next == NULL)
    {
        p->next = NULL;
    }
    else
    {
        temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        free(temp);
        printf("\nEmployee ID %d is deleted", no);
    }
}
void display()
{
    struct employee *temp;
    int sr_no = 1;
    printf("\n Employee database is :- \n\n");
    temp = head;
    printf("| Sr. No. | ID No. |  Name  |  Department  |  Salary  |  Mobile No.  |");
    while (temp != NULL)
    {
        printf("\n|%9d|%8d|%8s|%14s|%10d|%14d|", sr_no, temp->id_no, temp->name, temp->dept, temp->salary, temp->mobile_no);
        temp = temp->next;
        sr_no++;
    }
}
void search()
{
    struct employee *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter employee ID which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->id_no == item)
            {
                printf("\nitem found at location %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\nItem not found\n");
        }
    }
}

void reverse()
{
    struct employee *current, *temp, *p;
    p = head;
    while (p != NULL)
    {
        last = p;
        p = p->next;
    }
    current = head;
    while (current != NULL)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    temp = head;
    head = last;
    last = temp;
    display();
}