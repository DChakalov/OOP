#include"DoubleVector.h"
#include<iostream>

DoubleVector::DoubleVector(double* vectorParts, int allElem) : vector(NULL), size(0)
{
	size = allElem;
	vector = new double[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = vectorParts[i];
	}
}

void DoubleVector::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->vector[i] << std::endl;
	}
}

double DoubleVector::operator[](int index) const
{
	if (index < size && index > 0)
	{
		return vector[index];
	}

	return 0;
}

DoubleVector DoubleVector::operator+(DoubleVector& rightVec)
{
	shouldResize(rightVec);
	return make(rightVec, '+');
}

DoubleVector DoubleVector::operator-(DoubleVector& rightVec)
{
	shouldResize(rightVec);
	return make(rightVec, '-');
}

DoubleVector DoubleVector::make(DoubleVector& rightVec, char operNum, int num)
{
	DoubleVector newObject;
	newObject.size = this->size;
	newObject.vector = new double[newObject.size];

	int i = 0;
	for (i = 0; i < newObject.size; i++)
	{
		switch (operNum)
		{
			case '-': newObject.vector[i] = this->vector[i] - rightVec.vector[i]; break;
			case '+': newObject.vector[i] = this->vector[i] + rightVec.vector[i]; break;
			case '/': newObject.vector[i] = this->vector[i] / num; break;
			case '*': newObject.vector[i] = this->vector[i] * num; break;
			case '%': newObject.vector[i] = this->vector[i] * rightVec.vector[i]; break;
		}
	}

	return newObject;
}

DoubleVector DoubleVector::operator*(int num)
{
	return make(*this, '*', num);
}

DoubleVector DoubleVector::operator/(int num)
{
	return make(*this, '/', num);
}

DoubleVector DoubleVector::operator%(DoubleVector& rightVec)
{
	return make(rightVec, '%');
}

void DoubleVector::shouldResize(DoubleVector& rightVec)
{
	if (this->size > rightVec.size)
	{
		resize(rightVec, this->size);
	}
	else if (rightVec.size > this->size)
	{
		resize(*this, rightVec.size);
	}
}

void DoubleVector::resize(DoubleVector& resizedVec, int foreignSize)
{
	double* correct = new double[foreignSize];
	int i = 0;
	for (; i < resizedVec.size; i++)
	{
		correct[i] = resizedVec.vector[i];
	}
	for (; i < foreignSize; i++)
	{
		correct[i] = 0.0;
	}

	resizedVec.size = foreignSize;
	delete[] resizedVec.vector;
	resizedVec.vector = correct;
	correct = NULL;
}

DoubleVector::DoubleVector(const DoubleVector& rightVec)
{
	this->vector = copy(this->vector, rightVec.size, rightVec.vector);
	this->size = rightVec.size;
}

double* DoubleVector::copy(double* leftVector, int sizeRight,  double* rightVector)
{
	
	leftVector = new double[sizeRight];
	for (int i = 0; i < sizeRight; i++)
	{
		leftVector[i] = rightVector[i];
	}

	return leftVector;
}

DoubleVector& DoubleVector::operator=(DoubleVector& rightVec)
{
	if (this == &rightVec)
	{
		return *this;
	}

	delete[] this->vector;
	this->vector = copy(this->vector, rightVec.size, rightVec.vector);
	this->size = rightVec.size;
	return *this;
}

DoubleVector& DoubleVector::operator+=(DoubleVector& rightVec)
{
	return *this = *this + rightVec;
}

DoubleVector& DoubleVector::operator-=(DoubleVector& rightVec)
{
	return *this = *this - rightVec;
}

DoubleVector& DoubleVector::operator*=(int num)
{
	return *this = *this * num;
}

DoubleVector& DoubleVector::operator/=(int num)
{
	return *this = *this / num;
}

DoubleVector& DoubleVector::operator%=(DoubleVector& rightVec)
{
	return *this = *this % rightVec;
}

DoubleVector::~DoubleVector()
{
	delete[] vector;
}

DoubleVector DoubleVector::add(DoubleVector& right)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] += right.vector[i];
	}

	return *this;
}

