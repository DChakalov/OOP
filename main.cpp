#include"Define_Shapes.h"
#include<iostream>

using namespace std;

int main()
{
	double pointX, pointY;
	cout << "Enter coords:"<< endl;
	cin >> pointX;
	cin >> pointY;
	
	Define_Shapes shapesWithPointInside(pointX, pointY);
}
