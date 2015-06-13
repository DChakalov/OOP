#include"Shapes.h"
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shapes
{
public:
	Circle() : centerX(0), centerY(0), radiusLength(0){};
	Circle(double, double);
	virtual void createParam(char*, int);
	virtual void isPointInside(double, double);
	~Circle();

private:
	double centerX;
	double centerY;
	double radiusLength;
};



#endif