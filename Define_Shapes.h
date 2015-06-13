#include<fstream>
#include"Shapes.h"
#ifndef Define_Shapes_H
#define Define_Shapes_H

class Define_Shapes
{
public:
	Define_Shapes(double, double);
	void createShapes(int, std::fstream&);
	void getShapeParameters(std::fstream&, Shapes*);
	void getTransVecParams(std::fstream&);
	char* paramsMemory(char*, int);
	char* bufferRelease(char*, int, int&);

	Define_Shapes(){};
	~Define_Shapes();

private:
	int allShapesInFile;
	Shapes** shapes;
	double transVecCoords[2];
};


#endif