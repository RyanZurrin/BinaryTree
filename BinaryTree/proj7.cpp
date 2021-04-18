#include <fstream>
#include "binaryTree.h"
#include <string>
#include <random>
#include <iostream>
#include <stdlib.h>
#include <time.h>
void printRandomNumbersToFile(
	int min, int max, int amount, const std::string& filename);
void readFileIntoTree(Bll* tree);
bool isDuplicate(Bll* tree, std::ifstream infile);
void printErrorLog();
void printMergedTree();

int main()
{


	return 0;
}
/// <summary>
/// Prints random numbers to file.
/// </summary>
/// <param name="amount">The amount.</param>
/// <param name="filename">The filename.</param>
void printRandomNumbersToFile(
	int min, int max, int amount,  const std::string& filename)
{
	std::srand(static_cast<unsigned int>(time(nullptr)));
	std::ofstream file;
	file.open(filename.c_str());
	int data;
	for (int index = 0; index < amount; index++)
	{
		data =  min + rand() % (( max + 1 ) - min);
		file << data << '\n';
	}
	file.close();
}

void readFileIntoTree(Bll* tree)
{

}

bool isDuplicate(Bll* tree, std::ifstream infile)
{
	return false;
}

void printErrorLog()
{

}

void printMergedTree()
{

}








/*
 * 	printRandomNumbersToFile(1, 500, 100, "data1.txt");
	int found;
	Bll myTree;
	std::ofstream ofs;
	std::cout<<"isEmpty: " << myTree.isEmpty()<<std::endl;
	myTree.addItem(15);
	myTree.addItem(7);
	myTree.addItem(22);
	myTree.addItem(45);
	std::cout<<"isEmpty: " << myTree.isEmpty()<<std::endl;
	myTree.traverseTree(Bll::IN_ORDER);
	myTree.addItem(2);
	myTree.addItem(12);
	myTree.addItem(37);
	myTree.addItem(1);
	myTree.addItem(25);
	myTree.addItem(122);
	myTree.addItem(39);
	myTree.addItem(1);
	myTree.addItem(20);
	myTree.addItem(11);
	myTree.addItem(337);
	myTree.addItem(5);
	myTree.addItem(215);
	myTree.addItem(102);
	myTree.addItem(89);
	myTree.addItem(19);
	myTree.traverseTree(Bll::IN_ORDER);
	myTree.traverseTree(Bll::REVERSE_ORDER);
	myTree.addItem(2);
	myTree.traverseTree(Bll::BREADTH_FIRST);
	std::cout << "find 12? : "<< myTree.findItem(12, found)<< std::endl;
	std::cout << "value in found: "<< found<<std::endl;
	std::cout << "count: "<< myTree.getCount() << std::endl;
	std::cout << "qty: " << myTree.getQty() << std::endl;
	myTree.traverseTree(Bll::IN_ORDER);
	myTree.deleteItem(15);
		std::cout << "find 15? : "<< myTree.findItem(15, found)<< std::endl;
	std::cout << "value in found: "<< found<<std::endl;
	std::cout << "qty: " << myTree.getQty() << std::endl;
	myTree.traverseTree(Bll::PRE_ORDER);
	myTree.traverseTree(Bll::POST_ORDER);
	myTree.traverseTree(Bll::IN_ORDER);
	myTree.traverseTree(Bll::POST_ORDER);
	Bll copied(myTree);
	copied.traverseTree(Bll::IN_ORDER);
	copied.traverseTree(Bll::BREADTH_FIRST);
	std::cout << "\ncopied tree traversal"<<std::endl;
	copied.traverseTree(Bll::IN_ORDER);
	copied.deleteItem(37);
	copied.deleteItem(22);
	copied.deleteItem(15);
	copied.traverseTree(Bll::BREADTH_FIRST);
	copied.traverseTree(Bll::REVERSE_ORDER);
	Bll operatorTest;
	operatorTest = copied;
	std::cout << "operator copied test print: "<< std::endl;
	operatorTest.traverseTree(Bll::IN_ORDER);
	operatorTest.traverseTree(Bll::BREADTH_FIRST);
	std::cout << "count: " << copied.getCount()<< std::endl;
	copied.traverseTree(Bll::POST_ORDER);
	myTree.makeEmpty();
	std::cout << "qty after make empty: " << myTree.getQty() << std::endl;
	for (size_t i = 0; i < 10000; i++){}
	printRandomNumbersToFile(1, 500, 100, "data2.txt");
	return 0;
 */