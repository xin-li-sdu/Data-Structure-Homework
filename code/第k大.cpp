#include<iostream>
#include<stdio.h>
using namespace std;
int Partition (int *L, int low, int high)
{
	int temp = L[low];
	int pt   = L[low]; 
	while (low != high)
	{
		while (low < high && L[high] >= pt)
			high--;
		L[low] = L[high];		
		
		while (low < high && L[low] <= pt)
			low++;
		L[high] = L[low];
	}	
	L[low] = temp;
	return low;
}
void findk(int k,int *L,int low,int high)
{
	int temp;
	temp=Partition(L,low,high);
	if(temp==k-1)
	{
		cout<<"第"<<temp+1<<"大的数是:"<<L[temp]<<endl;
	}
	else if(temp>k-1)
		findk(k,L,low,temp-1);
	else
		findk(k,L,temp+1,high);
}
int main()
{
	int n,k;
	int a[100000];
	cin>>n;
	for(int i=0;i<n;i++) 
	  cin>>a[i];
	cin>>k;
	findk(k,a,0,n-1); 
	cout<<endl;
	return 0;
}

