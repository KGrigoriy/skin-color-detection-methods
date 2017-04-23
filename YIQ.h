#pragma once


class YIQ {
private:
	int R;
	int G;
	int B;

	double Y();
	double I();
	double Q();

public:
	YIQ(int red, int grean, int blue);
	~YIQ();

	void setRed(int red);
	void setGrean(int grean);
	void setBlue(int blue);

	double getY();
	double getI();
	double getQ();
};