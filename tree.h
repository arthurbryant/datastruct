#ifndef TREE_DEF
#define TREE_DEF

typedef int ElementType;
typedef struct node
{
    struct node* left;
    struct node*  right;
    int maxLeft;
    int maxRight;
    ElementType data;
}Node, *Tree;

Tree createTree(Tree root);
void preOrder(Tree t);
void inOrder(Tree t);

#endif
