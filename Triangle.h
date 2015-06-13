#include"Shapes.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shapes
{
public:
	Triangle()
	{
		for (int i = 0; i < 6; i++)
		{
			triangleCoords[i] = 0;
		}
	};
	Triangle(double, double);
	virtual void createParam(char*, int);
	virtual void isPointInside(double, double);
	~Triangle();
	
private:
	double triangleCoords[6];
};



#endif