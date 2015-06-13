#include"Rectanglee.h"
#include"iostream"
using namespace std;

Rectanglee::Rectanglee(double transVecX, double transVecY)
{
	for (int i = 1; i < sizeof(this->recCoords)/sizeof(double); i+=2)
	{
		this->recCoords[i - 1] = 0;
		this->recCoords[i - 1] = transVecX;
		this->recCoords[i] = 0;
		this->recCoords[i] = transVecY;
	}
}

void Rectanglee::createParam(char* params, int i)
{
	switch (i)
	{
		case 0:	recCoords[0] += atof(params); break;
		case 1:	recCoords[1] += atof(params); break;
		case 2:	recCoords[2] += atof(params); break;
		case 3:	recCoords[3] += atof(params); break;
	}

	return;
}

void Rectanglee::isPointInside(double pointX, double pointY)
{
	bool isInside = pointX >= recCoords[0] && pointX <= recCoords[2] &&
		pointY >= recCoords[1] && pointY <= recCoords[3];

	if (isInside)
	{
		cout << "rect ";
		for (int i = 0; i < 4; i++)
		{
			cout << recCoords[i] << ' ';
		}
		
		cout << endl;
	}
}

Rectanglee::~Rectanglee()
{
}
