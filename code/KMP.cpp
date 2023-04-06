#include<iostream>
#include<cstring>
using namespace std;
int* findNext(string Pbox)   //就是前后缀匹配数组向后进位然后最前面-1； 
{
//https://www.bilibili.com/video/BV1Px411z7Yo/?spm_id_from=333.788.recommend_more_video.2
	int i = 0;
	int j = -1;
	int size = Pbox.length();
	int* next = new int[size];
	next[0] = -1;
	while (i < size) 
	{
		while (j >= 0 && Pbox[i] != Pbox[j]) 
		{
			j = next[j];
		}
		i++;
		j++;
		if (i == size) 
		{
			break;
		}
		if (Pbox[i] == Pbox[j])
		 {
			next[i] = next[j];
		}
		else 
		{
			next[i] = j;
		}
	}
	return next;
}
int KMP(const string T, const string P, int* next)
 {
	int i = 0;
	int j = 0;
	int pLen = P.length();
	int tLen = T.length();
	if (tLen < pLen) {
		return -1;
	}
	while (i < pLen && j < tLen) 
	{
		if (i == -1 || T[j] == P[i]) 
		{
			i++;
			j++;
		}
		else {
			i = next[i];
		}
	}
	if (i >= pLen) 
	{
		return j-pLen+1;
	}
	else {
		return -1;
	}
}
int main() {
	string P = "abcdaabcab";
	string T = "abcddabcababcdaabcababcdaabcaba";
	for (int i=0; i<P.length();i++) 
	{
		cout <<findNext(P)[i] << " ";
	}
	cout << endl;
	cout << KMP(T, P, findNext(P));
}
