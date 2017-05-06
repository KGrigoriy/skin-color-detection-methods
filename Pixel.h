#pragma once

class Pixel {
private:
	int R;
	int G;
	int B;
	bool allColorFlag;

public:
	Pixel();
	~Pixel();
	int getRed();
	int getGrean();
	int getBlue();
	void setRed(int r);
	void setGrean(int g);
	void setBlue(int b);
	void nextRed(int step);
	void nextGrean(int step);
	void nextBlue(int step);
	void allColor(int step);
	bool getAllColorFlag();
};