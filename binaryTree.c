#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct node
{
    struct node* left;
    struct node*  right;
    //int maxLeft;
    //int maxRight;
    ElementType data;
}Node, *Tree;

Tree insert(ElementType x, Tree t)
{
    if(NULL == t)
    {
        t = malloc(sizeof(struct node));
        if(NULL == t)
        {
            perror("heap overflow\n");
        }
        else
        {
            t->data = x;
            t->left = t->right = NULL;
        }
    }
    else
    {
        if(x < t->data)
            t->left = insert(x, t->left);
        else
            t->right = insert(x, t->right);
    }
    return t;
}

void display(Tree root)
{
    if(NULL == root)
    {
        //printf("root == null\n");
        return;
        }
    else
    {
        printf("%d\n", root->data);
        display(root->left);
        display(root->right);
    }
}
