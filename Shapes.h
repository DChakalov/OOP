#include<iostream>

#ifndef SHAPES_H
#define SHAPES_H

class Shapes
{
public:
	virtual void createParam(char*, int)=0;
	virtual void isPointInside(double, double)=0;
	Shapes(){};
	~Shapes(){};
private:

};


#endif