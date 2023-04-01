#include <iostream>
using namespace std;
template <typename Type> 
class Heap 
{
private:
	Type *data;
	int size;
	void update(int pos, int n) 
	{
		int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
		int max_value = pos;
		if (lchild < n && data[lchild] < data[max_value])
		 {
			max_value = lchild;
		}
		if (rchild < n && data[rchild] < data[max_value])
		 {
			max_value = rchild;
		}
		if (max_value != pos) 
		{
			swap(data[pos], data[max_value]);
			update(max_value, n);
		}
	}
public:
	Heap(int length_input) {
		data = new Type[length_input];
		size = 0;
	}
	~Heap() {
		delete[] data;
	}
	void push(Type value) {
		data[size] = value;
		int current = size;
		int father = (current - 1) / 2;
		while (data[current] < data[father]) {
			swap(data[current], data[father]);
			current = father;
			father = (current - 1) / 2;
		}
		size++;
	}
	Type top() {
		return data[0];
	}
	void pop() {
		swap(data[0], data[size - 1]);
		size--;
		update(0, size);
	}
	int heap_size() {
		return size;
	}
};
 
 
int main() {
	int n;
	cin >> n;   //有多少个元素
	Heap<int> heap(n);   ///使用了stl里的堆 
	for (int i = 1; i < =n; i++) 
	{
		int num;
		cin >> num;
		heap.push(num);
	}
	int ans = 0;
	//如果只有一个元素的话
	if (n == 1) {
		ans += heap.top();
	}
 
	//如果有多个元素的话
	while (heap.heap_size() > 1) {
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();
		ans += a + b;
		heap.push(a + b);   //计算权值相加后的结果
	}
 
	cout << ans << endl;
	system("PAUSE");
	return 0;
}
