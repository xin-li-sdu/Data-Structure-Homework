#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
struct Node {//节点 
	int data;
	Node* left;
	Node* right;
};
struct Tree {//树 
	Node* root;
};
//先序遍历
void preorder(Node* node)
{
	if (node != NULL)
	 {
		cout << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}
}
//插入节点
void insert_node(Tree* tree, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;

	if (tree->root == NULL) {
		tree->root = node;
	}
	else {
		Node* tmp = tree->root;
		while (tmp != NULL) {
			if (value < tmp->data) {
				if (tmp->left == NULL) {
					tmp->left = node;
					return;
				}
				else {
					tmp = tmp->left;
				}
			}
			else {
				if (tmp->right == NULL) {
					tmp->right = node;
					return;
				}
				else {
					tmp = tmp->right;
				}
			}
		}
	}
}
int main()
{
	Tree tree;
	tree.root = NULL;
	int num;
	while (cin.peek() != '\n')
	{
		cin >> num;
		insert_node(&tree, num);
	}
	preorder(tree.root);
	return 0;
}
