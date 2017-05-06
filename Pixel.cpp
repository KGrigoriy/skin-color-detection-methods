#include "stdafx.h"
#include "Pixel.h"



	Pixel::Pixel()
	{
		R = 0;
		G = 0;
		B = 0;
		allColorFlag = false;
	}

	Pixel::~Pixel()
	{
	}

	int Pixel::getRed()
	{
		return R;
	}

	int Pixel::getGrean()
	{
		return G;
	}

	int Pixel::getBlue()
	{
		return B;
	}

	void Pixel::setRed(int r)
	{
		R = r;
	}

	void Pixel::setGrean(int g)
	{
		G = g;
	}

	void Pixel::setBlue(int b)
	{
		B = b;
	}

	void Pixel::nextRed(int step)
	{
		R = R + step;
	}

	void Pixel::nextGrean(int step)
	{
		G = G + step;
	}

	void Pixel::nextBlue(int step)
	{
		B = B + step;
	}

	void Pixel::allColor(int step)
	{
		if (R <= 255) 
		{
			nextRed(step);
		} else if (G <= 255) 
		{
			R = 0;
			nextGrean(step);
		} else if (B <= 255) 
		{
			R = 0;
			G = 0;
			nextBlue(step);
		}
		else {
			allColorFlag = true;
		}
	}

	bool Pixel::getAllColorFlag()
	{
		return allColorFlag;
	}
