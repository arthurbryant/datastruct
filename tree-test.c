#include <stdio.h>
#include <malloc.h>
#define SIZE 100

typedef struct BiTNode		//定义二叉树节点结构
{
  char data;			//数据域
  struct BiTNode *lchild, *rchild;	//左右孩子指针域
} BiTNode, *BiTree;

void CreateBiTree (BiTree& T);	//生成一个二叉树

void main ()
{
  BiTree T;
  char j;
  int flag = 1;
  printf ("请建立二叉树。\n");
  printf ("建树将以三个空格后回车结束。\n");
  printf ("例如:1 2 3 4 5 6       (回车)\n");
  CreateBiTree (T);		//初始化队列
}
void
CreateBiTree (BiTree & T)
{
  char ch;
  scanf ("%c", &ch);		//读入一个字符   
  if (ch == ' ')
    T = NULL;
  else
    {
      T = (BiTNode *) malloc (sizeof (BiTNode));	//生成一个新结点
      T->data = ch;
      CreateBiTree (T->lchild);	//生成左子树
      CreateBiTree (T->rchild);	//生成右子树
    }
}

