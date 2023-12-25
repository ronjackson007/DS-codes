#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
struct list
{
    Node *start;
};

void ins_Node_Last(list *lp, int item)
{
    Node *newNode = new Node;
    newNode->data = item;
    newNode->link = NULL;

    // If List is Empty
    if (lp->start == NULL)
    {
        lp->start = newNode;
        cout << "\n Success~~\n";
        return;
    }
    // If List is not Empty
    Node *ptr = lp->start;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newNode;
    cout << "Success at Last~~\n";
}
void ins_Node_First(list *lp, int item)
{
    Node *newNode = new Node;
    newNode->data = item;
    newNode->link = lp->start;
    lp->start = newNode;
    cout << "~~Successfully Insert at First\n";
}
void ins_yafterx(list *lp, int x, int y){
    //If List is empty
    if (lp->start == NULL)  
    {
        cout << "x Not Found";
    }
    Node *ptr = lp->start;
    while (ptr->data != x && ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    if (ptr->data == x)
    {
    Node *newNode = new Node;
    newNode->data = y;
    newNode->link = ptr->link;
    ptr->link = newNode;
    cout << "successfully added " << y <<" after " << x << "\n";
    }
    else
    {
        cout << x <<" NOT FOUND\n";
    }
    
    
}
void display(list l0)
{
    // Check for UnderFlow
    if (l0.start == NULL)
    {
        cout << "UnderFlow~~";
        return;
    }
    Node *ptr = l0.start;
    while (ptr != NULL)
    {
        cout << ptr->data <<"\n";
        ptr = ptr->link;
    }
}

int main()
{
    list l;
    l.start = NULL;

    ins_Node_Last(&l, 10);
    ins_Node_Last(&l, 12);
    ins_Node_Last(&l, 13);
    ins_Node_Last(&l, 14);
    display(l);
    ins_Node_First(&l, 100);
    ins_Node_First(&l, 200);
    ins_Node_First(&l, 300);
    display(l);
    ins_yafterx(&l, 100, 255);
    display(l);
    return 0;
}
