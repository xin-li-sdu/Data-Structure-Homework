#include<iostream>
using namespace std;

#define max 100
#define maxInt 32767

//定义图
typedef struct {
	char vexs[1000];  //顶点表
	int arcs[1000][1000];  //矩阵
	int vexnum;  //顶点值
	int arcnum;  //边值
}AMGraph;

//权值最小边
struct POINT{
	char adjvex;  //顶点
	int lowcost;  //权值
}closeedge[1000];

//确定位置函数
int LocalVex(AMGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == v)
		{
			return i;
		}
	}
	return -1;
}


//创建无向图
void CreatUDN(AMGraph & G) {
	int i, j, k;
	cout << "please input the num of vex and arcs of Graph，seperate them with spece key：" << endl;
	cin >> G.vexnum >> G.arcnum;  //输入顶点数和边数
	cout << endl;
	//输入顶点信息
	cout << "please input name of vexs as a：" << endl;
	for ( i = 0; i < G.vexnum; i++)
	{
		cout << "please the name of " << (i + 1) << " vex：";
		cin >> G.vexs[i];
	}
	cout << endl;
	
	//输入权值
	//初始化
	for (i = 0; i < G.vexnum; i++) {
		//顶点
		for ( j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = maxInt; //置为最大值
		}
	}

	//边的数量
	cout << "please input the vexs of arc and corresponding weight as a b 1:" << endl;
	for (k = 0; k < G.arcnum; k++) {
		char v1, v2;
		int weight;
		cout << "please input the vex name and weight of" << (k + 1) << "arc:";
		cin >> v1 >> v2 >> weight;
		
		i = LocalVex(G, v1);
		j = LocalVex(G, v2);
		G.arcs[i][j] = weight;  //将权值赋值
		G.arcs[i][j] = G.arcs[i][j];
	}
}

//权值最小边
int Min(AMGraph G) {
	int index = -1;
	int min = maxInt;
	for (int i = 0; i < G.vexnum; i++) {
		if (min > closeedge[i].lowcost && closeedge[i].lowcost != 0) { //找出最小的以及不在同一集合中的
			min = closeedge[i].lowcost;
			index = i;
		}
	}
	return index;
}

//最小生成树算法
void prime(AMGraph G, char u) {
	//先构造起始顶点
	int k, i, j;
	char u0, v0;
	k = LocalVex(G, u);
	for (j = 0; j < G.vexnum; j++)
	{
		if (j != k) {
			closeedge[j].adjvex = u;
			closeedge[j].lowcost = G.arcs[k][j];
		}
	}
	closeedge[k].lowcost = 0;
	for (i = 1; i < G.vexnum; i++)
	{
		k = Min(G); //找出最短边
		u0 = closeedge[k].adjvex;  //找出最短边对应的顶点
		v0 = G.vexs[k];
		cout << "arc " << u0 << "---->" << v0 << endl;
		closeedge[k].lowcost = 0;

		//更新数组
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[k][j] < closeedge[j].lowcost)
			{
				closeedge[j].adjvex = G.vexs[k];
				closeedge[j].lowcost = G.arcs[k][j];
			}
		}
	}
}

int main() 
{
	AMGraph G;
	CreatUDN(G);
	prime(G,'a');
	return 0;
}


