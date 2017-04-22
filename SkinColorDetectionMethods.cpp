#include "stdafx.h"
#include "Pixel.h"
#include "MethodLogOpponent.h"
#include "MethodYIQ.h"
#include <math.h>

#include <iostream>


using namespace std;

/*

skin


R > 90
G > 40
B > 20
R - G > 15
R > B
*/


int main(int argc, char **argv)
{
	Pixel pixel;
	MethodLogOpponent logOpponent(0, 0, 0);
	MethodYIQ YIQ(0, 0, 0);

	int step = 5;
	int count = 0;
	int countTrue = 0;
	int arrayElements = ceil(16777216 / (step*step*step));


	double* arrayH = new double[arrayElements];
	double* arrayI = new double[arrayElements];

	for (; !pixel.getAllColorFlag(); pixel.allColor(step), count++) {
		if ((pixel.getRed() > 90 && pixel.getGrean() > 40 && pixel.getBlue() > 20 && pixel.getRed() - pixel.getGrean() > 15 && pixel.getRed() > pixel.getBlue())) {

			logOpponent.setRed(pixel.getRed());
			logOpponent.setGrean(pixel.getGrean());
			logOpponent.setBlue(pixel.getBlue());

			arrayH[countTrue] = logOpponent.getH();

			YIQ.setRed(pixel.getRed());
			YIQ.setGrean(pixel.getGrean());
			YIQ.setBlue(pixel.getBlue());

			arrayI[countTrue] = YIQ.getI();

			countTrue++;
		}
		//double pers = (100 / ((arrayElements/4)/ (countElements+1))*count);
		cout << "all: " << count << "   true: " << countTrue << " " << pixel.getRed() << " " << pixel.getGrean() << " " << pixel.getBlue() << endl;
	}


	int maxH = arrayH[0];
	int minH = arrayH[0];

	int maxI = arrayI[0];
	int minI = arrayI[0];

	for (int i = 0; i<countTrue; i++)
	{
		if (minH > arrayH[i])
		{
			minH = arrayH[i];
		}
		else if (maxH < arrayH[i])
		{
			maxH = arrayH[i];
		}

		if (minI > arrayI[i])
		{
			minI = arrayI[i];
		}
		else if (maxI < arrayI[i])
		{
			maxI = arrayI[i];
		}
	}

	cout << "Maximum hue number is: " << maxH << endl;
	cout << "Minimum hue number is: " << minH << endl;

	cout << "Maximum I number is: " << maxI << endl;
	cout << "Minimum I number is: " << minI << endl;


	system("pause");
	return 0;
}

//example 

//      typedef struct Tree
//      {
//      	int data;
//      	Tree *left;
//      	Tree *right;
//      } Node;
//      
//      /* recursion routine to find path */
//      void pathFinder(Node* node, int path[], int level)
//      {
//      
//      	if (node == NULL) return;
//      	// leaf node save
//      	if (node->left == NULL && node->right == NULL) {
//      		path[level] = node->data;
//      		int sum = 0;
//      		for (int i = 0; i <= level; i++) {
//      			cout << path[i] << " ";
//      			sum += path[i];
//      		}
//      		cout << "  sum = " << sum << endl;
//      		return;
//      	}
//      	// parent node save
//      	path[level] = node->data;
//      	pathFinder(node->left, path, level + 1);
//      	pathFinder(node->right, path, level + 1);
//      }
//      
//      struct Tree* insertNode(Tree *node, int data)
//      {
//      	node->data = data;
//      	node->left = NULL;
//      	node->right = NULL;
//      	return node;
//      }
//      
//      int main(int argc, char **argv)
//      {
//      	Tree *root = NULL;
//      	Tree *nodeLeft = NULL;
//      	Tree *nodeRight = NULL;
//      
//      	// unsorted binary tree
//      	// root
//      	root = insertNode(new Tree, 3);
//      
//      	// 1st level
//      	nodeLeft = insertNode(new Tree, -1);
//      	root->left = nodeLeft;
//      	nodeRight = insertNode(new Tree, 2);
//      	root->right = nodeRight;
//      
//      	// 2nd level
//      	nodeLeft->left = insertNode(new Tree, 5);
//      	nodeLeft->right = insertNode(new Tree, 7);
//      	nodeRight->left = insertNode(new Tree, 1);
//      
//      	// path find
//      	int path[10];
//      	pathFinder(root, path, 0);
//      
//      	system("pause");
//      
//      	return 0;
//      }
//      
//      /* output */
//      /*
//      3 -1 5  sum = 7
//      3 -1 7  sum = 9
//      3 2 1  sum = 6
//      */