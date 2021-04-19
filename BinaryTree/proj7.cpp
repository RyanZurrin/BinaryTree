#include <fstream>
#include "binaryTree.h"
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <ctime>

struct listHolder
{
	/// <summary>
	/// The main Tree list
	/// </summary>
	Bll* mainTree;
	/// <summary>
	/// //holds each repeated error value in the order that it happened, is
	/// useful to keep track of the total number of errors as well.
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
};

void printRandomNumbersToFile(
	int, int, int, const std::string&);
void printErrorLogAndDeleteErrorKeys(listHolder* );
void printMergedTree(listHolder*);
void dataLoader(listHolder*, std::string);
static void printVector(std::vector<double>&);
void printSet(std::set<double>);

/// <summary>
/// The Main method.
/// </summary>
/// <returns>int 0 if all runs well: else some other value</returns>
int main()
{
	listHolder* lh = new listHolder;
	dataLoader(lh, "data1.txt");
	dataLoader(lh, "data2.txt");
	printErrorLogAndDeleteErrorKeys(lh);
	printMergedTree(lh);

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
void printErrorLogAndDeleteErrorKeys(listHolder* lh)
{
	std::ofstream output;
	output.open("errors.txt");
	int pos = 1;
	time_t* timeReport = new time_t;
	struct tm* t_info;
	time(timeReport);
	t_info = localtime(timeReport);
	output << "Error log generated on: " << asctime(t_info) <<"\n"
		   << "Total errors counted: "<< lh->errList.size() << "\n"
		   << "Unique errors logged: "<< lh->errorSet.size() << std::endl;
	std::set<double>::iterator it;
	for(it=lh->errorSet.begin(); it != lh->errorSet.end();it++)
	{
		output<< std::setw(6)<< std::left <<*it<<(pos%10==0?'\n':' ');
		lh->mainTree->deleteItem(*it);
		pos++;
	}
	output.close();
}//end function printErrorLogAndDeleteErrorKeys

/// <summary>
/// Prints the merged tree.
/// </summary>
void printMergedTree(listHolder* lh)
{
	std::ofstream output;
	output.open("merged.txt");
	std::cout << "merged list printed to file: "<< std::endl;
	lh->mainTree->display(output);
	output.close();
}//end function printMergedTree

/// <summary>
/// loads the data from the specified filename into the Bll bt(binaryTree).
/// </summary>
/// <param name="bt">The binary tree to load.</param>
/// <param name="fileName">Name of the file to load from.</param>
void dataLoader(listHolder* lh, std::string fileName)
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
		goodData = lh->mainTree->addItem(toList);
		if (goodData == false)
		{
			lh->errList.push_back(toList);
			lh->errorSet.insert(toList);
		}
	}

	std::cout << "data has been successfully loaded." << std::endl;
	inFile.close();
}//end function listLoader


/// <summary>
/// Prints the vector.
/// </summary>
/// <param name="v">The v.</param>
void printVector(std::vector<double>& v)
{
	const int size = v.size();
	std::cout << "vector: ";
	for (int i = 0; i < size; i++)
	{

		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}//end function printVectorValues

/// <summary>
/// Prints the set.
/// </summary>
/// <param name="s">The s.</param>
void printSet(std::set<double> s)
{
	std::set<double>::iterator it;
	for(it=s.begin(); it != s.end();it++)
		std::cout<<*it<<" ";
	std::cout<< std::endl;
	std::cout << "set size: "<< s.size()<< std::endl;
}//end function printSet
