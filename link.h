#ifndef LINKLIST
#define LINKLIST

typedef int ElementType;
typedef struct node* Position;
typedef Position List;

extern void insert(List head, ElementType x);
extern void createList(ElementType arr[], int len, List head);
extern List init();
extern void display(List);

#endif
