#pragma once

class LogOpponent {

private:
	int R;
	int G;
	int B;

//	int H; // Hue � �����������
//	int S; // Saturation ��������������
	double I();
	double Rg();
	double By();
	double H();
//	void calculateS();

public:
	LogOpponent(int red, int grean, int blue);
	~LogOpponent()
		;
	void setRed(int red);
	void setGrean(int grean);
	void setBlue(int blue);

	double getH();
	//int getS();
};