#pragma once


#include <iostream>
#include <queue>


struct b_node
{	b_node* left;
	double num;
	b_node* right;
};

class Bll
{
public:
	Bll();
	Bll(int maxSize);
	Bll(const Bll& originalTree);
	void operator=(Bll& originalTree);
	enum  OrderType {
		PRE_ORDER,
		IN_ORDER,
		POST_ORDER,
		BREADTH_FIRST,
		REVERSE_ORDER
	};
	bool addItem(int k);
	bool deleteItem(int k);
	bool isEmpty()const;
	bool isFull()const;
	bool makeEmpty();
	void traverseTree(OrderType order)const;
	int getQty()const;
	int getCount()const;
	bool findItem(int k, int& found)const;
	~Bll();

private:
	b_node* tt;
	int qty;
	int max;
	bool pAdd(b_node* tree, int& k);
	bool pDelete(b_node*& tree, int& k);
	bool deleteNode(b_node*& tree);
	static void getPredecessor(b_node* tree, int& k);
	static int countNodes(b_node* tree);
	bool retrieve(b_node* tree,const int k, int& found)const;
	static void copyTree(b_node*& copy, const b_node* originalTree);
	void destroy(b_node*& tree);
	static void preOrderHelper(b_node* tree);
	static void inOrderHelper(b_node* tree);
	static void postOrderHelper(b_node* tree);
	static void breadthFirstHelper(b_node* tree);
	static void reverseOrderHelper(b_node* tree);

};//end class Bll interface



inline Bll::Bll()//working
{
	qty = 0;
	max = INT_MAX;
	tt = NULL;
}//end no argument constructor

inline Bll::Bll(int maxSize)//working
{
	qty = 0;
	max = maxSize;
	tt = NULL;
}//end overloaded constructor

inline Bll::Bll(const Bll& originalTree)
{
	max = originalTree.max;
	qty = originalTree.qty;
	copyTree(tt, originalTree.tt);
}//end copy constructor

inline void Bll::operator=(Bll& originalTree)
{
	if (&originalTree == this)
		return;
	destroy(tt);
	copyTree(tt, originalTree.tt);
	max = originalTree.max;
	qty = originalTree.qty;
}// end overloaded operator=



inline bool Bll::addItem(int k)//working
{
	if (isFull())
		return false;
	if (tt == NULL)
	{
		std::cout << "adding root node key: "<< k << std::endl;
		tt = new b_node;
		tt->left = NULL;
		tt->right = NULL;
		tt->num = k;
		qty++;
		return true;
	}

	return pAdd(tt, k);
}//end method addItem

inline bool Bll::deleteItem(int k)//working
{
	return pDelete(tt, k);

}//end method deleteItem

inline bool Bll::isEmpty()const
{
	return tt == NULL;
}//end method isEmpty

inline bool Bll::isFull()const
{
	return qty >= max;
}//end method isFull

inline bool Bll::makeEmpty()//working
{

	if (isEmpty())
		return false;
	else
	{
		destroy(tt);
		tt = NULL;
		return true;
	}

}//end method MakeEmpty

inline void Bll::traverseTree(OrderType order)const
{
	switch (order)
	{
		case PRE_ORDER:		std::cout << "\nPre-Order tree traversal:\n";
						preOrderHelper(tt);
						break;
		case IN_ORDER:		std::cout << "\nIn-Order tree traversal:\n";
						inOrderHelper(tt);
						break;
		case POST_ORDER:	std::cout << "\nPost-Order tree traversal:\n";
						postOrderHelper(tt);
						break;
		case BREADTH_FIRST: std::cout<< "Breadth-first traversal:\n";
						breadthFirstHelper(tt);
						break;
		case REVERSE_ORDER: std::cout << "\nReverse-Order tree traversal:\n";
						reverseOrderHelper(tt);
						break;
	}

	std::cout << std::endl;
}//end method traverseTree



inline int Bll::getQty()const
{
	return qty;
}//end method getQty

inline int Bll::getCount()const
{
	return countNodes(tt);
}//end method getCount


inline bool Bll::findItem(int k, int& found)const
{

	return retrieve(tt, k, found);
}//end method findItem

inline Bll::~Bll()
{
	destroy(tt);
}//end ~destructor


inline bool Bll::pAdd(b_node* tree, int& k)//working
{
	if (tree->num == k || qty >= max)
		return false; // duplicate item, or max size reached
	if (k < tree->num)//walk left
	{
		if (tree->left == NULL)//add element here
		{
			std::cout << "adding node key: "<< k << std::endl;
			tree->left = new b_node;
			tree->left->left = tree->left->right = NULL;
			tree->left->num = k;
			qty++;
			return true;
		}
		else
			return pAdd(tree->left, k);
	}
	else
	{
		if (tree->right == NULL)//add element here
		{
			std::cout << "adding node key: "<< k << std::endl;
			tree->right = new b_node;
			tree->right->left = tree->right->right = NULL;
			tree->right->num = k;
			qty++;
			return true;
		}
		else
			pAdd(tree->right, k);
	}
	return false;


}//end auxiliary method pAdd

inline bool Bll::pDelete(b_node*& tree, int& k)//working
{
	if (k < tree->num)
	{
		if (tree->left == NULL)
			return false;
		return pDelete(tree->left, k);
	}
	else if (k > tree->num)
	{
		if (tree->right == NULL)
			return false;
		return pDelete(tree->right, k);
	}
	else
		return deleteNode(tree);
}//end auxiliary method pDelete

inline bool Bll::deleteNode(b_node*& tree)//working
{
	int _k = 0;
	b_node* tempPtr;

	tempPtr = tree;
	if (tree->left == NULL)
	{
		std::cout << "deleting node key: "<< tempPtr->num << std::endl;
		tree = tree->right;
		delete tempPtr;
		qty--;
		return true;
	}
	else if (tree->right == NULL)
	{
		std::cout << "deleting node key: "<< tempPtr->num << std::endl;
		tree = tree->left;
		delete tempPtr;
		qty--;
		return true;
	}
	else
	{
		getPredecessor(tree->left, _k);
		tree->num = _k;
		return pDelete(tree->left, _k);
	}

}//end auxiliary method deleteNode

inline void Bll::getPredecessor(b_node* tree, int& k)//working
{
	while (tree->right != NULL)
		tree = tree->right;
	k = tree->num;
}// end auxiliary method getPredecessor

inline int Bll::countNodes(b_node* tree)//working
{
	if (tree == NULL)
		return 0;
	else
		return countNodes(tree->left) + countNodes(tree->right) + 1;
}//end auxiliary method countNodes

inline bool Bll::retrieve(b_node* tree,const int k, int& found)const//working
{
	if (tree == NULL)
		return false;
	if (k < tree->num)
		retrieve(tt->left, k, found);
	else if (k > tree->num)
		retrieve(tree->right, k, found);
	else if (k == tree->num)
	{
		found = tree->num;
		return true;
	}
	else
		return false;

}// end auxiliary method retrieve

inline void Bll::copyTree(b_node*& copy, const b_node* originalTree)//working
{
	if (originalTree == NULL)
		copy = NULL;
	else
	{
		copy = new b_node;
		copy->num = originalTree->num;
		copyTree(copy->left, originalTree->left);
		copyTree(copy->right, originalTree->right);
	}
}//end auxiliary method copyTree


inline void Bll::destroy(b_node*& tree)
{
	if (tree != NULL)
	{
		destroy(tree->left);
		destroy(tree->right);
		qty--;
		delete tree;
	}
}//end auxiliary method destroy

inline void Bll::preOrderHelper(b_node* tree)
{

	if (tree != NULL)
	{
		std::cout << tree->num<< " ";
		preOrderHelper(tree->left);
		preOrderHelper(tree->right);
	}
}//end auxiliary method preOrder
inline void Bll::inOrderHelper(b_node* tree)//working
{
	if (tree != NULL)
	{
		inOrderHelper(tree->left);
		std::cout << tree->num << " ";
		inOrderHelper(tree->right);
	}
}//end auxiliary method inOrder

inline void Bll::postOrderHelper(b_node* tree)//working
{
	if (tree != NULL)
	{
		postOrderHelper(tree->left);
		postOrderHelper(tree->right);
		std::cout << tree->num << " ";
	}
}//end  auxiliary postOrder


inline void Bll::breadthFirstHelper(b_node* tree)
{
	if (tree == NULL)
		return;
	std::queue<b_node*> bFList;
	bFList.push(tree);
	while (bFList.empty() == false)
	{
		int nodeCount = bFList.size();
		while (nodeCount > 0)
		{
			b_node* node = bFList.front();
			std::cout << node->num << " ";
			bFList.pop();
			if (node->left != NULL)
				bFList.push(node->left);
			if (node->right != NULL)
				bFList.push(node->right);
			nodeCount--;
		}
		std::cout << std::endl;
	}
}//end auxiliary method breadthFirst

inline void Bll::reverseOrderHelper(b_node* tree)
{
	if (tree != NULL)
	{
		reverseOrderHelper(tree->right);
		std::cout << tree->num << " ";
		reverseOrderHelper(tree->left);
	}
}