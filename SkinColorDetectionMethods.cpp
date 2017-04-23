#include "stdafx.h"
#include "Pixel.h"
#include "LogOpponent.h"
#include "YIQ.h"
#include "TSL.h"
#include "HSV.h"
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
	LogOpponent logOpponent(0, 0, 0);
	YIQ yiq(0, 0, 0);
	HSV hsv(0, 0, 0);
	TSL tsl(0, 0, 0);

	int step = 10;
	int count = 0;
	int countTrue = 0;
	int arrayElements = ceil(16777216 / (step*step*step));


	double* logOpponentArrayH = new double[arrayElements];

	double* yiqArrayI = new double[arrayElements];

	double* hsvArrayH = new double[arrayElements];
	double* hsvArrayS = new double[arrayElements];
	double* hsvArrayV = new double[arrayElements];

	double* tslArrayT = new double[arrayElements];
	double* tslArrayS = new double[arrayElements];

	for (; !pixel.getAllColorFlag(); pixel.allColor(step), count++) {
		if ((pixel.getRed() > 90 && pixel.getGrean() > 40 && pixel.getBlue() > 20 && pixel.getRed() - pixel.getGrean() > 15 && pixel.getRed() > pixel.getBlue())) {

			logOpponent.setRed(pixel.getRed());
			logOpponent.setGrean(pixel.getGrean());
			logOpponent.setBlue(pixel.getBlue());
			logOpponentArrayH[countTrue] = logOpponent.getH();

			yiq.setRed(pixel.getRed());
			yiq.setGrean(pixel.getGrean());
			yiq.setBlue(pixel.getBlue());
			yiqArrayI[countTrue] = yiq.getI();

			hsv.setRed(pixel.getRed());
			hsv.setGrean(pixel.getGrean());
			hsv.setBlue(pixel.getBlue());
			hsvArrayH[countTrue] = hsv.getH();
			hsvArrayS[countTrue] = hsv.getS();
			hsvArrayV[countTrue] = hsv.getV();

			tsl.setRed(pixel.getRed());
			tsl.setGrean(pixel.getGrean());
			tsl.setBlue(pixel.getBlue());
			tslArrayT[countTrue] = tsl.getT();
			tslArrayS[countTrue] = tsl.getS();


			countTrue++;
		}

		cout << "all: " << count << "   true: " << countTrue << " " << pixel.getRed() << " " << pixel.getGrean() << " " << pixel.getBlue() << endl;
	}


	double logOpponentMinH = logOpponentArrayH[0];
	double logOpponenthsvMaxH = logOpponentArrayH[0];

	double yiqMinI = yiqArrayI[0];
	double yiqMaxI = yiqArrayI[0];

	double hsvMinH = hsvArrayH[0];
	double hsvMaxH = hsvArrayH[0];
	double hsvMinS = hsvArrayS[0];
	double hsvMaxS = hsvArrayS[0];
	double hsvMinV = hsvArrayV[0];
	double hsvMaxV = hsvArrayV[0];

	double tslMinT = tslArrayT[0];
	double tslMaxT = tslArrayT[0];
	double tslMinS = tslArrayS[0];
	double tslMaxS = tslArrayS[0];


	for (int i = 0; i<countTrue; i++)
	{
		if (logOpponentMinH > logOpponentArrayH[i])
		{
			logOpponentMinH = logOpponentArrayH[i];
		}
		else if (logOpponenthsvMaxH < logOpponentArrayH[i])
		{
			logOpponenthsvMaxH = logOpponentArrayH[i];
		}


		if (yiqMinI > yiqArrayI[i])
		{
			yiqMinI = yiqArrayI[i];
		}
		else if (yiqMaxI < yiqArrayI[i])
		{
			yiqMaxI = yiqArrayI[i];
		}


		if (hsvMinH > hsvArrayH[i])
		{
			hsvMinH = hsvArrayH[i];
		}
		else if (hsvMaxH < hsvArrayH[i])
		{
			hsvMaxH = hsvArrayH[i];
		}

		if (hsvMinS > hsvArrayS[i])
		{
			hsvMinS = hsvArrayS[i];
		}
		else if (hsvMaxS < hsvArrayS[i])
		{
			hsvMaxS = hsvArrayS[i];
		}

		if (hsvMinV > hsvArrayV[i])
		{
			hsvMinV = hsvArrayV[i];
		}
		else if (hsvMaxV < hsvArrayV[i])
		{
			hsvMaxV = hsvArrayV[i];
		}


		if (tslMinT > tslArrayT[i])
		{
			tslMinT = tslArrayT[i];
		}
		else if (tslMaxT < tslArrayT[i])
		{
			tslMaxT = tslArrayT[i];
		}

		if (tslMinS > tslArrayS[i])
		{
			tslMinS = tslArrayS[i];
		}
		else if (tslMaxS < tslArrayS[i])
		{
			tslMaxS = tslArrayS[i];
		}
	}

	cout << "===========LOG OPPONENT===========" << endl;
	cout << "logOpponentMinH is: " << logOpponentMinH << endl;
	cout << "logOpponenthsvMaxH is: " << logOpponenthsvMaxH << endl;

	cout << "===========YIQ===========" << endl;
	cout << "yiqMinI is: " << yiqMinI << endl;
	cout << "yiqMaxI is: " << yiqMaxI << endl;

	cout << "===========HSV===========" << endl;
	cout << "hsvMinH is: " << hsvMinH << endl;
	cout << "hsvMaxH is: " << hsvMaxH << endl;
	cout << "hsvMinS is: " << hsvMinS << endl;
	cout << "hsvMaxS is: " << hsvMaxS << endl;
	cout << "hsvMinV is: " << hsvMinV << endl;
	cout << "hsvMaxV is: " << hsvMaxV << endl;

	cout << "===========TSL===========" << endl;
	cout << "tslMinT is: " << tslMinT << endl;
	cout << "tslMaxT is: " << tslMaxT << endl;
	cout << "tslMinS is: " << tslMinS << endl;
	cout << "tslMaxS is: " << tslMaxS << endl;

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