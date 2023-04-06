#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include<iostream> 
#include<windows.h>
using namespace std;
long long n2[30] {1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484,7174453,21523360,64570081,193710244,581130733,1743392200,5230176601};
long long n3[30] {1, 5, 19, 41, 109, 209, 505, 929, 2161,3905, 8929, 16001, 36289, 64769, 146305,260609, 587521, 
1045505, 2354689, 4188161,9427969, 16764929, 37730305, 67084289};
int shell_sort(long long arr[],long long n)
{
    long long i, j, tmp;
    int num=0;
    for(long long step = n/2; step > 0;step /= 2)
    {
    	//cout<<step<<" ";
        for(i = step; i < n; i++)
        {
            tmp = arr[i];
            j = i - step;
            for(;j >= 0 && tmp < arr[j];)
            {
                arr[j + step] = arr[j];
                j -= step;
                
            }
            arr[j + step] = tmp;
        }
    }
}
int shell_sort2(long long arr[],long long n)
{
    long long  tmp,beg;
    for (int i = 18; i >= 0; i--)
	  if (n2[i]<= n/2)
		{
			beg = i;
		//	cout<<n2[beg]<<endl; 
			break;
		}
	long long j;
    for(long long step = n2[beg]; step > 0;step = n2[--beg])
    {
    	//cout<<step<<" ";
        for(long long i = step; i < n; i++)
        {
            tmp = arr[i];
            j = i - step;
            for(;j >= 0 && tmp < arr[j];)
            {
                arr[j + step] = arr[j];
                j -= step;
            }
            
            arr[j + step] = tmp;
        }
    }
}
int shell_sort3(long long arr[],long long n)
{
    long long  tmp,beg;
    for (int i = 19; i >= 0; i--)
	  if (n3[i]<= n)
		{
			beg = i;
			break;
		}
	long long j;
    for(long long step = n3[beg]; step > 0;step = n3[--beg])
    { 
        //cout<<step<<" ";
        for(long long i = step; i < n; i++)
        {
            tmp = arr[i];
            j = i - step;
            for(;j >= 0 && tmp < arr[j];)
            {
                arr[j + step] = arr[j];
                j -= step;
            }
            arr[j + step] = tmp;
        }
    }
}
int shell_sort4(long long arr[],long long n)
{
    long long i, j, tmp;
    int num=0;
    for(long long step = n/3; step > 0;step /= 3)
    {
       // cout<<step<<" ";
		for(i = step; i < n; i++)
        {
            tmp = arr[i];
            j = i - step;
            for(;j >= 0 && tmp < arr[j];)
            {
                arr[j + step] = arr[j];
                j -= step;
                
            }
            arr[j + step] = tmp;
        }
    }
}
int main()
{
	long long LENGTH;
	cout<<"请输入排序数组规模（建议大于10万）:";
    cin>>LENGTH;
    long long *arr = new long long[LENGTH];
    
    for (long long i = 0; i < LENGTH; i++) 
		arr[i] = rand() % LENGTH;
    int t1 = GetTickCount();
    shell_sort(arr,LENGTH);
    int t2 = GetTickCount();
    cout<<"Shell增量{N/2}的时间开销："<<t2-t1<<"ms"<<endl;
    
    for (long long i = 0; i < LENGTH; i++) 
		arr[i] = rand() % LENGTH;
    t1 = GetTickCount();
    shell_sort4(arr,LENGTH);
    t2 = GetTickCount();
    cout<<"增量{N/3}的时间开销："<<t2-t1<<"ms"<<endl;
    
    for (long long i = 0; i < LENGTH; i++) 
		arr[i] = rand() % LENGTH;
    t1 = GetTickCount();
    shell_sort2(arr,LENGTH);
    t2 = GetTickCount();
    cout<<"Knuth增量{（3^k-1）/2}的时间开销："<<t2-t1<<"ms"<<endl;
    
    for (long long i = 0; i < LENGTH; i++) 
		arr[i] = rand() % LENGTH;
    t1 = GetTickCount();
    shell_sort3(arr,LENGTH);
    t2 = GetTickCount();
    cout<<"Sedgewick增量{9*4^k-9*4^k+1或4^k-3*2^k+1}的时间开销："<<t2-t1<<"ms"<<endl;
     //for (long long i = 0; i < LENGTH; i++) 
	//	cout<<arr[i]<<" ";
}
