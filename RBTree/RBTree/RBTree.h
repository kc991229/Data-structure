# pragma once

#include <iostream>

enum Colour
{
	Red,
	Black,
};
template <class K,class V>
class RBTreeNode
{
	RBTreeNode<K, V>* _parent;//�ýڵ�ĸ��׽ڵ�
	RBTreeNode<K, V>* _left;//�ýڵ������
	RBTreeNode<K, V>* _right;//�ýڵ���Һ���
	std::pair<K,V> _data;//�ýڵ������
	Colour _col;//�ڵ����ɫ

	RBTreeNode(const std::pair<K, V> data)
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _col(Red)
		, _data(data)
	{}
};

template <class K,class V>
class RBTree
{
	typedef RBTreeNode Node;
public:
	bool Insert(std::pair<K, V>& kv)
	{
		newnode = new Node(kv);
		if (_root == nullptr)
		{
			_root = newnode;
			_root->_col = Black;
			return true;
		}
		//���ն����������Ĺ������
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first > cur->_data.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_data.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		cur = newnode;
		if (cur->_data.first>parent->_data.first)
		{
			cur->_parent = parent;
			parent->_right = cur;
		}
		else
		{
			cur->_parent = parent;
			parent->_left = cur;
		}
		cur->_col = Red;//Ĭ���²���ڵ�Ϊ��

		//�����ɫ�Ƿ�����Ҫ��
		while (parent && parent->_col == Red)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)//�������������в���
			{
				Node* uncle = grandfather->_right;
				//���1��uncle������Ϊ��
				if (uncle && uncle->_col == Red)
				{
					//���������ڣ�үү���
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;
					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				//���2��uncle�����ڻ�uncle����Ϊ��
				else
				{
					//���3��Ϊ���������ұߣ���Ҫת��Ϊ���2
					if (cur == parent->_right)
					{
						RotateL(parent);
					}
					//�������2
					RotateR(grandfather);
					grandfather->_col = Red;
					parent->_col = Black;

					break;
				}
			}
			//��������
			else
			{
				Node* uncle = grandfther->_left;
				// ���1��uncle���ڣ���Ϊ��
				// ���2 or ���3��uncle������ or uncle���ڣ���Ϊ��
				if (uncle && uncle->_col == Red)
				{
					parent->_col = uncle->_col = Black;
					grandfther->_col = Red;

					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
					}

					RotateL(grandfther);
					grandfther->_col = Red;
					parent->_col = Black;
				}
			}
			//����Ϊ��ɫ
			_root->_col = Black;
			return true;
		}

	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		// 1��ԭ��parent��������ĸ�������subR�Ǹ�
		// 2��parentΪ������ֻ���������е��������ı����ӹ�ϵ����ôsubRҪ��������λ��
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}
	}
private:
	Node* _root = nullptr;
};