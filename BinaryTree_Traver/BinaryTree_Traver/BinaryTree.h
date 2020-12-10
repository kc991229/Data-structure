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
		stack<Node*> st;//����һ��ջ
		Node* cur = root;//����һ����ʱ����
		
		while (!st.empty()||cur)//��ջ��Ϊ�ջ�cur��Ϊnullptr
		{
			while (cur)//ִ�ж������Ĵ�ӡ
		{
			cout << root->_date << "  ";
			st.push(cur);//��ӡ��ɺ���ջ
			cur = cur->_left;//�����ӡ����
		}
			cur = st.top();//�ó���ӡ���Ľڵ���Ϊ�µĸ�
			cur = cur->_right;//��������������ͬ����
			st.pop();//��ջ
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