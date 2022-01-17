// Name : Aditya Khoje
// Roll No. : SYITA156

/* epartment of Information Technology has a student's club named 'Pinnacle Club'. Students of the 
Second, third and final year of the department can be granted membership on request. Similarly, 
one may cancel the membership of the club. The first node is reserved for the president of the club 
and the last node is reserved for the secretary of the club. Write C program to maintain club 
member’s information using a singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as the president or even secretary. 
b) Compute the total number of members of the club
c) Display members of the club
Display list in reverse order using recursion */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct club_information *create_head(struct club_information *head);
void add_members(int m, struct club_information *head);
void add_secretary(struct club_information *head);
void display(struct club_information *head);
void AddM(int m, struct club_information *head);
struct club_information *Delete_president(struct club_information *head);
void Delete_Member(int m1, struct club_information *head);
void Delete_secretary(struct club_information *head);
struct club_information *reverse(struct club_information *head);
void Total_Member(struct club_information *head);

struct club_information
{
    int prn, rollno;
    char name[20];
    struct club_information *next;
};

int main()
{
    printf("\n\n-----  Pinnacle Club Database  -----\n\n");
    struct club_information *head = NULL;
    struct club_information *temp;
    int ch, m, m1;

    do
    {
        printf("\n\nWhich operation do you want to perform :- ");
        printf("\n 1) Add president");
        printf("\n 2) Add members");
        printf("\n 3) Add secretary");
        printf("\n 4) Display");
        printf("\n 5) Delete president");
        printf("\n 6) Delete specific member");
        printf("\n 7) Delete secretary");
        printf("\n 8) Display data in reverse order");
        printf("\n 9) Compute the total number of members of the club");
        printf("\n10) Exit");
        printf("\nYour choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = create_head(head);
            break;

        case 2:
            printf("\nEnter the number of members to add : ");
            scanf("%d", &m);
            add_members(m, head);
            break;

        case 3:
            add_secretary(head);
            break;

        case 4:
            display(head);
            break;

        case 5:
            temp = Delete_president(head);
            head = temp;
            break;

        case 6:
            printf("\nEnter roll no. to be deleted : ");
            scanf("%d", &m1);
            Delete_Member(m1, head);
            break;

        case 7:
            Delete_secretary(head);
            break;

        case 8:
            temp = reverse(head);
            head = temp;
            display(head);
            break;

        case 9:
            Total_Member(head);
            break;

        case 10:
            printf("\n Thank you :)  \n");
            break;

        default:
            printf("\n Invalid Entry !!! \n");
            break;
        }
    } while (ch != 10);
}

struct club_information *create_head(struct club_information *head)
{
    struct club_information *temp;
    temp = (struct club_information *)malloc(sizeof(struct club_information));

    char n[20];

    printf("\nEnter the roll number, PRN and name of the member : \n");
    scanf("%d %d %s", &temp->rollno, &temp->prn, n);
    strcpy(temp->name, n);

    if (head == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
    }

    return temp;
}

void add_members(int m, struct club_information *head)
{
    struct club_information *temp;
    char n[20];

    for (int i = 0; i < m; i++)
    {
        temp = (struct club_information *)malloc(sizeof(struct club_information));
        printf("\nEnter the roll no., PRN and name of the member : \n");
        scanf("%d %d %s", &temp->rollno, &temp->prn, n);
        strcpy(temp->name, n);

        temp->next = NULL;
        head->next = temp;
        head = head->next;
    }
}

void add_secretary(struct club_information *head)
{

    struct club_information *temp;
    temp = (struct club_information *)malloc(sizeof(struct club_information));

    char n[20];

    printf("\nEnter the roll no., PRN and name of the secretary : \n");
    scanf("%d %d %s", &temp->rollno, &temp->prn, n);
    strcpy(temp->name, n);

    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    temp->next = NULL;
    head->next = temp;
}

void display(struct club_information *head)
{
    int Sr_no = 1;
    printf("\n| Sr No. | Roll No. | PRN No. |   Name   |");
    while (head != NULL)
    {
        printf("\n|%8d|%10d|%9d|%10s|", Sr_no, head->rollno, head->prn, head->name);
        head = head->next;
        Sr_no++;
    }
}

struct club_information *Delete_president(struct club_information *head)
{
    struct club_information *p;
    p = head;
    head = head->next;
    free(p);
    return head;
}

void Delete_Member(int m1, struct club_information *head)
{
    struct club_information *q;

    while (head->rollno != m1)
    {
        q = head;
        head = head->next;
    }
    q->next = head->next;
    free(head);
}

void Delete_secretary(struct club_information *head)
{
    struct club_information *q, *p;
    q = p = head;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    free(p);
    q->next = NULL;
}

struct club_information *reverse(struct club_information *head)
{
    struct club_information *p, *q;
    q = p = head;
    head = head->next;

    q = head;
    p->next = NULL;
    while (head != NULL)
    {
        head = head->next;
        q->next = p;
        p = q;
        q = head;
    }
    return p;
}

void Total_Member(struct club_information *head)
{
    int Sr_no = 1;
    while (head != NULL)
    {
        head = head->next;
        Sr_no++;
    }
    printf("\nTotal number of members of the club are %d\n", Sr_no - 1);
}
