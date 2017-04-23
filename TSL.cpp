#include "stdafx.h"
#include "TSL.h"
#include <math.h> 

TSL::TSL(int red, int grean, int blue)
{
	R = red;
	G = grean;
	B = blue;
}

TSL::~TSL()
{
}


void TSL::setRed(int red)
{
	R = red;
}

void TSL::setGrean(int grean)
{
	G = grean;
}

void TSL::setBlue(int blue)
{
	B = blue;
}


double TSL::getT()
{
	return T();
}

double TSL::getS()
{
	return S();
}

double TSL::getL()
{
	return L();
}


double TSL::T()
{
	if (Gg() > 0)
	{
		double numer = atan((double) Rr() / Gg());
		double denom = 2 * 3.141592654 + (double) 1/4;
		double res = (double) numer / denom;
		return res;
	}
	else if (Gg() < 0)
	{
		double numer = atan((double)Rr() / Gg());
		double denom = 2 * 3.141592654 + (double) 3/4;
		double res = (double) numer / denom;
		return res;
	}
	else
	{
		return 0.0;
	}
}

double TSL::S()
{
	double step1 = pow(Rr(), 2) + pow(Gg(), 2);
	double step2 = 9 * (double) step1 / 5;
	double res = pow(fabs(step2), 0.5);
	return res;
}

double TSL::L()
{
	return 0.299 * R + 0.587 * G + 0.114 * B;
}

double  TSL::Rr()
{
	return r() - (double) 1/3;
}

double  TSL::Gg()
{
	return g() - (double) 1/3;
}

double  TSL::r()
{

	return (double) R / (R + G + B);
}

double  TSL::g()
{

	return (double) G / (R + G + B);
}
