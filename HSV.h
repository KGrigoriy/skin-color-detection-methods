#pragma once

class HSV {

private:
	int R;
	int G;
	int B;
	double H();
	double S();
	double V();
	double minOfThree(int v1, int v2, int v3);

public:
	HSV(int red, int grean, int blue);
	~HSV();

	void setRed(int red);
	void setGrean(int grean);
	void setBlue(int blue);

	double getH();
	double getS();
	double getV();
};
