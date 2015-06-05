#include<iostream>
#include"DoubleVector.h"
#include"BoolVector.h"
using namespace std;

const int n = 3;
int main()
{
	double* doubleVector = new double[n];
	//int* boolVector = new int[n];
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> boolVector[i];
	//}

	//BoolVector boolV(boolVector, n);
	//boolV.set(3);
	//boolV.clear(5);

	for (int j = 0; j < n; j++)
	{
		cin >> doubleVector[j];
	}
	
	
	DoubleVector doubleV(doubleVector, n);
	DoubleVector secondV(doubleVector, n);
	doubleV.add(secondV);
	/*doubleV -= secondV;
	doubleV %= secondV;
	doubleV *= 5;
	doubleV /= 5;*/
	doubleV.print();

	return 0;
}