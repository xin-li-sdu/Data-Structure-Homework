#include<iostream>
using namespace std;
int n, m,edge=0;
int Matrix[501][501];
struct pNode 
{
    int headvex, tailvex;//弧尾（始点）-->弧头（终点）
    int info;//权值，没用到 
    pNode* nxt_to = NULL;//指向下一条相同头节点的弧 
    pNode* nxt_from = NULL;////指向下一条相同尾结点的弧 
};
pNode list[250000];   //十字链表的边表 
pNode* head_from[501];//指向该顶点的第一条进弧  
pNode* head_to[501];//指向该顶点的第一条出弧
//十字链表的顶点表 
void LinkedList(int u, int v) 
{
    edge++;
    list[edge].tailvex = u;//弧尾（始点）
    list[edge].headvex = v;//弧头（终点）
    //头插法插入弧结点
    list[edge].nxt_from = head_from[u];
    list[edge].nxt_to = head_to[v];
    head_from[u] = &list[edge];
    head_to[v] = &list[edge];
    return ;
}
void change() //转换邻接矩阵为十字链表
{
    for (int i = n; i >= 1; i--) 
      for (int j = n; j >= 1; j--)
        if (Matrix[i][j]==1) //如果i和j之间边存在 
            LinkedList(i, j);////头插法插入弧结点
          else continue; 
    return ;
}
void print()//打印十字链表 
{
	for (int i = 1; i <= n; i++) 
	{
        for (pNode* j = head_from[i]; j; j = j->nxt_from)//以每一个顶点为一行打印结果 
        //为了符合正常思维，下标从1开始一直到n。 
		{
            cout<<"当前边节点地址："<<j<<" "<<"起点下标为"<<j->tailvex<<" "<<"终点下标为"<<j->headvex<<" ";
		    cout<<"指向下一条相同头节点的弧:"<<j->nxt_to<<" ";
			cout<<"指向下一条顶相同尾结点的弧 :"<<j->nxt_from<<" ";
        }
        if(head_from[i]!=0) cout<<endl;//把具有相同起点的边结点的信息输出在同一行
    }
    return ;
 } 
int main() 
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) 
            cin>>Matrix[i][j];     //构造邻接矩阵 
    change();      //转换邻接矩阵为十字链表 
    print();       //打印十字链表 
    return 0;
}
