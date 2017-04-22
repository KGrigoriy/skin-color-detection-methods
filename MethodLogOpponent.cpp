#include "stdafx.h"
#include "MethodLogOpponent.h"
#include <math.h> 



	MethodLogOpponent::MethodLogOpponent(int red, int grean, int blue)
	{
		R = red;
		G = grean;
		B = blue;
	}

	MethodLogOpponent::~MethodLogOpponent()
	{
	}

	void MethodLogOpponent::setRed(int red)
	{
		R = red;
	}

	void MethodLogOpponent::setGrean(int grean)
	{
		G = grean;
	}

	void MethodLogOpponent::setBlue(int blue)
	{
		B = blue;
	}


	double MethodLogOpponent::getH()
	{
		return H();
	}


	double MethodLogOpponent::H()
	{
		return atan2(Rg(), By()) * (180 / 3.141592654);
	}


	double MethodLogOpponent::Rg()
	{
		return log(R) - log(G);
	}

	double MethodLogOpponent::By()
	{
		return log(B) - (log(G) + log(R)) / 2;
	}

	double MethodLogOpponent::I()
	{
		return log(G);
	}




	//  void MethodLogOpponent::calculateS()
	//  {
	//  }

	//  int MethodLogOpponent::getS()
	//  {
	//  	return 0;
	//  }
