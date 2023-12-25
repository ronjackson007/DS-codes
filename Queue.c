#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct QUEUE
{
    int a[MAX];
    int front, rear;
};

void enqueue(struct QUEUE *qp, int data)
{
    // Check Overflow
    if (qp->rear == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    qp->rear = qp->rear + 1;
    qp->a[qp->rear] = data;

    // Chek if front is-1
    if (qp->front == -1)
    {
        qp->front = 0;
    }
    printf("Successfull\n");
}
void dequeue(struct QUEUE *qp)
{
    // Check for Underflow
    if (qp->front == -1)
    {
        printf("UnderFlow\n");
        return;
    }
    int item = qp->a[qp->front];
    qp->front = qp->front - 1;
    printf("%d Deleted Successfully\n", item);
}
void display(struct QUEUE q0)
{
    // Check for Underflow
    if (q0.front == -1)
    {
        printf("UnderFlow\n");
        return;
    }
    for (int i = q0.front; i >= 0; i--)
    {
        printf("%d ", q0.a[i]);
    }
}
void main()
{
    struct QUEUE q;
    q.front = q.rear = -1;
    int ch, item;
    while (1)
    {
        printf("\nEnter Your Choice: \n");
        printf("1.Enqueue\n 2.Dequeue \n 3.Display \n 4.Size of Queue \n 5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element : ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Size of queue = %d\n", q.front + 1);
            break;
        case 5:
            exit(0);
        default:
            printf("INVALID!!!!\n");
        }
    }
}
