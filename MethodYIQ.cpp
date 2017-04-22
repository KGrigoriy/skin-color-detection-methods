#include "stdafx.h"
#include "MethodYIQ.h"



MethodYIQ::MethodYIQ(int red, int grean, int blue)
{
	R = red;
	G = grean;
	B = blue;
}

MethodYIQ::~MethodYIQ()
{
}


void MethodYIQ::setRed(int red)
{
	R = red;
}

void MethodYIQ::setGrean(int grean)
{
	G = grean;
}

void MethodYIQ::setBlue(int blue)
{
	B = blue;
}


double MethodYIQ::Y()
{
	return 0.299 * R + 0.587 * G + 0.114 * B;
}

double MethodYIQ::I()
{
	return 0.596 * R - 0.274 * G - 0.322 * B;
}

double MethodYIQ::Q()
{
	return 0.211 * R - 0.522 * G + 0.311 * B;
}





double MethodYIQ::getY()
{
	return Y();
}

double MethodYIQ::getI()
{
	return I();
}

double MethodYIQ::getQ()
{
	return Q();
}
