#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<list>
#include<queue>
#include<ctime>
using namespace std; 
//202100460065 李昕 
int f[1000],rank[1000];
/*int findx(int x)  //已查询函数
{
    if(f[x] != x)
    f[x] = findx(f[x]);  // 路径压缩优化,
    return f[x];         //将每个元素直接连到所在集合的根上
}*/
int findx(int x)  //未优化的查询函数 
{
	if(x == f[x])
        return x;
    return findx(f[x]);
 } 
//朴素的并查集的时间主要浪费在查询操作上，原因在于当我们需要查询某个节点的根时，
//需要从该节点出发，不断的查询父亲元素直到找到根节点。
int findx_good(int x)  //路径压缩优化查询函数
{
    if(f[x] != x)
    f[x] = findx(f[x]);  // 路径压缩优化,
    return f[x];         //将每个元素直接连到所在集合的根上
}
//采用按秩合并，按秩合并法需要将树中所有节点都增设一个权值，用以表示该节点所在树中的高度（比如用rank[x]=3表示 x 节点所在树的高度为3）。这样一来，在合并操作的时候就能通过这个权值的大小来决定谁当谁的上级。
//在合并操作的时候，假设需要合并的两个集合的代表元分别为 x 和 y，则只需要令f[x] = y 或者f[y] = x 即可。但我们为了使合并后的树不产生退化（即：使树中左右子树的深度差尽可能小），
//那么对于每一个元素 x ，增设一个rank[x]数组，用以表达子树 x 的高度。在合并时，如果rank[x] < rank[y]，则令f[x] = y；否则令f[y] = x。
void uni(int x,int y) //合并集合 
{
  f[findx(x)] = findx(y);
}
void unioni_good(int x,int y)
{
    x=findx(x);							//寻找 x的代表元
    y=findx(y);							//寻找 y的代表元
    if(x==y) return ;					//如果 x和 y的代表元一致，说明他们共属同一集合，则不需要合并，直接返回；否则，执行下面的逻辑
    if(rank[x]>rank[y]) f[y]=x;		//如果 x的高度大于 y，则令 y的上级为 x
    else								//否则
    {
        if(rank[x]==rank[y]) rank[y]++;	//如果 x的高度和 y的高度相同，则令 y的高度加1
        f[x]=y;						//让 x的上级为 y
    }
}
bool same(int x, int y)
{
    return findx(x) == findx(y);
}
int main()
{
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++) //并查集初始化,每个自身为一个集合 ，同时初始化秩 
      {
      	f[i] = i; 
      	rank[i]=1;
	  }
    for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		unioni_good(a,b);
	 } 
    for(int i=1;i<=n;i++)
    {
    	if(findx(i)==i)
    	{
    		cout<<i<<" ";
    		for(int j=1;j<=n;j++)
    		{
    			if(findx(j)==i&&i!=j)
    			  cout<<j<<" ";
			}
		cout<<endl;
		}
	}
    return 0;
}
//202100460065 李昕 
