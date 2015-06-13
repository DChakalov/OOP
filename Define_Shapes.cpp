#include"Define_Shapes.h"
#include"Shapes.h"
#include"Rectanglee.h"
#include"Triangle.h"
#include"Circle.h"
#include<fstream>
using namespace std;
Define_Shapes::Define_Shapes(double pointX, double pointY) : allShapesInFile(0), shapes(NULL)
{
	transVecCoords[0] = 0;
	transVecCoords[1] = 0;

	fstream fileWithShapes;
	fileWithShapes.open("Shapes.txt", ios::in);
	if (!fileWithShapes)
	{
		cout << "No such a file.." << endl;
		return;
	}

	allShapesInFile = 1;
	const int lineLength = 1000;
	const int shapeNameLength = 10;
	const int nOfShapes = 3;

	char shapeNames[nOfShapes][shapeNameLength] = { "circle", "rect", "triangle"};
	char group[2][shapeNameLength] = {"group in", "group out"};
	char* buffer = new char[lineLength];

	for (int i = 0; !fileWithShapes.eof();)
	{
		buffer[i] = fileWithShapes.get();
		i++;
		for (int j = 0; j < nOfShapes; j++)
		{
			if (!strncmp(buffer, shapeNames[j], strlen(shapeNames[j])))
			{
				createShapes(j, fileWithShapes);
				buffer = bufferRelease(buffer, lineLength, i);
				shapes[allShapesInFile-1]->isPointInside(pointX, pointY);
				allShapesInFile++;
			}
			else if (!strncmp(buffer, group[0], strlen(group[0])))
			{
				getTransVecParams(fileWithShapes);
				buffer = bufferRelease(buffer, lineLength, i);
			}
			else if (!strncmp(buffer, group[1], strlen(group[1])))
			{
				transVecCoords[0] = 0;
				transVecCoords[1] = 0;
				buffer = bufferRelease(buffer, lineLength, i);
			}
		}
	}

	delete[] buffer;
} 

char* Define_Shapes::bufferRelease(char* buffer, int size, int& index)
{
	delete[] buffer;
	buffer = new char[size];
	index = 0;

	return buffer;
}


void Define_Shapes::createShapes(int figN, fstream& fileWithShapes)
{
	Shapes** pShapes = new Shapes*[allShapesInFile];
	for(int i = 0; i < allShapesInFile-1; i++)
	{
		pShapes[i] = shapes[i];
	}

	if (shapes != NULL)
	{
		delete[] shapes;
	}

	shapes = pShapes;
	pShapes = NULL;

	switch (figN)
	{
		case 0: shapes[allShapesInFile-1] = new Circle(transVecCoords[0], transVecCoords[1]); 
			break;	   
		case 1: shapes[allShapesInFile-1] = new Rectanglee(transVecCoords[0], transVecCoords[1]);
			break;	   
		case 2: shapes[allShapesInFile-1] = new Triangle(transVecCoords[0], transVecCoords[1]);
			break;
	}

	getShapeParameters(fileWithShapes, shapes[allShapesInFile-1]);

	return;
}

void Define_Shapes::getShapeParameters(fstream& fileWithParams, Shapes* shape)
{
	fileWithParams.get();
	char* params = new char[2];
	int bytes = 0;
	params[bytes] = fileWithParams.get();
	bytes++;

	for (int i = 0; params[bytes] != '\n';)
	{
		params[bytes] = fileWithParams.get();

		if (params[bytes] != ' ' && params[bytes] != '\n')
		{
			bytes++;
			params = paramsMemory(params, bytes);
		}
		else
		{
			if (params[bytes] == '\n')
			{
				params[bytes] = '\0';
				shape->createParam(params, i);
				delete[] params;
				break;
			}

			params[bytes] = '\0';
			shape->createParam(params, i);
			params = bufferRelease(params, 1, bytes);
			i++;
		}
	}

	return;
}

char* Define_Shapes::paramsMemory(char* params, int nOfBytes)
{
	char* newParams = new char[nOfBytes+1];
	for (int j = 0; j < nOfBytes; j++)
	{
		newParams[j] = params[j];
	}

	delete[] params;
	return newParams;
}

void Define_Shapes::getTransVecParams(fstream& fileWithParams)
{
	char symb = ' ';
	char* coords = new char[1];
	int i = 0;
	int j = 0;
	symb = fileWithParams.get();

	while (symb != '\n')
	{
		symb = fileWithParams.get();
		if (symb != ' ' && symb != '\n')
		{
			coords[i] = symb;
			i++;
			coords = paramsMemory(coords, i);
		}
		else
		{
			coords[i] = '\0';
			transVecCoords[j] = atof(coords);

			if (symb == '\n')
			{
				delete[] coords;
				break;
			}

			coords = bufferRelease(coords, 1, i);
			j++;
		}
	}

	return;
}

Define_Shapes::~Define_Shapes()
{
	for (int i = 0; i < allShapesInFile-1; i++)
	{
		delete shapes[i];
	}

	delete[] shapes;
}