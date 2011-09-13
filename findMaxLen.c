#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int MaxLen = 0;

void findMaxLen(Tree t)
{
    if(NULL == t)
        return;
    if(NULL == t->left)
       t->maxLeft = 0;
    if(NULL == t->right)
       t->maxRight = 0;

    if(t->left != NULL)
        findMaxLen(t->left);
    if(t->right != NULL)
        findMaxLen(t->right);
    
    if(t->left != NULL)
    {
        int tmpMax = 0;
        if(t->left->maxLeft > t->left->maxRight)
            tmpMax = t->left->maxLeft; 
        else
            tmpMax = t->left->maxRight;
        t->maxLeft = tmpMax + 1;
        }
    if(t->right != NULL)
    {
        int tmpMax = 0;
        if(t->right->maxLeft > t->right->maxRight)
            tmpMax = t->right->maxLeft;
        else
            tmpMax = t->right->maxRight;
        t->maxRight = tmpMax + 1;
    }
    if(t->maxLeft + t->maxRight > MaxLen)
        MaxLen = t->maxLeft + t->maxRight;
}

int main()
{
    Tree t = NULL;
    t = createTree(t);
    findMaxLen(t);
    printf("Max len = %d\n", MaxLen);
    return 0;
}
