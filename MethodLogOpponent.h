#pragma once

class MethodLogOpponent {

private:
	int R;
	int G;
	int B;

//	int H; // Hue Ч цветовой†тон
//	int S; // Saturation Ч†насыщенность
	double I();
	double Rg();
	double By();
	double H();
//	void calculateS();

public:
	MethodLogOpponent(int red, int grean, int blue);
	~MethodLogOpponent();
	void setRed(int red);
	void setGrean(int grean);
	void setBlue(int blue);

	double getH();
	//int getS();


};