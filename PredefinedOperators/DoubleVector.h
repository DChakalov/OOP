#ifndef DoubleVector_H
#define DoubleVector_H
#include<iostream>

class DoubleVector
{
	public:
		DoubleVector() : vector(NULL), size(0) {};
		DoubleVector(const DoubleVector&);
		DoubleVector(double*, int);
		~DoubleVector();
		
		DoubleVector& operator=(DoubleVector&);
		DoubleVector& operator+=(DoubleVector&);
		DoubleVector& operator-=(DoubleVector&);
		DoubleVector& operator%=(DoubleVector&);
		DoubleVector& operator/=(int);
		DoubleVector& operator*=(int);
		double operator[](int)const;
		DoubleVector add(DoubleVector&);
		DoubleVector operator+(DoubleVector&);
		DoubleVector operator-(DoubleVector&);
		DoubleVector operator/(int);
		DoubleVector operator*(int);
		DoubleVector operator%(DoubleVector&);

		void resize(DoubleVector&, int);
		void shouldResize(DoubleVector&);
		double* copy(double*, int, double*);
		DoubleVector make(DoubleVector&, char, int = 1);								
		void print()const;

	private:
		double* vector;
		int size;
};

#endif
