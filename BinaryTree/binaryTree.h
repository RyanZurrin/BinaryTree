#pragma once


#include <iomanip>
#include <iostream>
#include <queue>
#define COUNT 10
static int pos = 1;

struct b_node
{	b_node* left;
	double num;
	b_node* right;
};

/// <summary>
/// binary search tree data structure
/// </summary>
class Bll
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Bll"/> class.
	/// </summary>
	Bll();

	/// <summary>
	/// Initializes a new instance of the <see cref="Bll"/> class.
	/// </summary>
	/// <param name="maxSize">The maximum size.</param>
	Bll(int maxSize);


	/// <summary>
	/// Copy Constructor initializes a new instance of the
	/// <see cref="Bll"/> class.
	/// </summary>
	/// <param name="originalTree">The original tree.</param>
	Bll(const Bll& originalTree);


	/// <summary>
	/// Move operator= copies from the specified original tree.
	/// </summary>
	/// <param name="originalTree">The original tree.</param>
	void operator=(Bll& originalTree);

	/// <summary>
	/// Allows the user to pass one of these into traverseTree method and get
	/// a tree printed out in the order they wish
	/// </summary>
	enum  OrderType {
		PRE_ORDER,
		IN_ORDER,
		POST_ORDER,
		BREADTH_FIRST,
		REVERSE_ORDER,
		TWO_DIMENSIONS
	};
	/// <summary>
	/// Adds item to the tree
	/// </summary>
	/// <param name="k">The key value.</param>
	/// <returns>true if added: else false</returns>
	bool addItem(double k);


	/// <summary>
	/// Deletes the item.
	/// </summary>
	/// <param name="k">The k.</param>
	/// <returns></returns>
	bool deleteItem(double k);
	/// <summary>
	/// Determines whether this instance is empty.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
	/// </returns>
	bool isEmpty()const;
	/// <summary>
	/// Determines whether this instance is full.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is full; otherwise, <c>false</c>.
	/// </returns>
	bool isFull()const;
	/// <summary>
	/// Makes the tree empty.
	/// </summary>
	/// <returns></returns>
	bool makeEmpty();
	/// <summary>
	/// Traverses the tree.
	/// </summary>
	/// <param name="order">The order to traverse the tree.</param>
	void traverseTree(OrderType order)const;
	/// <summary>
	/// Gets the qty.
	/// </summary>
	/// <returns>the number of elements in the tree</returns>
	int getQty()const;
	/// <summary>
	/// Gets the count.
	/// </summary>
	/// <returns>counts the nodes and returns the count</returns>
	int getCount()const;
	/// <summary>
	/// Finds the item.
	/// </summary>
	/// <param name="k">The key to look for.</param>
	/// <param name="found">The found.</param>
	/// <returns></returns>
	bool findItem(double k, double& found)const;
	/// <summary>
	/// outputs the tree
	/// </summary>
	/// <param name="os">The output stream if being printed out to file.</param>
	/// <returns>true if prints: else false</returns>
	bool display(std::ofstream& os)const;
	/// <summary>
	/// Finalizes an instance of the <see cref="Bll"/> class.
	/// </summary>
	~Bll();

private:
	b_node* tt;
	int qty;
	int max;
	/// <summary>
	/// private auxiliary method to help with adding to the tree.
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <param name="k">The key.</param>
	/// <returns>true if added: else false</returns>
	bool pAdd(b_node* tree, double& k);
	/// <summary>
	/// private auxiliary method to help with deleting element from tree
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <param name="k">The key.</param>
	/// <returns>true if deleted: else false</returns>
	bool pDelete(b_node*& tree, double& k);
	/// <summary>
	/// private auxiliary function called when a node is found to
	/// be deleted from the tree.
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <returns></returns>
	bool deleteNode(b_node*& tree);
	/// <summary>
	/// Gets the predecessor node when deleting nodes what need to be relinked
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <param name="k">The k.</param>
	static void getPredecessor(b_node* tree, double& k);
	/// <summary>
	/// Counts the nodes.
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <returns></returns>
	static int countNodes(b_node* tree);
	/// <summary>
	/// Retrieves the specified tree.
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <param name="k">The k.</param>
	/// <param name="found">The found.</param>
	/// <returns></returns>
	bool retrieve(b_node* tree, const double k, double& found)const;
	/// <summary>
	/// Copies the tree.
	/// </summary>
	/// <param name="copy">The copy.</param>
	/// <param name="originalTree">The original tree.</param>
	static void copyTree(b_node*& copy, const b_node* originalTree);
	/// <summary>
	/// Destroys the specified tree.
	/// </summary>
	/// <param name="tree">The tree.</param>
	void destroy(b_node*& tree);
	/// <summary>
	/// Prints the tree.
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <param name="os">The os.</param>
	static void printTree(b_node* tree, std::ofstream& os);
	/// <summary>
	/// auxiliary pre-order traversal helper
	/// </summary>
	/// <param name="tree">The tree.</param>
	static void preOrderHelper(b_node* tree);
	/// <summary>
	/// auxiliary in-order traversal helper
	/// </summary>
	/// <param name="tree">The tree.</param>
	static void inOrderHelper(b_node* tree);
	/// <summary>
	/// auxiliary post-order traversal helper
	/// </summary>
	/// <param name="tree">The tree.</param>
	static void postOrderHelper(b_node* tree);
	/// <summary>
	/// auxiliary breadth-first-order traversal helper
	/// </summary>
	/// <param name="tree">The tree.</param>
	static void breadthFirstHelper(b_node* tree);
	/// <summary>
	/// auxiliary reverse-order traversal helper
	/// </summary>
	/// <param name="tree">The tree.</param>
	static void reverseOrderHelper(b_node* tree);
	/// <summary>
	/// auxiliary 2D-order traversal helper
	/// </summary>
	/// <param name="tree">The tree.</param>
	/// <param name="space">The space between nodes.</param>
	static void twoDimensionalHelper(b_node* tree, int space);

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



inline bool Bll::addItem(double k)//working
{
	if (isFull())
		return false;
	if (tt == NULL)
	{
		tt = new b_node;
		tt->left = NULL;
		tt->right = NULL;
		tt->num = k;
		qty++;
		return true;
	}

	return pAdd(tt, k);
}//end method addItem

inline bool Bll::deleteItem(double k)//working
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
		case TWO_DIMENSIONS: std::cout << "\nTwo-Dimensional-Order tree traversal:\n";
						twoDimensionalHelper(tt, 0);
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


inline bool Bll::findItem(double k, double& found)const
{

	return retrieve(tt, k, found);
}
inline bool Bll::display(std::ofstream& os)const
{

	printTree(tt, os);
	return true;
}
//end method findItem

inline Bll::~Bll()
{
	destroy(tt);
}//end ~destructor


inline bool Bll::pAdd(b_node* tree, double& k)//working
{
	if (tree->num == k || qty >= max)
	{
		std::cout << "duplicate, cannot add element "<< k << std::endl;
		return false; // duplicate item, or max size reached
	}

	if (k < tree->num)//walk left
	{
		if (tree->left == NULL)//add element here
		{
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
			tree->right = new b_node;
			tree->right->left = tree->right->right = NULL;
			tree->right->num = k;
			qty++;
			return true;
		}
		else
			pAdd(tree->right, k);
	}
	//return false;


}//end auxiliary method pAdd

inline bool Bll::pDelete(b_node*& tree, double& k)//working
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
	double _k = 0;
	b_node* tempPtr;

	tempPtr = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
		qty--;
		return true;
	}
	else if (tree->right == NULL)
	{
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

inline void Bll::getPredecessor(b_node* tree, double& k)//working
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

inline bool Bll::retrieve(b_node* tree,const double k, double& found)const//working
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
}
inline void Bll::printTree(b_node* tree, std::ofstream& os)
{

	if (tree != NULL)
	{
		printTree(tree->left, os);
		os << std::setw(7)<< std::left << tree->num
						  << (pos % 10 == 0 ? '\n': ' ');
		std::cout << tree->num << " ";
		pos++;
		printTree(tree->right, os);

	}
}
//end auxiliary method destroy

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

inline void Bll::twoDimensionalHelper(b_node* tree, int space)
{
	if (tree == NULL)
		return;
	space += COUNT;
	twoDimensionalHelper(tree->right, space);
	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << tree->num << "\n";
	twoDimensionalHelper(tree->left, space);

}
