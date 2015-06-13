#include"Triangle.h"
#include"iostream"
using namespace std;

Triangle::Triangle(double transVecX, double transVecY)
{
	for (int i = 1; i < sizeof(this->triangleCoords) / sizeof(double); i += 2)
	{
		this->triangleCoords[i - 1] = 0;
		this->triangleCoords[i - 1] = transVecX;
		this->triangleCoords[i] = 0;
		this->triangleCoords[i] = transVecY;
	}
}

void Triangle::createParam(char* params, int i)
{
	switch (i)
	{
		case 0:triangleCoords[0] += atof(params); break;
		case 1:triangleCoords[1] += atof(params); break;
		case 2:triangleCoords[2] += atof(params); break;
	}

	return;
}

void Triangle::isPointInside(double pointX, double pointY)
{
	int scalarA, scalarB, scalarC;
	scalarA = ((triangleCoords[3] - triangleCoords[5])*(pointX - triangleCoords[4]) +
		(triangleCoords[5] - triangleCoords[2])*(pointY - triangleCoords[4])) /
		((triangleCoords[3] - triangleCoords[5])*(triangleCoords[0] - triangleCoords[4]) +
		(triangleCoords[4] - triangleCoords[2])*(triangleCoords[1] - triangleCoords[5]));

	scalarB = ((triangleCoords[3] - triangleCoords[1])*(pointX - triangleCoords[4]) +
		(triangleCoords[0] - triangleCoords[4])*(pointY - triangleCoords[5])) /
		((triangleCoords[3] - triangleCoords[5])*(triangleCoords[0] - triangleCoords[4]) +
		(triangleCoords[4] - triangleCoords[2])*(triangleCoords[1] - triangleCoords[5]));

	scalarC = 1 - scalarA - scalarB;
	bool isInside = 0 <= scalarA <= 1 && 0 <= scalarB <= 1 && 0 <= scalarC <= 1;

	if (isInside)
	{
		cout << "triangle ";
		for (int i = 0; i < 6; i++)
		{
			cout << triangleCoords[i] << ' ';
		}
		cout << endl;
	}

}

Triangle::~Triangle()
{
}
