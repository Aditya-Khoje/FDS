// Name : Aditya Khoje
// Roll No : SYITA156

/*
Implement Circular Queue using Array. Perform following operations on it. a) Insertion (Enqueue) b) Deletion (Dequeue) Display

*/
#include <stdio.h>

int n, front = -1, rear = -1;

void enqueue(int a[]);
void dequeue(int a[]);
void display(int a[]);

int main()
{

    printf("Enter the size of queue : ");
    scanf("%d", &n);

    int a[10];
    int choice;
    int temp = 0;

    do
    {
        printf("\n  --  Menu  --  ");

        printf("\nFollowing operations are available in this program : ");
        printf("\n  1) Enqueue");
        printf("\n  2) Dequeue");
        printf("\n  3) Display");
        printf("\n  4) Exit\n");
        printf(" Choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            enqueue(a);
            break;
        case 2:
            dequeue(a);
            break;
        case 3:
            display(a);
            break;
        case 4:
            printf("\n  Thank You :) ");
            break;

        default:
            printf("\nInvalid Input , Try again \n");
            break;
        }
    } while (choice != 4);
}

void enqueue(int a[])
{
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = data;
    }
    else if ((rear + 1) % n == front)
    {
        printf("\nQueue is Full\n");
        return;
    }
    else
    {
        rear = (rear + 1) % n;
        a[rear] = data;
    }
    printf("Data enqueued Sucessfully....\n");
}

void dequeue(int a[])
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }
    else
    {
        front = (front + 1) % n;
    }
    printf("Data dequeued Sucessfully....\n");
}

void display(int a[])
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    else
    {
        printf("\nThe queue is : ");
        while (i != rear + 1)
        {
            printf("%d ", a[i]);
            i++;
        }
    }
    printf("\n\n");
}