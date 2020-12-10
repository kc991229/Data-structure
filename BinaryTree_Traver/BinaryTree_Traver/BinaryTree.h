#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <class T>
struct BinaryNode
{
	struct BinaryNode* _left;
	struct BinaryNode* _right;
	struct BinaryNode* _parent;
	T _date;
};
template <class T>
class Binary
{
public:
	typedef  BinaryNode Node;
	void BinaryTree_OrderTraver(Node* root = _root)
	{
		stack<Node*> st;//定义一个栈
		Node* cur = root;//定义一个临时变量
		
		while (!st.empty()||cur)//当栈不为空或cur不为nullptr
		{
			while (cur)//执行对左树的打印
		{
			cout << root->_date << "  ";
			st.push(cur);//打印完成后入栈
			cur = cur->_left;//先序打印左树
		}
			cur = st.top();//拿出打印过的节点作为新的根
			cur = cur->_right;//对其右树进行相同操作
			st.pop();//出栈
		}
	}
	void BinaryTree_middleTraver(Node* root=_root)
	{
		stack<Node*> st;
		Node* cur = root;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->_left;
			}
			cur = st.top();
			cout << cur->_date << "  ";
			cur = cur->_right;
		}
	}
	void BinaryTree_LastTraver(Node* root=_root)
	{
		stack<Node*> st;
		Node* cur = root;
		Node* prev = nullptr;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->_left;
			}
			cur = st.top();
			if (cur->_right == nullptr || cur->_right == prev)
			{
				cout << cur->_date << "  ";
				prev = cur;
				st.pop();
			}
			else
			{
				cur = cur->_right;
			}
		}
	}
	void BinaryTree_OrderTraver_recursion(Node* root=_root)
	{
		Node* cur = root;
		while (cur != nullptr)
		{
			cout << cur->_date << "  ";
			BinaryTree_OrderTraver_recursion(cur->_left);
			BinaryTree_OrderTraver_recursion(cur->_right);
		}
	}
	void BinaryTree_middleTraver_recursion(Node* root=_root)
	{
		Node* cur = root;
		while (cur != nullptr)
		{
			BinaryTree_OrderTraver_recursion(cur->_left);
			cout << cur->_date << "  ";
			BinaryTree_OrderTraver_recursion(cur->_right);
		}
	}
	void BinaryTree_LastTraver_recursion(Node* root=_root)
	{
		Node* cur = root;
		while (cur != nullptr)
		{
			BinaryTree_OrderTraver_recursion(cur->_left);
			BinaryTree_OrderTraver_recursion(cur->_right);
			cout << cur->_date << "  ";
		}
	}
private:
	Node* _root;
};