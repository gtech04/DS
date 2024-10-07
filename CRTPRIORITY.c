#include<stdio.h>
#include<stdlib.h>
int size, front, rear;
struct PQ
{
    int item, priority;
} A[30];
void enqueue(int item, int prio);
void D();
void display();
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d %d\n", A[i].item, A[i].priority);
        }
    }
}
void enqueue(int ITEM, int PRIORITY)
{
    int i, loc;
    if (front == 0 && rear == size - 1)
    {
        printf("Queue is full\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        A[rear].item = ITEM;
        A[rear].priority = PRIORITY;
    }
    else
    {
        if (rear == size - 1)
        {
            for (i = front; i <= rear; i++)
            {
                A[i - 1] = A[i];
            }
            front--;
            rear--;
        }

        for (i = rear; i >= front; i--)
        {
            if (A[i].priority < PRIORITY)
            {
                break;
            }
        }
        loc = i + 1;
        for (i = rear; i >= loc; i--)
        {
            A[i + 1] = A[i];
        }
        A[loc].item = ITEM;
        A[loc].priority = PRIORITY;
        rear++;
    }
}

void D()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("\nDeleted item is %d\n", A[front].item);
        front = rear = -1;
    }
    else
    {
        printf("\nDeleted item is %d\n", A[front].item);
        front++;
    }
}

int main()
{
    int opt, item, prio;
    front = -1;
    rear = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    do
    {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("\nEnter item and priority: ");
                scanf("%d %d", &item, &prio);
                enqueue(item, prio);
                break;

            case 2:
                D();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nWrong choice\n");
        }

    } while (opt != 4);

    return 0;
}
