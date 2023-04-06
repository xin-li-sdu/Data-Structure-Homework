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
	int n,first;
	cin>>n;
	list a[100000];
    for(int i=0;i<n;i++)
     {
     	cin>>a[i].num;
	 }
    for(int i=0;i<n;i++)
     {
     	cin>>a[i].next;
	 }
	 cin>>first;
	 for(int i=first;;)
	 {
	 	cout<<a[i].num<<" ";
	 	i=a[i].next;
	 }
    return 0;
}
10
3 7 5 21 8 14 11 17 13 11
7 9 4 6 1 8 5 2 0 -1
3
