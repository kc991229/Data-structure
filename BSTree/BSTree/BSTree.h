#pragma once;

#include <iostream>
using namespace std;
template <class T>
struct BSTreeNode
{
	BSTreeNode<T>* _left;
	BSTreeNode<T>* _right;
	T _key;

	BSTreeNode(const T& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template <class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	~BSTree()
	{}
	bool Insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* father = nullptr;
		while (cur)
		{
			if (cur->_key < key)//����Ѱ��
			{
				father = cur;
				cur = cur->_left;
			}
			else if (cur->_key>key)//����Ѱ��
			{
				father = cur;
				cur = cur->_right;
			}
			else//�Ѿ��иýڵ㣬����ʧ��
				return false;
		}
		Node* newnode = new Node(key);
		if (father->_key < key)
		{
			father->_right = newnode;
		}
		else
		{
			father->_left = newnode;
		}
		return true;
	}
	Node* Find(const T& key)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
				return cur;
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				cur = cur->_left;
			}
		}
		return nullptr;
	}

	bool Erase(const T& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 1.��Ϊ��
				// 2.��Ϊ��
				// 3.���Ҷ���Ϊ��
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}

					delete cur;
				}
				else
				{
					// �滻��ɾ��  ���������ڵ�(���ҽڵ�) ��������������С�ڵ�(����ڵ�)
					Node* minNodeParent = cur;  // ����Ҫע�ⲻ�ܳ�ʼ������
					Node* minNode = cur->_right;
					while (minNode->_left)
					{
						minNodeParent = minNode;
						minNode = minNode->_left;
					}

					swap(cur->_key, minNode->_key);
					// ת����ɾ��minNode

					// ��ΪminNode����Ϊ�յĽڵ㣬����ֱ��ɾ��
					if (minNodeParent->_right == minNode)
						minNodeParent->_right = minNode->_right;
					else
						minNodeParent->_left = minNode->_right;

					delete minNode;
				}

				return true;
			}
		}

		return false;
	}
private:
	Node* _root = nullptr;
};