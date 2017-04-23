#include "stdafx.h"
#include "YIQ.h"



YIQ::YIQ(int red, int grean, int blue)
{
	R = red;
	G = grean;
	B = blue;
}

YIQ::~YIQ()
{
}


void YIQ::setRed(int red)
{
	R = red;
}

void YIQ::setGrean(int grean)
{
	G = grean;
}

void YIQ::setBlue(int blue)
{
	B = blue;
}


double YIQ::Y()
{
	return 0.299 * R + 0.587 * G + 0.114 * B;
}

double YIQ::I()
{
	return 0.596 * R - 0.274 * G - 0.322 * B;
}

double YIQ::Q()
{
	return 0.211 * R - 0.522 * G + 0.311 * B;
}





double YIQ::getY()
{
	return Y();
}

double YIQ::getI()
{
	return I();
}

double YIQ::getQ()
{
	return Q();
}
