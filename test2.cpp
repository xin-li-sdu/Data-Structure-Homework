#include <iostream>
#include<cstring>
using namespace std;
typedef struct List
{
    int num;
    int next;
}list;
int main()
{
	int n=0,first,sum=0;
	//cin>>n;
	list a[100000];
	int b[100000];
   /* for(int i=0;i<n;i++)
     {
     	cin>>a[i].num;
	 }
	 */
	while(cin.peek()!='\n') 
	  {
	  	cin>>a[n].num;
		  n++;
	  }
	  //cout<<n<<endl;
    for(int i=0;i<n;i++)
     {
     	cin>>a[i].next;
	 }
	 cin>>first;
	 for(int i=first;;)
	 {
	 	if(a[i].next==-1) 
		 {
		 	cout<<a[i].num<<endl;
		 	b[sum++]=a[i].num;
		 	break;
		 }
	 	cout<<a[i].num<<" ";
	 	b[sum++]=a[i].num;
	 	i=a[i].next;
	 }
	 for(int i=1;i<n;++i)
	   cout<<i<<" ";
	cout<<"-1"<<endl;
	//cout<<sum;
//	for(int i=0;i<sum;++i)
	//   cout<<b[i]<<" ";
    return 0;
}

