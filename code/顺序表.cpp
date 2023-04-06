#include<iostream>
#include<cstring>
using namespace std;
template<class T>
class arrList
{
private:
    T* number;
    int maxSize;
public:
    arrList(const int size)
    {
        maxSize = size;
        number = new T[maxSize];
        for (int i = 0; i < maxSize; i++)
            number[i] = 0;
    }
    ~arrList()
    {}
    void print()
    {
        int i = 0;
        for (i = maxSize - 1; i > 0; i--)
        {
            if (number[i] != 0)
                break;
        }
        if (i == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << number[i] << " " << i;
            for (; i - 1 >= 0; i--)
            {
                if (number[i - 1] != 0)
                {
                    cout << " " << number[i - 1] << " " << i - 1;
                }
            }
        }
    }
    bool setValue(const T numberValue, const T indexValue);
    void add(arrList<T> a, arrList<T> b);//求和函数 
};
template<class T>
bool arrList<T>::setValue(const T numberValue, const T indexValue)
{
    number[indexValue] += numberValue;//牺牲空间换时间，使指数与数组位置相同 ，方便查找 
    return true;
}
template<class T>
void arrList<T>::add(arrList<T> a, arrList<T>b)
{
    for (int i = 0; i < maxSize - 1; i++)
        number[i] = a.number[i] + b.number[i];
}
int main()
{
    arrList<int> La(100001), Lb(100001), Lc(100001);
    int size;
    int number, index;
    while (cin.peek() != '\n')
    {
        cin >> number >> index;
        La.setValue(number, index);
    }
    cin.get();
    while (cin.peek() != '\n')
    {
        cin >> number >> index;
        Lb.setValue(number, index);
    }
    Lc.add(La, Lb);
    Lc.print();
    La.~arrList();
    Lb.~arrList();
    Lc.~arrList();
    return 0;
}