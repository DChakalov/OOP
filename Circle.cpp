#include"iostream"
#include"Circle.h"
using namespace std;

Circle::Circle(double transVecX, double transVecY) : centerX(0), centerY(0), radiusLength(0)
{
	this->centerX = transVecX;
	this->centerY = transVecY;
}

void Circle::createParam(char* params, int i)
{
	switch (i)
	{
		case 0:centerX += atof(params); break;
		case 1:centerY += atof(params); break;
		case 2:radiusLength += atof(params); break;
	}

	return;
}

void Circle::isPointInside(double pointX, double pointY)
{
	double distance = (centerX - pointX)*(centerX - pointX) +
		(centerY - pointY)*(centerY - pointY);
	if (distance < radiusLength*radiusLength)
	{
		cout << "circle " << centerX 
			<< ' ' << centerY << ' ' 
			<< radiusLength << endl;
	}

}

Circle::~Circle()
{
}