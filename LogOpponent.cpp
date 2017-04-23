#include "stdafx.h"
#include "LogOpponent.h"
#include <math.h> 



	LogOpponent::LogOpponent(int red, int grean, int blue)
	{
		R = red;
		G = grean;
		B = blue;
	}

	LogOpponent::~LogOpponent()
	{
	}

	void LogOpponent::setRed(int red)
	{
		R = red;
	}

	void LogOpponent::setGrean(int grean)
	{
		G = grean;
	}

	void LogOpponent::setBlue(int blue)
	{
		B = blue;
	}


	double LogOpponent::getH()
	{
		return H();
	}


	double LogOpponent::H()
	{
		return atan2(Rg(), By()) * (180 / 3.141592654);
	}


	double LogOpponent::Rg()
	{
		return log(R) - log(G);
	}

	double LogOpponent::By()
	{
		return log(B) - (log(G) + log(R)) / 2;
	}

	double LogOpponent::I()
	{
		return log(G);
	}




	//  void LogOpponent::calculateS()
	//  {
	//  }

	//  int LogOpponent::getS()
	//  {
	//  	return 0;
	//  }
