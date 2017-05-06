#include "stdafx.h"
#include "HSV.h"
#include <math.h> 

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

double HSV::min(int v1, int v2, int v3)
{
	if (v1 < v2) 
	{
		if (v1 < v3)
		{
			return v1;
		}
		else
		{
			return v3;
		}
	}
	else if (v2 < v3)
	{
		return v2;
	}
	else
	{
		return v3;
	}
}

double HSV::H()
{
	double numer = 0.5 * ((R - G) + (R - B));
	double denom = sqrt(pow(R - G, 2) + ((R - B)*(G - B)));
	double res = acos((double) numer / denom);
	return res;
}

double HSV::S()
{
	double res = 1 - (3 * ((double) min(R, G, B) / (R + G + B)));
	return res;
}

double HSV::V()
{
	double res = 0.3333333333 * (R + G + B);
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
