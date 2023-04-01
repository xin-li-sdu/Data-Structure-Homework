#include<iostream>
using namespace std;
const int maxn = 1000000;
typedef long long LL;
LL x, sum, n;
namespace MakeHeap 
{
    LL size;
    LL heap[maxn];
    void swap(LL &aa, LL &bb) { aa ^= bb ^= aa ^= bb; }
    void up(LL p) {
        while (p > 1) {
            if (heap[p] < heap[p / 2]) {
                swap(heap[p], heap[p / 2]);
                p /= 2;
            }
            else break;
        }
    }
    inline void insert(LL val) 
	{
        heap[++size] = val;
        up(size);
    }
    LL GetTop() { return heap[1]; }
    void down(LL p) {
        LL s = p * 2;
        while (s <= size) {
            if (s < size && heap[s] > heap[s + 1]) s++;
            if (heap[s] < heap[p]) {
                swap(heap[s], heap[p]);
                p = s, s = p * 2;
            }
            else break;
        }
    }
    void Extract() 
	{ 
        heap[1] = heap[size--];
        down(1);
    }
}
using namespace MakeHeap;

int main() 
{
    cin>>n;
    for (int i = 1; i <= n; ++i) 
	{
        cin>>x; 
		insert(x);
    }
    sum = 0;
    while (size > 1) 
	{
        LL x1 = GetTop();
        Extract();
        LL x2 = GetTop();
        Extract();
        sum += (x1 + x2);
        insert(x1 + x2);
    }
    printf("%lld\n", sum);
    return 0;
}

//模板切割n-1的最小花费
 
