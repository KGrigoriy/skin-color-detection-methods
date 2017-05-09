#include "stdafx.h"
#include "Borders.h"

#include "FreeImage.h"
#include <FreeImage.h>


Borders::Borders(int src, double fact)
{
	factor = fact;

	switch (src)
	{
	case 1:
		detectionFromRGB();
		break;
	case 2:
		detectionFromImage();
		break;
	}
}


Borders::~Borders()
{
}


void Borders::detectionFromRGB() {
	Pixel pixel;
	LogOpponent logOpponent(0, 0, 0);
	YIQ yiq(0, 0, 0);
	HSV hsv(0, 0, 0);
	TSL tsl(0, 0, 0);

	int step = 5;
	int count = 0;
	int countTrue = 0;
	int arrayElements = ceil(16777216 / (step*step*step));


	double* logOpponentArrayH = new double[arrayElements];

	double* yiqArrayI = new double[arrayElements];

	double* hsvArrayH = new double[arrayElements];
	double* hsvArrayS = new double[arrayElements];
	double* hsvArrayV = new double[arrayElements];

	double* tslArrayT = new double[arrayElements];
	double* tslArrayS = new double[arrayElements];

	for (; !pixel.getAllColorFlag(); pixel.allColor(step), count++) {
		if ((pixel.getRed() > 90 && pixel.getGrean() > 40 && pixel.getBlue() > 20 && pixel.getRed() - pixel.getGrean() > 15 && pixel.getRed() > pixel.getBlue())) {

			logOpponent.setRed(pixel.getRed());
			logOpponent.setGrean(pixel.getGrean());
			logOpponent.setBlue(pixel.getBlue());
			logOpponentArrayH[countTrue] = logOpponent.getH();

			yiq.setRed(pixel.getRed());
			yiq.setGrean(pixel.getGrean());
			yiq.setBlue(pixel.getBlue());
			yiqArrayI[countTrue] = yiq.getI();

			hsv.setRed(pixel.getRed());
			hsv.setGrean(pixel.getGrean());
			hsv.setBlue(pixel.getBlue());
			hsvArrayH[countTrue] = hsv.getH();
			hsvArrayS[countTrue] = hsv.getS();
			hsvArrayV[countTrue] = hsv.getV();

			tsl.setRed(pixel.getRed());
			tsl.setGrean(pixel.getGrean());
			tsl.setBlue(pixel.getBlue());
			tslArrayT[countTrue] = tsl.getT();
			tslArrayS[countTrue] = tsl.getS();


			countTrue++;
		}

		cout << "all: " << count << "   true: " << countTrue << " " << pixel.getRed() << " " << pixel.getGrean() << " " << pixel.getBlue() << endl;
	}


	logOpponentMinH = logOpponentArrayH[0];
	logOpponenthsvMaxH = logOpponentArrayH[0];

	yiqMinI = yiqArrayI[0];
	yiqMaxI = yiqArrayI[0];

	hsvMinH = hsvArrayH[0];
	hsvMaxH = hsvArrayH[0];
	hsvMinS = hsvArrayS[0];
	hsvMaxS = hsvArrayS[0];
	hsvMinV = hsvArrayV[0];
	hsvMaxV = hsvArrayV[0];

	tslMinT = tslArrayT[0];
	tslMaxT = tslArrayT[0];
	tslMinS = tslArrayS[0];
	tslMaxS = tslArrayS[0];


	for (int i = 0; i<countTrue; i++)
	{
		if (logOpponentMinH > logOpponentArrayH[i])
		{
			logOpponentMinH = logOpponentArrayH[i];
		}
		else if (logOpponenthsvMaxH < logOpponentArrayH[i])
		{
			logOpponenthsvMaxH = logOpponentArrayH[i];
		}


		if (yiqMinI > yiqArrayI[i])
		{
			yiqMinI = yiqArrayI[i];
		}
		else if (yiqMaxI < yiqArrayI[i])
		{
			yiqMaxI = yiqArrayI[i];
		}


		if (hsvMinH > hsvArrayH[i])
		{
			hsvMinH = hsvArrayH[i];
		}
		else if (hsvMaxH < hsvArrayH[i])
		{
			hsvMaxH = hsvArrayH[i];
		}

		if (hsvMinS > hsvArrayS[i])
		{
			hsvMinS = hsvArrayS[i];
		}
		else if (hsvMaxS < hsvArrayS[i])
		{
			hsvMaxS = hsvArrayS[i];
		}

		if (hsvMinV > hsvArrayV[i])
		{
			hsvMinV = hsvArrayV[i];
		}
		else if (hsvMaxV < hsvArrayV[i])
		{
			hsvMaxV = hsvArrayV[i];
		}


		if (tslMinT > tslArrayT[i])
		{
			tslMinT = tslArrayT[i];
		}
		else if (tslMaxT < tslArrayT[i])
		{
			tslMaxT = tslArrayT[i];
		}

		if (tslMinS > tslArrayS[i])
		{
			tslMinS = tslArrayS[i];
		}
		else if (tslMaxS < tslArrayS[i])
		{
			tslMaxS = tslArrayS[i];
		}
	}

	cout << "===========LOG OPPONENT===========" << endl;
	cout << "logOpponentMinH is: " << logOpponentMinH << endl;
	cout << "logOpponenthsvMaxH is: " << logOpponenthsvMaxH << endl;

	cout << "===========YIQ===========" << endl;
	cout << "yiqMinI is: " << yiqMinI << endl;
	cout << "yiqMaxI is: " << yiqMaxI << endl;

	cout << "===========HSV===========" << endl;
	cout << "hsvMinH is: " << hsvMinH << endl;
	cout << "hsvMaxH is: " << hsvMaxH << endl;
	cout << "hsvMinS is: " << hsvMinS << endl;
	cout << "hsvMaxS is: " << hsvMaxS << endl;
	cout << "hsvMinV is: " << hsvMinV << endl;
	cout << "hsvMaxV is: " << hsvMaxV << endl;

	cout << "===========TSL===========" << endl;
	cout << "tslMinT is: " << tslMinT << endl;
	cout << "tslMaxT is: " << tslMaxT << endl;
	cout << "tslMinS is: " << tslMinS << endl;
	cout << "tslMaxS is: " << tslMaxS << endl;

	safeFilters();
}

void Borders::detectionFromImage() {
	Pixel pixel;
	LogOpponent logOpponent(0, 0, 0);
	YIQ yiq(0, 0, 0);
	HSV hsv(0, 0, 0);
	TSL tsl(0, 0, 0);

	int step = 10;
	int count = 0;
	int countTrue = 0;

	char *fileIn = "in.jpg";
	FIBITMAP *originalImage = FreeImage_Load(FIF_JPEG, fileIn, 0);
	RGBQUAD color;
	int widthOriginal = FreeImage_GetWidth(originalImage);
	int heightOriginal = FreeImage_GetHeight(originalImage);

	int arrayElements = widthOriginal * heightOriginal;


	double* logOpponentArrayH = new double[arrayElements];

	double* yiqArrayI = new double[arrayElements];

	double* hsvArrayH = new double[arrayElements];
	double* hsvArrayS = new double[arrayElements];
	double* hsvArrayV = new double[arrayElements];

	double* tslArrayT = new double[arrayElements];
	double* tslArrayS = new double[arrayElements];

	

	for (int x = 0; x <= widthOriginal; x++) {
		for (int y = 0; y <= heightOriginal; y++) {
			FreeImage_GetPixelColor(originalImage, x, y, &color);
			int r, g, b;
			r = color.rgbRed;
			g = color.rgbGreen;
			b = color.rgbBlue;

			pixel.setRed(r);
			pixel.setGrean(g);
			pixel.setBlue(b);

			if (r != 0 && g != 0 && b != 0) {

				logOpponent.setRed(pixel.getRed());
				logOpponent.setGrean(pixel.getGrean());
				logOpponent.setBlue(pixel.getBlue());
				logOpponentArrayH[countTrue] = logOpponent.getH();

				yiq.setRed(pixel.getRed());
				yiq.setGrean(pixel.getGrean());
				yiq.setBlue(pixel.getBlue());
				yiqArrayI[countTrue] = yiq.getI();

				hsv.setRed(pixel.getRed());
				hsv.setGrean(pixel.getGrean());
				hsv.setBlue(pixel.getBlue());
				hsvArrayH[countTrue] = hsv.getH();
				hsvArrayS[countTrue] = hsv.getS();
				hsvArrayV[countTrue] = hsv.getV();

				tsl.setRed(pixel.getRed());
				tsl.setGrean(pixel.getGrean());
				tsl.setBlue(pixel.getBlue());
				tslArrayT[countTrue] = tsl.getT();
				tslArrayS[countTrue] = tsl.getS();


				countTrue++;
			}


			cout << " w: " << x << " h: " << y << " all: " << arrayElements << "   true: " << countTrue << " " << pixel.getRed() << " " << pixel.getGrean() << " " << pixel.getBlue() << endl;
		}
	}


	logOpponentMinH = logOpponentArrayH[0];
	logOpponenthsvMaxH = logOpponentArrayH[0];

	yiqMinI = yiqArrayI[0];
	yiqMaxI = yiqArrayI[0];

	hsvMinH = hsvArrayH[0];
	hsvMaxH = hsvArrayH[0];
	hsvMinS = hsvArrayS[0];
	hsvMaxS = hsvArrayS[0];
	hsvMinV = hsvArrayV[0];
	hsvMaxV = hsvArrayV[0];

	tslMinT = tslArrayT[0];
	tslMaxT = tslArrayT[0];
	tslMinS = tslArrayS[0];
	tslMaxS = tslArrayS[0];


	for (int i = 0; i < countTrue; i++)
	{
		if (logOpponentMinH > logOpponentArrayH[i])
		{
			logOpponentMinH = logOpponentArrayH[i];
		}
		else if (logOpponenthsvMaxH < logOpponentArrayH[i])
		{
			logOpponenthsvMaxH = logOpponentArrayH[i];
		}


		if (yiqMinI > yiqArrayI[i])
		{
			yiqMinI = yiqArrayI[i];
		}
		else if (yiqMaxI < yiqArrayI[i])
		{
			yiqMaxI = yiqArrayI[i];
		}


		if (hsvMinH > hsvArrayH[i])
		{
			hsvMinH = hsvArrayH[i];
		}
		else if (hsvMaxH < hsvArrayH[i])
		{
			hsvMaxH = hsvArrayH[i];
		}

		if (hsvMinS > hsvArrayS[i])
		{
			hsvMinS = hsvArrayS[i];
		}
		else if (hsvMaxS < hsvArrayS[i])
		{
			hsvMaxS = hsvArrayS[i];
		}

		if (hsvMinV > hsvArrayV[i])
		{
			hsvMinV = hsvArrayV[i];
		}
		else if (hsvMaxV < hsvArrayV[i])
		{
			hsvMaxV = hsvArrayV[i];
		}


		if (tslMinT > tslArrayT[i])
		{
			tslMinT = tslArrayT[i];
		}
		else if (tslMaxT < tslArrayT[i])
		{
			tslMaxT = tslArrayT[i];
		}

		if (tslMinS > tslArrayS[i])
		{
			tslMinS = tslArrayS[i];
		}
		else if (tslMaxS < tslArrayS[i])
		{
			tslMaxS = tslArrayS[i];
		}
	}

	cout << "===========LOG OPPONENT===========" << endl;
	cout << "logOpponentMinH is: " << factor * logOpponentMinH << endl;
	cout << "logOpponenthsvMaxH is: " << factor * logOpponenthsvMaxH << endl;

	cout << "===========YIQ===========" << endl;
	cout << "yiqMinI is: " << factor * yiqMinI << endl;
	cout << "yiqMaxI is: " << factor * yiqMaxI << endl;

	cout << "===========HSV===========" << endl;
	cout << "hsvMinH is: " << factor * hsvMinH << endl;
	cout << "hsvMaxH is: " << factor * hsvMaxH << endl;
	cout << "hsvMinS is: " << factor * hsvMinS << endl;
	cout << "hsvMaxS is: " << factor * hsvMaxS << endl;
	cout << "hsvMinV is: " << factor * hsvMinV << endl;
	cout << "hsvMaxV is: " << factor * hsvMaxV << endl;

	cout << "===========TSL===========" << endl;
	cout << "tslMinT is: " <<  factor * tslMinT << endl;
	cout << "tslMaxT is: " <<  factor * tslMaxT << endl;
	cout << "tslMinS is: " <<  factor * tslMinS << endl;
	cout << "tslMaxS is: " <<  factor * tslMaxS << endl;

	safeFilters();
}

void Borders::safeFilters()
{

	ofstream fout("Filters.txt");
	fout.trunc;
	fout << factor * logOpponentMinH
		<< endl << factor * logOpponenthsvMaxH
		<< endl <<  factor * yiqMinI
		<< endl <<  factor * yiqMaxI
		<< endl <<  factor * hsvMinH
		<< endl <<  factor * hsvMaxH
		<< endl <<  factor * hsvMinS
		<< endl <<  factor * hsvMaxS
		<< endl <<  factor * hsvMinV
		<< endl <<  factor * hsvMaxV
		<< endl <<  factor * tslMinT
		<< endl <<  factor * tslMaxT
		<< endl <<  factor * tslMinS
		<< endl <<  factor * tslMaxS << endl;
	fout.close();
}
