#include <cstdio>
#include<iostream>
using namespace std;
#define MINKEY -1  //假设所有数据都大于与该值
#define MAXKEY 999 //假设所有数据都小与该值
#define SWAP(a,b) {a=a^b;b=b^a;a=a^b;}
void adjust(int* ,int* ,int,int );
void createLoserTree(int *[], int* ,int* ,int );
void kMerge(int* [], int* , int , int* , int*);

int main()
{
    //总共有5个片段需要归并
    int arr0[] = { 6, 15, 25 };
    int arr1[] = { 12, 37, 48 };
    int arr2[] = { 10, 15, 16 };
    int arr3[] = { 9, 18, 20 };
    int arr4[] = { 34, 36, 40 };
    int arr5[] = { 3, 35, 46 };
    int arr6[] = { 666, 889, 678 };
    int arr7[] = { 21, 56, 140 };
    int* arr[] = { arr0, arr1, arr2, arr3, arr4, arr5, arr6, arr7,};
    
    //总共K路
    int k = sizeof(arr) / sizeof(arr[0]);
    //记录每一路的个数，用于判断结束的标记
    int arrayCount[k];
    arrayCount[0] = sizeof(arr0) / sizeof(arr0[0]);
    arrayCount[1] = sizeof(arr1) / sizeof(arr2[0]);
    arrayCount[2] = sizeof(arr2) / sizeof(arr2[0]);
    arrayCount[3] = sizeof(arr3) / sizeof(arr3[0]);
    arrayCount[4] = sizeof(arr4) / sizeof(arr4[0]); 
	arrayCount[5] = sizeof(arr5) / sizeof(arr5[0]);  
	arrayCount[6] = sizeof(arr6) / sizeof(arr6[0]);  
	arrayCount[7] = sizeof(arr7) / sizeof(arr7[0]);        
    //存放败者树
    int ls[k];
    //存放每一路的首元素
    int b[k+1];
    //创建败者树
    createLoserTree(arr,b,ls,k);
    //进行多路归并
    kMerge(arr, arrayCount, k, ls, b);
}
/**
 * 调整败者树，得出最终胜者
 */
void adjust(int* b,int* ls,int s,int k)
{
    //t为b[s]在败者树中的父结点
    int t = (s + k) / 2;
    while (t > 0) {//若没有到达树根，则继续
        if (b[s] > b[ls[t]]){ //与父结点指示的数据进行比较
            //ls[t]记录败者所在的索引，s指示新的胜者，胜者将去参加更上一层的比较
            SWAP(s,ls[t]);
        }
        t/= 2;//获取下一个父节点
    }
    //最终的胜者记录于ls[0]
    ls[0] = s;
}
/**
 * arry:多路归并的所有数据
 * b:存放多路归并的首地址数组
 * ls:败者树数组
 * k:几路归并
 */
void createLoserTree(int *arry[], int* b,int* ls,int k)
{
    for (int i = 0; i < k; ++i){
        b[i] = arry[i][0];//每一路的首元素进行赋予
    }
    //最后一个元素用于存放默认的最小值，用于刚开始的对比
    b[k] = MINKEY; 
    //设置ls数组中败者的初始值，既b[k]最小值
    for (int i=0; i < k; i++) {
        ls[i] = k;
    }
    
    //有k个叶子节点
    //从最后一个叶子节点开始，沿着从叶子节点到根节点的路径调整
    for (int i = k - 1; i >= 0; --i){
        adjust(b, ls, i, k);
    }
    
}
/**
 *多路归并操作
 */
void kMerge(int* arr[], int* arrayCount, int k, int* ls, int* b)
{
    
    //index数组记录每一路读取的索引，
    int index[k];
    for (int i = 0; i < k; i++){
        index[i] = 0;
    }
    //最终的胜者存储在 is[0]中，当其值为 MAXKEY时，证明5个临时文件归并结束
    while (b[ls[0]]!=MAXKEY) {
        
        //获取胜者索引
        int s = ls[0];
        //输出过程模拟向外存写的操作
        printf("%d ",b[s]);
        //对应的索引路进行++记录
        ++index[s];
    
        //判断是否已经读完
        if (index[s] < arrayCount[s]){
            //没有读完，从第s路中读取数据
             b[s] = arr[s][index[s]];
        }else{
            //已经读完用最大值来表示该路已经结束
            b[s] = MAXKEY;
        }
        //进行调整，让最终胜者的索引存放到ls[0]中 
        adjust(b, ls, s, k);     
    }
}
