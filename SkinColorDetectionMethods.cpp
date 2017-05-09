#include "stdafx.h"
#include "Borders.h"

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

	printf("=============================================================\n");
	printf("=========== FINDING BORDERS FOR SKIN DETECTION ==============\n");
	printf("=============================================================\n\n\n");


	printf("=============================================================\n\n\n");
	printf("skin color detection from:\n");
	printf("1 - RGB\n");
	printf("2 - image\n");

	int src;
	scanf_s("%d", &src);

	printf("Enter a factor (0.0-1.0): ");
	double factor;
	scanf_s("%lf", &factor);

	Borders borders(src, factor);

	system("pause");
	return 0;
}

