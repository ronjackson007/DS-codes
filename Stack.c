#include <stdio.h>
#define MAX 5
int flag = 1;

struct STACK
{
    int a[MAX];
    int top;
};

void push(struct STACK *sp, int data)
{
    // CHECK FOR OVERFLOW
    if (sp->top == MAX - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    sp->top = sp->top + 1;
    sp->a[sp->top] = data;
    printf("Successfully Added\n");
}
void pop(struct STACK *sp)
{
    // CHECK FOR UNDERFLOW
    if (sp->top == -1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int item = sp->a[sp->top];
    sp->top = sp->top - 1;
    printf("%d Successfully deleted\n", item);
}
void display(struct STACK s0)
{
    // CHECK FOR UNDERFLOW
    if (s0.top == -1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int i;
    for (i=s0.top; i >= 0; i--)
    {
        printf("%d \n", s0.a[i]);
    }
}

void main()
{
    struct STACK s;
    s.top = -1;
    int ch, item;
    while(1)
    {
        printf("Enter Your Choice: ");
        printf("1.PUSH \n 2.POP \n 3.Display \n 4.Stack Size \n 5.Quit \n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter Item\n");
            scanf("%d", &item);
            push(&s, item);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            printf("Size of stack = %d\n", s.top + 1);
            break;
        case 5: exit(0);
        default:
            printf("SORRY!!! INVALID\n");
            break;
        }
    }
}
