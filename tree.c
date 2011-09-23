#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "tree.h"

Tree createTree(Tree t)
{
    Tree t1 = NULL;
    int k;
    scanf("%d", &k);
    if(0 == k)
        t = NULL;
    else
    {
        t = (Tree)malloc(sizeof(struct node));
        t->data = k;
        t->left = t->right = NULL;
        t->left = createTree(t1);
        t->right = createTree(t1);
    }
    return t;
}

void preOrder(Tree root)
{
    if(NULL == root)
    {
        return;
        }
    else
    {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Tree root)
{
    if(NULL == root)
    {
        return;
        }
    else
    {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
    }
