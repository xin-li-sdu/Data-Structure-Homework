#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
    double x,y;
}location[1001];//坐标数组 
double dis[1001];//辅助数组，表示从起点到达编号为i的点的最短路径 
int vis[1001];//标记当前点是否被访问 
int n,m;//点,边的个数 
int from,to;//起点终点 
double map[101][101];//邻接矩阵存图  
priority_queue< pair<double,int> > q;//利用pair来存 dis[i]和i的关系； 
/*void Dijkstra(int u)
{
     for(int i=1;i<=n;i++)
        dis[i]=map[u][i];//二次初始化dis 
     dis[u]=0;
     vis[u]=1;
     for(int i=1;i<=n;i++)//循环n次
     {
         double minn=99999999;
         int k=-1;//k使d[k]最小，minn存放该最小的d[k]的值 
         for(int j=1;j<=n;j++) //找到未访问的顶点中d[j]最小的
         {
             if((dis[j]<=minn)&&vis[j]==0)
             {
                minn=dis[j];//记录当前最小的d[k]（即d[j]）的值 
                k=j;//记录当前最小的d[k] 
            }
        }
         vis[k]=1;//标记k为已访问
        for(int j=1;j<=n;j++)
         {
         	 //如果j未访问 && k能到达j && 以k为中介点可以使dis[j]更优
             if((dis[j]>=dis[k]+map[k][j])&&vis[j]==0&&map[k][j]!=1000000)
               dis[j]=dis[k]+map[k][j];//优化d[j]
			  
         }
     }
}*/
void Dijkstra_queue(int u)
{
	q.push(make_pair(0,u));
    dis[u]=0;
    while(!q.empty())
    {
        int k=q.top().second;//队首出队
        q.pop();
        if(vis[k]==1) continue;
        vis[k]=1;
        for(int j=1;j<=n;j++)
         {
         	 //如果j未访问 && k能到达j && 以k为中介点可以使dis[j]更优
             if((dis[j]>=dis[k]+map[k][j])&&vis[j]==0&&map[k][j]!=1000000)
               {
			     dis[j]=dis[k]+map[k][j];//优化d[j]
			     q.push(make_pair(-dis[j],j));
		       }
         }
    }
}
void readpoint()
{
 	cin>>n;//读取节点个数 
    for(int i=1;i<=n;i++)         
	  cin>>location[i].x>>location[i].y;//把节点坐标读进来 
    cin>>m;//读取连线（边） 个数 
    for(int i=1;i<=m;i++)
    {
        int p,q;
        cin>>p>>q;
        double y=sqrt(pow(location[p].x-location[q].x,2)+pow(location[p].y-location[q].y,2));//求一下长度 
        map[p][q]=y;//无向图双向存边 
        map[q][p]=y;
    }
}
 int main()
 {
     memset(map,1000000,sizeof(map));//初始化矩阵 (无边则超级大)
     memset(dis,1000000,sizeof(dis));//初始化辅助数组 （没试过则超级大） 
     memset(vis,0,sizeof(vis));//访问初始化（无访问则为0） 
     readpoint();
     cin>>from>>to;
     //Dijkstra(from);
     Dijkstra_queue(from);//堆优化 
     printf("%0.2lf",dis[to]);
     return 0;
 }
