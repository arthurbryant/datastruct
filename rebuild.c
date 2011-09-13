/*
*   Rebuild the tree using preOrder and inOrder sequence
*/
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
void postOrder(Tree root)
{
    if(NULL == root)
    {
        return;
        }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}

Tree rebuild(int pre[], int in[], int len, Tree *t)
{
    if(NULL == pre || NULL == in)
        return;
    Tree tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = *pre;
    tmp->left = tmp->right = NULL;
    if(NULL == *t)
        *t = tmp;
    if(1 == len)
        return;
    int *inEnd = in;
    int leftLen = 0;
    while(*inEnd != *pre)
    {
        if(NULL == pre || NULL == inEnd)
            return;
        if(leftLen >= len)
            break;
        ++inEnd;
        ++leftLen;
    }
    int rightLen = len - leftLen - 1;
    // rebuild left child tree;
    if(leftLen > 0)
        rebuild(pre+1, in, leftLen, &((*t)->left));
    // rebuild right child tree;
    if(rightLen > 0)
        rebuild(pre+leftLen+1, in+leftLen+1, rightLen, &((*t)->right));
}

int main()
{
    int pre[] = {1, 2, 4, 3, 5, 6};
    int in[] = {4, 2, 1, 5, 3, 6};
    Tree t = NULL;
    rebuild(pre, in, 6, &t);
    Order(t);
    return 0;
}
