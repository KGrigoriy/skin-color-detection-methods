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

using namespace std;

class Borders
{
public:
	Borders(int src);
	~Borders();

	void detectionFromRGB();
	void detectionFromImage();
};

