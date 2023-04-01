#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV = 1000;	//最大顶点数
const int INF = 1000000000;		//设INF为一个很大的数
 
//边集定义部分 
struct edge {
	int u,v;	//边的两个端点编号
	int cost;	//边权 
}E[MAXV]; 	//最多有MAXV条边 
 
bool cmp(edge a,edge b)
{
	return a.cost < b.cost;
} 
//并查集部分 
int father[MAXV];	//并查集数组
int findFather(int x)
{	//并查集查询函数 
	int a=x;
	while(x != father[x]){
		x = father[x];
	}
	//路径压缩
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[x] = x; 
	} 
	return x;
} 
 
//kruskal函数返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
int kruskal(int n,int m)
{
	//ans为所求边权之和，Num_Edge为当前生成树的边数
	int ans = 0, Num_Edge = 0;
	for(int i=1; i<= n;i++)
	{	//假设题目中顶点范围为[1,n] 
		father[i] = i;	//并查集初始化 
	} 
	sort(E,E+m,cmp);	//所有边按边权从小到大排序
	for(int i=0;i<m;i++){	//枚举所有边 
		int faU = findFather(E[i].u);	//查询测试边所在的集合根结点
		int faV = findFather(E[i].v);
		if(faU != faV){		//如果不在一个集合 
			father[faU] = faV;	//合并集合（即把测试边加入最小生成树中） 
			ans += E[i].cost;	//边权之和增加测试边的边权
			Num_Edge++;	//生成树的边数+1
			if(Num_Edge == n-1)	//边数等于顶点数减一时结束算法 
				break; 
		}
	} 
	if(Num_Edge != n-1)
		return -1;	//无法连通，返回-1
	else
		return ans;	//返回最小生成树的边权之和 
} 
 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);	//顶点个数，边数，起点编号
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);	//两个端点编号、边权 
	} 
	int ans = kruskal(n,m);	// kruskal算法入口
	printf("%d\n",ans);
	return 0; 
} 

