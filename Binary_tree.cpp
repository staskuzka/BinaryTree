// Binary_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TreeNode.h"
#include "SearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iostream>


int main()
{
	unsigned int start_time = clock();
	TreeNode *tree = nullptr;
	SearchTree s;
	srand(time(NULL));
	int random_variable;
	for (int i = 0; i < 50; i++)
	{
		random_variable = rand();
		std::cout << "random_variable:" << random_variable << std::endl;
		s.addNode(random_variable, tree);
	}
	s.printTree(tree, 0);
	std::cout << std::endl;
	s.balance(tree);
	s.printTree(tree, 0);
	s.deleteTree(tree);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	std::cout << "search_time:" << search_time << std::endl;
    return 0;
}

