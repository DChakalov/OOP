#include"Shapes.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectanglee : public Shapes
{
public:
	Rectanglee()
	{
		for (int i = 0; i < 4; i++)
		{
			recCoords[i] = 0;
		}
	};
	Rectanglee(double, double);
	virtual void createParam(char*, int);
	virtual void isPointInside(double, double);
	~Rectanglee();

private:
	double recCoords[4];
};

#endif
