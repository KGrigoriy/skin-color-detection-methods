#pragma once


class MethodYIQ {
private:
	int R;
	int G;
	int B;

	double Y();
	double I();
	double Q();

public:
	MethodYIQ(int red, int grean, int blue);
	~MethodYIQ();
	void setRed(int red);
	void setGrean(int grean);
	void setBlue(int blue);

	double getY();
	double getI();
	double getQ();

};