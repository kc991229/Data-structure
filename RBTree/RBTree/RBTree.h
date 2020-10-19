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
	RBTreeNode<K, V>* _parent;//该节点的父亲节点
	RBTreeNode<K, V>* _left;//该节点的左孩子
	RBTreeNode<K, V>* _right;//该节点的右孩子
	std::pair<K,V> _data;//该节点的数据
	Colour _col;//节点的颜色

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
		//按照二叉搜索树的规则插入
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
		cur->_col = Red;//默认新插入节点为红

		//检查颜色是否满足要求
		while (parent && parent->_col == Red)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)//表明在左树进行插入
			{
				Node* uncle = grandfather->_right;
				//情况1：uncle存在且为红
				if (uncle && uncle->_col == Red)
				{
					//父亲叔叔变黑，爷爷变红
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;
					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				//情况2：uncle不存在或uncle存在为黑
				else
				{
					//情况3：为左子树的右边，需要转换为情况2
					if (cur == parent->_right)
					{
						RotateL(parent);
					}
					//处理情况2
					RotateR(grandfather);
					grandfather->_col = Red;
					parent->_col = Black;

					break;
				}
			}
			//右树插入
			else
			{
				Node* uncle = grandfther->_left;
				// 情况1：uncle存在，且为红
				// 情况2 or 情况3：uncle不存在 or uncle存在，且为黑
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
			//根恒为黑色
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

		// 1、原来parent是这颗树的跟，现在subR是根
		// 2、parent为根的树只是整颗树中的子树，改变链接关系，那么subR要顶替他的位置
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