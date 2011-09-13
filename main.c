#include <stdio.h>
#include "tree.h"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    struct node* root = NULL;
    /*
    int i;
    for(i = 0; i < len; ++i)
    {
        root = insert(arr[i], root);
    }
    */
    /*
    root = createTree(root);
    if(NULL == root)
        printf("root still null\n");
    preOrder(root);
    printf("---------------------\n");
    inOrder(root);
    */
    int pre[] = {1, 2, 4, 3, 6, 5};
    int in[] = {4, 2, 1, 5, 3, 6};
    Tree t = NULL;
    rebuild(pre, in, 6, t);
    return 0;
}
