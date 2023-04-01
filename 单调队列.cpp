#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int* a = new int[n];
	int* q = new int[k];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int left = 0, right = -1;      //递减队列的左右边界
	for (int i = 0; i < n; i++)
	{
		while (right >= left && a[i] > a[q[right]])
			right--;		//遇到更大的元素
		q[++right] = i;
		if (q[right] - q[left] + 1 > k)
			left++;	//保证队列中最多只有k个元素
		if (i - k + 1 >= 0)
			cout << a[q[left]] << " ";	//最大值在left上
	}
	delete a; delete q;
	return 0;
}