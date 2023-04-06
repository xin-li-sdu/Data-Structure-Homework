#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 200
typedef int ElemType;
//数据类型
//定义树节点
typedef struct Node
{
	int data;
	struct Node* leftChild;
	struct Node* rightSibling;
} Node, * Tree;
//先序创建树
int CreateForest(Tree* T)
{
	ElemType ch;
	ElemType temp;
	scanf("%d", &ch);
	temp = getchar();
	if (ch == -1)
		* T = NULL;
	else 
	{
		*T = (Tree)malloc(sizeof(Node));
		if (!(*T))
			exit(-1);
		(*T)->data = ch;
		printf("输入%d的子树：", ch);
		CreateForest(&(*T)->leftChild);  //左边第一个子树 
		printf("输入%d的兄弟：", ch);
		CreateForest(&(*T)->rightSibling); //右边第一个兄弟 
	}return 1;
}
//先根遍历森林（对应二叉树先序遍历）
void TraverseForest(Tree T)
{
	if (T == NULL)return;
	printf("%d ", T->data);
	TraverseForest(T->leftChild);
	TraverseForest(T->rightSibling);
}
//后根遍历森林（对应二叉树中序遍历） 
void PostOrderForest(Tree T)
{
	if (T == NULL)return;
	PostOrderForest(T->leftChild);
    printf("%d ", T->data);
    PostOrderForest(T->rightSibling);

}

// 编程求得孩子兄弟表示法存储的森林的叶子结点的个数
// 递归的思路：结点无孩子则该结点必为叶子结点
bool isLeaf(Tree T) 
{
		if (T->leftChild == NULL) 
			return true;
		else 
			return false;
}
int CountLeaves(Tree root)
{
	if (!root) 
	{
		return 0;
	}
	else
	{
	    int count = 0;
		while (root != NULL) 
		{
			if (isLeaf(root)) 
			{
				count++;
			}
			count += CountLeaves(root->leftChild);
			root = root->rightSibling;
		}
		return count;
	}
}

int height(Tree root)
{
	//int hchild, hsibling;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int depth = 0;
		int childdepth = height(root->leftChild);
		int brotherdepth = height(root->rightSibling);
		depth = childdepth + 1 > brotherdepth ? childdepth + 1 : brotherdepth;
		return depth;
	}
}
//主函数
int main(void)
{
	Tree T;

	int deepth, num = 0;
	printf("请输入第一个结点的值,-1表示没有对应子树:\n");
	CreateForest(&T);
	printf("先序遍历森林:\n");
	TraverseForest(T);
	printf("\n");
	printf("后序遍历森林:\n");
	PostOrderForest(T);
	printf("\n");

	num = CountLeaves(T);
	printf("森林的叶子结点个数为:%d", num);
	printf("\n");

	deepth = height(T);
	printf("森林的高度为:%d", deepth);
	printf("\n");

	return 0;
}
