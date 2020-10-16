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
		//依照二叉搜索树的规则插入

		//空树的插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		//非空树插入
		Node* cur = _root;
		Node* parent = nullptr;//记录父节点
		//寻找插入的位置
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

		//更新平衡因子
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
				// 说明parent子树已经不平衡，需要旋转处理，让他平衡
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
