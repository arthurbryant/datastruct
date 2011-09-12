#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct node* Position;
typedef Position List;

struct node 
{
    ElementType data;
    Position next;
};

List init()
{
   List head = malloc(sizeof(struct node));
   head->next = NULL;
   head->data = 0;

   return head;
}
void insert(List head, ElementType x)
{
    List node = malloc(sizeof(struct node));
    if(NULL == node)
    {
        printf("Heap overflows!\n");
        exit(-1);
    }
    node->data = x;
    node->next = head->next;
    head->next = node;
}

void createList(ElementType arr[], int len, List head)
{
    Position p;
    int i;
    for(i = 0; i < len; ++i)
    {
        insert(head, arr[i]);
    }
}

void display(List head)
{
    if(NULL == head)
    {
        printf("empty linklist\n");
        return;
    }
    Position p = head->next;
    while(p)
    {
       printf("%d\n", p->data);
       p = p->next;
    }
}

List reverse(List head)
{
    Position p1;
    Position p2;
    Position p3;

    p1 = head->next;
    if(NULL == p1)
    {
        printf("link is null\n");
        exit(-1);
        }
    p2 = p1->next;
    p1->next = NULL;
    if (NULL == p2)
        return head;
    else
        p3 = p2->next;
    while(p1 != NULL)
    {
        if(NULL == p2)
        {
            head->next = p1;
            return head;
        }
        if(NULL == p3)
        {
            head->next = p2;
            p2->next = p1;
            return head;
        }
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        }
}
