#include <fstream>
#include "binaryTree.h"
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <ctime>

void printRandomNumbersToFile(
	int min, int max, int amount, const std::string& filename);
void printErrorLogAndDeleteErrorKeys(std::set<double> s);
void printMergedTree();
void dataLoader(Bll* bt, std::string);
static void printVector(std::vector<double> v);
void printSet(std::set<double> s);

static struct listHolder
{
	/// <summary>
	/// The main Tree list
	/// </summary>
	Bll* mainTree;


	/// <summary>
	/// //holds each repeated error value in the order that it happened
	/// </summary>
	std::vector<double> errList;


	/// <summary>
	/// Set of each error with no duplicates of the errors
	/// </summary>
	std::set<double> errorSet;

	/// <summary>
	/// Initializes a new instance of the <see cref="listHolder"/> struct.
	/// </summary>
	listHolder()
	{
		mainTree = new Bll;
	}
	/// <summary>
	/// Finalizes an instance of the <see cref="listHolder"/> class.
	/// </summary>
	~listHolder()
	{
		delete mainTree;
	}
}lh;

/// <summary>
/// The Main method.
/// </summary>
/// <returns>int 0 if all runs well: else some other value</returns>
int main()
{
	std::ofstream mergePrinter;
	printRandomNumbersToFile(1, 500, 100, "data2.txt");
	dataLoader(lh.mainTree, "data1.txt");
	//lh.mainTree->traverseTree(Bll::IN_ORDER);
	//std::cout << "qty round 1: " << lh.mainTree->getQty() << std::endl;
	//std::cout << "vector error list 1: " << std::endl;
	//printVector(lh.errList);
	//std::cout << "vector error count 1: " << lh.errList.size() << std::endl;
	//std::cout << "set error list 1: " << std::endl;
	//printSet(lh.errorSet);
	dataLoader(lh.mainTree, "data2.txt");
	//lh.mainTree->traverseTree(Bll::IN_ORDER);
	//std::cout << "qty round 2: " << lh.mainTree->getQty() << std::endl;
	//std::cout << "vector error list 2: " << std::endl;
	//printVector(lh.errList);
	//std::cout << "vector error count 2: " << lh.errList.size() << std::endl;
	std::cout << "set error list: " << std::endl;
	printSet(lh.errorSet);
	printErrorLogAndDeleteErrorKeys(lh.errorSet);
	printMergedTree();
	std::cout << "\nqty of merged tree: " << lh.mainTree->getQty() << std::endl;

	return 0;
}

/// <summary>
/// Prints random numbers to file.
/// </summary>
/// <param name="min">the lower bound of the random numbers</param>
/// <param name="max">the upper bound of the random numbers</param>
/// <param name="amount">The total amount of random numbers to generate.</param>
/// <param name="filename">The filename to store them in.</param>
void printRandomNumbersToFile(
	int min, int max, int amount,  const std::string& filename)
{
	srand(static_cast<unsigned int>(time(NULL)));
	std::ofstream file;
	file.open(filename.c_str());
	int data;
	int count = 1;
	for (int index = 0; index < amount; index++)
	{
		data =  min + rand() % (( max + 1 ) - min);
		file << data << (count % 10 == 0 ? '\n' : ' ');
		count++;
	}
	file.close();
}//end function printRandomNumbersToFile

/// <summary>
/// Prints the error log and deletes the  error keys from tree list
/// </summary>
/// <param name="s">The set that holds the error values.</param>
void printErrorLogAndDeleteErrorKeys(std::set<double> s)
{
	std::ofstream output;
	output.open("errors.txt");
	time_t* timeReport = new time_t;
	struct tm* t_info;
	time(timeReport);
	t_info = localtime(timeReport);
	output << "Error log generated on: " << asctime(t_info) << std::endl;
		std::set<double>::iterator it;
	for(it=s.begin(); it != s.end();it++)
	{
		output<<*it<<"\n";
		lh.mainTree->deleteItem(*it);
	}
	output.close();
}//end function printErrorLogAndDeleteErrorKeys

/// <summary>
/// Prints the merged tree.
/// </summary>
void printMergedTree()
{
	std::ofstream output;
	output.open("merged.txt");
	std::cout << "merged list printed to file: "<< std::endl;
	lh.mainTree->display(output);
	output.close();
}//end function printMergedTree

/// <summary>
/// loads the data from the specified filename into the Bll bt(binaryTree).
/// </summary>
/// <param name="bt">The binary tree to load.</param>
/// <param name="fileName">Name of the file to load from.</param>
void dataLoader(Bll* bt, std::string fileName)
{
	std::ifstream inFile;
	double toList;
	bool fileNotFoundError = false;
	bool goodData = true;

	do
	{
		if (fileNotFoundError)
		{
			std::cout << "enter the name of the file to load from: "
				 <<"then press return.\n>>";
			std::cin >> fileName;
			if (fileName == "exit")
			{
				std::cout << "Good bye";
				exit(0);
			}
		}

		inFile.open(fileName.c_str());
		if (!inFile)
		{
			std::cout << "file not found, type 'exit' to end program, or"
			<< std::endl;
			fileNotFoundError = true;
		}
	} while (!inFile);

	while (!inFile.eof())
	{
		inFile >> toList;
		goodData = bt->addItem(toList);
		if (goodData == false)
		{
			lh.errList.push_back(toList);
			lh.errorSet.insert(toList);
		}
	}

	std::cout << "data has been successfully loaded." << std::endl;
	inFile.close();
}//end function listLoader


void printVector(std::vector<double> v)
{
	const int size = v.size();
	std::cout << "vector: ";
	for (int i = 0; i < size; i++)
	{

		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}//end function printVectorValues

void printSet(std::set<double> s)
{
	std::set<double>::iterator it;
	for(it=s.begin(); it != s.end();it++)
		std::cout<<*it<<" ";
	std::cout<< std::endl;
	std::cout << "set size: "<< s.size()<< std::endl;
}//end function printSet
