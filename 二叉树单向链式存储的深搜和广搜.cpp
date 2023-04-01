#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 200
typedef int ElemType;
//数据类型
//定义二叉树结构
typedef struct BiTNode 
{
	ElemType data;	//数据域struct BiTNode
	BiTNode* lChild, * rChild;	//左右子树域
}*BiTree;

typedef struct queue
{
	BiTNode array[MAX_QUEUE_SIZE];
	int front;
	int rear;
}SqQueue;

//循环队列基本操作
//初始化队列
SqQueue* Init_CirQueue()
{
	SqQueue* Q = (SqQueue*)malloc(sizeof(SqQueue));
	if (!Q)
		exit(0);
	Q->front = Q->rear = 0;
	return(Q);
}
//判断队列是否为空
bool IsEmpty_Queue(SqQueue* Q)
{
	if (Q->front == Q->rear)
		return 1;       /*  队列空，返回失败标志  */
	return 0;
}
//判断队列是否已满
bool IsFull_Queue(SqQueue* Q)
{
	if ((Q->rear + 1) % MAX_QUEUE_SIZE == Q->front)	/*  队满*/
		return 1;
	return 0;
}
//统计队列中元素个数
int Size_Queue(SqQueue* Q)
{
	return (Q->rear + MAX_QUEUE_SIZE - Q->front) % MAX_QUEUE_SIZE;
}
//往队列中插入元素
bool Push(SqQueue* Q, BiTNode e)
/*  将数据元素e插入到循环队列Q的队尾  */
{
	if (IsFull_Queue(Q))	/*  队满*/
	{
		printf("Insert: The queue is full.\n");
		return 1;
	}
	Q->array[Q->rear].data = e.data;   /*  元素e入队  */
	Q->array[Q->rear].lChild = e.lChild;
	Q->array[Q->rear].rChild = e.rChild;
	Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	/*  队尾指针向前移动  */
	return 0;        /*  入队成功    */
}
//取队首元素
bool Pop(SqQueue* Q, BiTNode* x)
/*  将循环队列Q的队首元素出队  */
{
	if (IsEmpty_Queue(Q))	/*  队空，返回错误标志    */
	{
		printf("The queue is empty.\n");
		return 1;       /*  队列空，返回失败标志  */
	}
	x->data = Q->array[Q->front].data;   /*  取栈顶元素  */
	x->lChild = Q->array[Q->front].lChild;
	x->rChild = Q->array[Q->front].rChild;
	Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
	/*  队首指针向前移动  */
	return 0;
}

//先序创建二叉树
int CreateBiTree(BiTree* T)
{
	ElemType ch;
	ElemType temp;
	scanf("%d", &ch);
	temp = getchar();
	if (ch == -1)
		* T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!(*T))
			exit(-1);
		(*T)->data = ch;
		printf("输入%d的左子节点：", ch);
		CreateBiTree(&(*T)->lChild);
		printf("输入%d的右子节点：", ch);
		CreateBiTree(&(*T)->rChild);
	}
	return 1;
}
//先序遍历二叉树
void TraverseBiTree(BiTree T)
{
	if (T == NULL)return;
	printf("%d ", T->data);
	TraverseBiTree(T->lChild);
	TraverseBiTree(T->rChild);
}
//中序遍历二叉树
void InOrderBiTree(BiTree T)
{
    if (T == NULL)return;
	TraverseBiTree(T->lChild);
	printf("%d ", T->data);
	TraverseBiTree(T->rChild);

}
//后序遍历二叉树
void PostOrderBiTree(BiTree T)
{
	if (T == NULL)return;
	TraverseBiTree(T->lChild);
	TraverseBiTree(T->rChild);
    printf("%d ", T->data);

}
//二叉树的深度（递归算法） 
int TreeDeep(BiTree T)
{
	int deep = -1;
	if (T) 
	{
		int leftdeep = TreeDeep(T->lChild);
		int rightdeep = TreeDeep(T->rChild);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}
	return deep;
}

int TreeDeep_norecursion(BiTree T)//（利用bfs层序遍历，循环队列先进先出） 
{
	int deep = -1;
	if (T) {
		SqQueue* Q = NULL;
		Q = Init_CirQueue();
		Push(Q, *T);
		while (!IsEmpty_Queue(Q))
		{
			int len = Size_Queue(Q);
			deep++;
			while (len--) 
			{
				BiTNode temp;
				Pop(Q, &temp);
				if (temp.lChild)
					Push(Q, *temp.lChild);
				if (temp.rChild)
					Push(Q, *temp.rChild);
			}
		}
	}
	return deep;
}
//判断结点度是否为1
bool isAlone(BiTree T) 
{
	if (T->lChild == NULL && T->rChild != NULL) 
	{
		return true;
	}
	else if(T->lChild != NULL && T->rChild == NULL)
	{
			return true;
	}
	else {
			return false;
	}
	}
//求二叉树度为1的结点个数
int Degree1count(BiTree T)
{
	int num = 0;
    if (T) 
	{
		if (isAlone(T))
		{
			num++;
		}
		num +=Degree1count(T->lChild) ;
		num +=Degree1count(T->rChild) ;
	}
	return num;
}

int Degree1count_norecursion(BiTree T)
{
	int num = 0;
	if (T) 
	{
		SqQueue* Q = NULL;
		Q = Init_CirQueue();
		Push(Q, *T);
		while (!IsEmpty_Queue(Q))
		{
			int len = Size_Queue(Q);
			while (len--) 
			{
				BiTNode temp;
				Pop(Q, &temp);
				if(isAlone(&temp)) num++;
				if (temp.lChild)
					Push(Q, *temp.lChild);
				if (temp.rChild)
					Push(Q, *temp.rChild);
			}
		}
	}
	return num;
}
//主函数
int main(void)
{
	BiTree T;

	int deepth=-1, num = 0;
	printf("请输入第一个结点的值,-1表示没有对应子树:\n");
	CreateBiTree(&T);
	printf("先序遍历二叉树:\n");
	TraverseBiTree(T);
	printf("\n");
	printf("中序遍历二叉树:\n");
	InOrderBiTree(T);
	printf("\n");
	printf("后序遍历二叉树:\n");
	PostOrderBiTree(T);
	printf("\n");
	deepth = TreeDeep(T);
	printf("（递归）树的深度为:%d", deepth);
	printf("\n");
	deepth = TreeDeep_norecursion(T);
	printf("（非递归）树的深度为:%d", deepth);
	printf("\n");
	num = Degree1count(T);
	printf("(递归)树的度为1的结点个数为:%d", num);
	printf("\n");
	num = Degree1count_norecursion(T);
	printf("（非递归）树的度为1的结点个数为:%d", num);
	printf("\n");
	return 0;
}



/* 非递归遍历方法（dfs）：实现思路，在进行后序遍历的时候是先要遍历左子树，然后在遍历右子树，最后才遍历根节点。所以在非递归的实现中要先把根节点入栈
     /* 然后再把左子树入栈直到左子树为空，此时停止入栈。此时栈顶就是需要访问的元素，所以直接取出访问p。在访问结束后，还要判断被访
     /* 问的节点p是否为栈顶节点的左子树，如果是的话那么还需要访问栈顶节点的右子树，所以将栈顶节点的右子树取出赋值给p。如果不是的
    / * 话则说明栈顶节点的右子树已经访问完了，那么现在可以访问栈顶节点了，所以此时将p赋值为null。判断结束的条件是p不为空或者栈
    / * 不为空，若果两个条件都不满足的话，说明所有节点都已经访问完成
     
     
/*bfs方法：从根结点开始,先放入队列,而后循环判断队列是否为空,非空,取出结点,打印数据域,而且依次将左孩子,右孩子放入队列,
/*借助队列的特性,先进先出,来进行层序遍历,最后队列为空,循环中止,遍历结束递归 【注意，本题之所以使用循环队列就是层序遍历求树的高度deepth】 
