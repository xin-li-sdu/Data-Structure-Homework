#include<iostream>
using namespace std;
class Node 
{
private:
	int size;
	int top;
	int** stack;  //用二维数组代替结构题 
public:
	Node(int sizeValue)   //初始化 
	{
		size = sizeValue;
		stack = new int* [size];
		for (int i = 0; i < size; i++) 
		{
			stack[i] = new int[2];
			stack[i][0] = stack[i][1] = -1;
		}
		top = 0;
	}
	bool push(int rank, int number) 
	{
		if (top == size - 1) 
			return false;
		top += 1;
		stack[top][0] = rank;
		stack[top][1] = number;
		return true;
	}
	bool pop() 
	{
		if (top == 0) 
		{
			return false;
		}
		stack[top][0] = stack[top][1] = -1;
		top -= 1;
		return true;
	}
	void getmax(int* array, int arraySize) 
	{
		int area = 0;
		for (int i = 0; i < arraySize; i++) 
		{
			if (array[i] > stack[top][1]) 
			{
				push(i, array[i]);
			}
			else if (array[i] < stack[top][1]) 
			{
				while (array[i] < stack[top][1])
				 {
					int height = stack[top][1];
					int width = i - stack[top - 1][0] - 1;
					area = max(height * width, area);
					pop();
				}
				push(i, array[i]);
			}
		}
		cout << area << endl;
	}
};
int main() 
{
	int arraySize=1;
	int* array = new int[1000000];
	while(cin.peek()!='\n')
	{
	  cin>>array[arraySize++];
	} 
	array[arraySize + 1] = 0;
	Node test(arraySize + 2);
	test.getmax(array, arraySize + 2);
	return 0; 
}
