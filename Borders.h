#pragma once

#include "Pixel.h"
#include "LogOpponent.h"
#include "YIQ.h"
#include "TSL.h"
#include "HSV.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "FreeImage.h"
#include <FreeImage.h>
#include <fstream>

using namespace std;

class Borders
{
private:
	double factor;

	double logOpponentMinH;
	double logOpponenthsvMaxH;

	double yiqMinI;
	double yiqMaxI;
				  
	double hsvMinH;
	double hsvMaxH;
	double hsvMinS;
	double hsvMaxS;
	double hsvMinV;
	double hsvMaxV;
				  
	double tslMinT;
	double tslMaxT;
	double tslMinS;
	double tslMaxS;

	void detectionFromRGB();
	void detectionFromImage();
	//void outResult();
	void safeFilters();

public:
	Borders(int src, double fact);
	~Borders();
};

