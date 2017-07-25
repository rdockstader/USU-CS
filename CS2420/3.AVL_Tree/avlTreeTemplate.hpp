#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <iostream> 
#include <assert.h>
#include <sstream>
#include"DoublyLinkedList.hpp"

using namespace std;

template <typename Comparable>
class AvlTree
{
public:
	/*-*-*-*-*-*constructors*-*-*-*-*-*-*/
	AvlTree():root{ nullptr }{size = 0;	}
	AvlTree(const AvlTree & rhs) : root{ nullptr }{	size = rhs.size; root = clone(rhs.root);}
	AvlTree(AvlTree && rhs) : root{ rhs.root }{	rhs.root = nullptr;	}
	/*-*-*-*-*-*destructor(s)*-*-*-*-*-*-*/
	~AvlTree(){	makeEmpty();}

	/*-*-*-*-*-*gets & finds*-*-*-*-*-*-*/
	int getSize() { return size; }

	// Find the smallest item in the tree. Throw UnderflowException if empty
	const Comparable & findMin() const
	{
		assert(!isEmpty());
			return findMin(root)->element;
	}

	// Find the largest item in the tree
	const Comparable & findMax() const
	{
		assert(!isEmpty()) :
			return findMax(root)->element;
	}



	/*-*-*-*-*-*overload operators*-*-*-*-*-*-*/
	AvlTree & operator=(AvlTree && rhs)
	{
		std::swap(root, rhs.root);

		return *this;
	}
	//Deep copy
	AvlTree & operator=(const AvlTree & rhs)
	{
		AvlTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	// Returns true if x is found in the tree
	bool contains(const Comparable & x) const
	{
		return contains(x, root);
	}

	// text if the tree is logically empty
	bool isEmpty() const
	{
		return root == nullptr;
	}

	// String contaings the tree contents in sorted order
	string toString() const
	{
		ostringstream oss;
		oss << "BEGIN ";
		if (isEmpty())
			oss << "Empty tree" << endl;
		else
			oss << toString(root, "");
		oss << "END " << endl;
		oss << endl;
		oss << endl;
		cout << endl;
		cout << endl;
		return oss.str();
	}

	string toString2() const
	{
		ostringstream oss;
		oss << "BEGIN ";
		if (isEmpty())
			oss << "Empty tree" << endl;
		else
			oss << toString2(root);
		oss << "END " << endl;
		return oss.str();
	}

	/* Make the tree logically empty. */
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/*-*-*-*-*-*Inserts*-*-*-*-*-*/
	void insert(const Comparable & x)
	{
		size++;
		insert(x, root);
	}

	//rref
	void insert(Comparable && x)
	{
		size++;
		insert(x, root);
	}

	/*-*-*-*-*-*Removes-*-*-*-*-*-*-*/
	void remove(const Comparable & x)
	{
		size--;
		remove(x, root);
	}
	//remove the smallest element
	Comparable removeMin()
	{
		size--;
		AvlNode * min = removeMin(root);
		assert(min != NULL);
		return min->element;
	}

private:
	struct AvlNode
	{
		Comparable element;
		AvlNode   *left;
		AvlNode   *right;
		int       height;

		//initializers
		AvlNode(const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0): element{ ele }, left{ lt }, right{ rt }, height{ h } { }
		AvlNode(Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0)		: element{ std::move(ele) }, left{ lt }, right{ rt }, height{ h } { }
	};
	/*-*-*-*-*-*private vars*-*-*-*-*-*/
	AvlNode *root;
	int size;

	/*-*-*-*-*-*private insert(s)*-*-*-*-*-*/
	void insert(Comparable value, AvlNode * & curNode)
	{
		if (curNode == nullptr)
			curNode = new AvlNode{ value, nullptr, nullptr };
		else if (value < curNode->element)
			insert(value, curNode->left);
		else 
			insert(value, curNode->right);

		balance(curNode);
	}
	//rref
	void insert(Comparable && value, AvlNode * & curNode)
	{
		if (curNode == nullptr)
			curNode = new AvlNode{ std::move(value), nullptr, nullptr };
		else if (value < curNode->element)
			insert(std::move(value), curNode->left);
		else 
			insert(std::move(value), curNode->right);

		balance(curNode);
	}

	void remove(Comparable removeValue, AvlNode * & curNode)
	{
		if (curNode == nullptr)
			return;   // Item not found; do nothing

		if (removeValue < curNode->element)
			remove(removeValue, curNode->left);
		else if (curNode->element < removeValue)
			remove(removeValue, curNode->right);
		else if (curNode->left != nullptr && curNode->right != nullptr) // Two children
		{
			curNode->element = findMin(curNode->right)->element;
			remove(curNode->element, curNode->right);
		}
		else
		{
			AvlNode *oldNode = curNode;
			curNode = (curNode->left != nullptr) ? curNode->left : curNode->right;
			delete oldNode;
		}

		balance(curNode);
	}

	AvlNode*  removeMin(AvlNode * & curNode)
	{
		assert(curNode);
		
		if (curNode->left == nullptr && curNode->right == nullptr)
		{
			auto temp = curNode;
			remove(curNode->element);
			return temp;
		}
		else if (curNode->left == nullptr && curNode->right->left == nullptr && curNode->right->right == nullptr)
		{
			AvlNode* temp = curNode;
			rotateWithRightChild(curNode);
			removeMin(temp);
		}
		else if (curNode->left == nullptr && curNode->right->right == nullptr)
		{
			AvlNode* temp = curNode;
			doubleWithRightChild(curNode);
			removeMin(temp);
		}
		else if (curNode->left == nullptr && curNode->right->left == nullptr)
			return removeMin(curNode->right->right);
		toString();
		return removeMin(curNode->left);
	}
	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AvlNode * & curNode)
	{
		if (curNode == nullptr)
			return;

		if (height(curNode->left) - height(curNode->right) > ALLOWED_IMBALANCE)
			if (height(curNode->left->left) >= height(curNode->left->right))
				rotateWithLeftChild(curNode);
			else
				doubleWithLeftChild(curNode);
		else
			if (height(curNode->right) - height(curNode->left) > ALLOWED_IMBALANCE)
				if (height(curNode->right->right) >= height(curNode->right->left))
					rotateWithRightChild(curNode);
				else
					doubleWithRightChild(curNode);

		curNode->height = max(height(curNode->left), height(curNode->right)) + 1;
	}

	//private find smallest value
	AvlNode * findMin(AvlNode *curNode) const
	{
		if (curNode == nullptr)
			return nullptr;
		if (curNode->left == nullptr)
			return curNode;
		return findMin(curNode->left);
	}

	//privaet find largest value
	AvlNode * findMax(AvlNode *curNode) const
	{
		if (curNode != nullptr)
			while (curNode->right != nullptr)
				curNode = curNode->right;
		return curNode;
	}
	//private contains function
	bool contains(const Comparable & value, AvlNode *curNode) const
	{
		if (curNode == nullptr)
			return false;
		else if (value < curNode->element)
			return contains(value, curNode->left);
		else if (curNode->element < value)
			return contains(value, curNode->right);
		else
			return true;    // Match
	}
	//private empty function
	void makeEmpty(AvlNode * & curNode)
	{
		if (curNode != nullptr)
		{
			makeEmpty(curNode->left);
			makeEmpty(curNode->right);
			delete curNode;
		}
		curNode = nullptr;
	}

	//Private to string function(s)
	string toString(AvlNode *curNode, std::string indent) const
	{
		if (curNode == nullptr)
			return "";
		if(curNode != root)
			indent = indent + "	";
		
		toString(curNode->right, indent);
		cout << indent << curNode->element << endl;
		toString(curNode->left, indent);
		
		if (curNode == root)
			return toString2(root);
		return "";

	}

	string toString2(AvlNode *curNode) const
	{
		stringstream ss;
		if (curNode == nullptr)
			return "";
		ss << toString2(curNode->left);
		ss << curNode->element << " ";
		ss << toString2(curNode->right);
		return ss.str();
	
	}

	//private cloan function
	AvlNode * clone(AvlNode *curNode) const
	{
		if (curNode == nullptr)
			return nullptr;
		else
			return new AvlNode{ curNode->element, clone(curNode->left), clone(curNode->right), curNode->height };
	}
	/*-*-*-*-*Avl manipulations*-*-*-*-*-*/
	//return height of node
	int height(AvlNode *curNode) const
	{
		return curNode == nullptr ? -1 : curNode->height;
	}

	int max(int left, int right) const
	{
		return left > right ? left : right;
	}

	/*-*-*-*-*-*Rotates*-*-*-*-*-*/
	void rotateWithLeftChild(AvlNode * & parent)
	{
		AvlNode *leftChild = parent->left;
		parent->left = leftChild->right;
		leftChild->right = parent;
		parent->height = max(height(parent->left), height(parent->right)) + 1;
		leftChild->height = max(height(leftChild->left), parent->height) + 1;
		parent = leftChild;
	}

	void rotateWithRightChild(AvlNode * & parent)
	{
		AvlNode *rightChild = parent->right;
		parent->right = rightChild->left;
		rightChild->left = parent;
		parent->height = max(height(parent->left), height(parent->right)) + 1;
		rightChild->height = max(height(rightChild->right), parent->height) + 1;
		parent = rightChild;
	}

	void doubleWithLeftChild(AvlNode * & grandParent)
	{
		rotateWithRightChild(grandParent->left);
		rotateWithLeftChild(grandParent);
	}

	void doubleWithRightChild(AvlNode * & grandParent)
	{
		rotateWithLeftChild(grandParent->right);
		rotateWithRightChild(grandParent);
	}
};

#endif
