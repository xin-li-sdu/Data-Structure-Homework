#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int ans[510][510];
int n,indegree[510];
void tuopu()
{
	int i,j,t,top;
	priority_queue<int,vector<int>,greater<int> > q;//从小到大排序 
    for(i=1;i<=n;++i)
    {
    	if(indegree[i]==0)
    		q.push(i);
    }
    int sign=1;
    while(!q.empty())
    {
    	top=q.top();
    	q.pop();
    	indegree[top]=-1;
    	if(sign)
    	{
    		cout<<top;
    		sign=0;
    	}
    	else   
		    cout<<" "<<top;
		for(i=1;i<=n;++i)
		{
			if(ans[top][i])
			{
				indegree[i]--; 
			    if(indegree[i]==0)
				    q.push(i);
			} 
			  
		}
    }
} 
int main()
{
	int i,m,a,b,ins=0;
	while(cin>>n>>m)
	{
		memset(indegree,0,sizeof(indegree));
		memset(ans,0,sizeof(ans));//重新初始化数组 
		for(i=0;i<m;++i)
		{
			cin>>a>>b;
			if(ans[a][b]==0)
			{
				ans[a][b]=1;
				indegree[b]++;
			}
		}
		tuopu();
		if(cin.peek()!=' ') cout<<endl;
	}
	return 0;
}
