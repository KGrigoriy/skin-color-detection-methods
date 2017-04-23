#pragma once

class TSL {
private:
	int R;
	int G;
	int B;

	double T();
	double S();
	double L();


	double  Rr();
	double  Gg();

	double  r();
	double  g();
public:
	TSL(int red, int grean, int blue);
	~TSL();

	void setRed(int red);
	void setGrean(int grean);
	void setBlue(int blue);

	double getT();
	double getS();
	double getL();

};