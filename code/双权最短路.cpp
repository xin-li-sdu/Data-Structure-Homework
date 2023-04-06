#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int map[1001][1001];
int cost[1001][1001];
int vis[1000001];
int dis[1000001],lesscost[1000001];
int st,to;
int n;
void Dijkstra()
{
	int k=-1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)//第一次给low，lesscost赋值 
	{
		dis[i]=map[st][i];
		lesscost[i]=cost[st][i];
	}
	vis[st]=1;
	for(int i=1;i<=n;i++)
	{
		int min =100000;
		for(int j=1;j<=n;++j)
		{
			if(!vis[j]&&min>dis[j])
			{
				min=dis[j];
				k=j;
			}
		}
		vis[k]=1;
		for(int j=1;j<=n;++j)
		{
			if(vis[j]==0&&dis[j]>dis[k]+map[k][j])
			{
				dis[j]=dis[k]+map[k][j];
				lesscost[j]=lesscost[k]+cost[k][j];
			}
			else if(vis[j]==0&&dis[j]==dis[k]+map[k][j]&&lesscost[j]>lesscost[k]+cost[k][j])
			{
				dis[j]=dis[k]+map[k][j];
				lesscost[j]=lesscost[k]+cost[k][j];
			}
		}
	} 	
}
int main()
{
	int m;
	int u,v,len,val;
	int i,j;
	while(scanf("%d%d",&n,&m),n+m!=0)
	{
		memset(cost,1000000,sizeof(cost));
		memset(map,1000000,sizeof(map));
		for(i=1;i<=m;i++)
		{
			cin>>u>>v>>len>>val;
			cost[u][v]=val;
			cost[v][u]=val;
			map[u][v]=len;
			map[v][u]=len;
		}
		cin>>st>>to;
		Dijkstra();
		cout<<dis[to]<<" "<<lesscost[to]<<endl;
	}
	return 0;
}
