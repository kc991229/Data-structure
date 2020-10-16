#pragma once;

#include <iostream>


template <class K,class V>
struct AVLTreeNode
{
	std::pair<K, V> _kv;
	int _bf;// balance factor
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template <class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(std::pair<K, V>& kv)
	{
		//���ն����������Ĺ������

		//�����Ĳ���
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		//�ǿ�������
		Node* cur = _root;
		Node* parent = nullptr;//��¼���ڵ�
		//Ѱ�Ҳ����λ��
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			cur->_parent = parent;
			parent->_left = cur;
		}
		else
		{
			cur->_parent = parent;
			parent->_right = cur;
		}

		//����ƽ������
		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else if (parent->_right == cur)
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (std::abs(parent->_bf) == 1)
			{
				cur = parent;
				parent->_parent;
			}
			else if (std::abs(parent->_bf) == 2)
			{
				// ˵��parent�����Ѿ���ƽ�⣬��Ҫ��ת��������ƽ��
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}

				break;
			}
			else
			{
				return false;
			}
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

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}

		subR->_bf = parent->_bf = 0;
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

		if (parent == _root)
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

		parent->_bf = subL->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}
private:
	Node* _root = nullptr;
};
