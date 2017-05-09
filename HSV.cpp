#include "HSV.h"
#include <math.h> 
#include <algorithm>
using namespace std;

HSV::HSV(int red, int grean, int blue)
{
	R = red;
	G = grean;
	B = blue;
}

HSV::~HSV()
{
}

void HSV::setRed(int red)
{
	R = red;
}

void HSV::setGrean(int grean)
{
	G = grean;
}

void HSV::setBlue(int blue)
{
	B = blue;
}

double HSV::minOfThree(int v1, int v2, int v3)
{
	int min = v1;

	if (v2 < min) {
		min = v2;
	}
	if (v3 < min) {
		min = v3;
	}
	return min;
}

double HSV::H()
{
	//double numer = 0.5 * ((R - G) + (R - B));
	//	double denom = sqrt(pow(R - G, 2) + ((R - B)*(G - B)));
	//double res = acos((double) numer / denom);

	//	return res;

	double H = 0;
	double D = max(R, max(G, B)) - min(R, min(G, B));

	if (R == V())
		H = (double)(G - B) / (6 * D);
	if (G == V())
		H = (double)(2 - R + B) / (6 * D);
	if (B == V())
		H = (double)(4 - G + R) / (6 * D);

	return H;
}

double HSV::S()
{
	//double res = 1 - (3 * ((double)minOfThree(R, G, B) / (R + G + B)));

	double D = max(R, max(G, B)) - min(R, min(G, B));
	double res = (double)D / V();

	return res;
}

double HSV::V()
{
	//double res = (double)1/3 * (R + G + B);
	double res = max(R, max(G, B));
	return res;
}





double HSV::getH()
{
	return H();
}

double HSV::getS()
{
	return S();
}

double HSV::getV()
{
	return V();
}