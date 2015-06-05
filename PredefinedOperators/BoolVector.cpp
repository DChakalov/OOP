#include"BoolVector.h"
#include<iostream>

BoolVector::BoolVector(int* boolVector, int exLength) : vector(0), length(32)
{
	long long partsOfVector = 1;
	for (int i = 0; i < exLength; i++)
	{
		vector += (boolVector[i] * partsOfVector);
		partsOfVector *= 2;
	}
}

int BoolVector::operator[](int index) const
{
	if (!(index < length && index > 0)) return -1;
	return findMember(index);
}

bool BoolVector::clear(int index)
{
	if (!(index < length && index >0)) return false;
	if (findMember(index)) vector = (1<<index) ^ vector;
	
}

int BoolVector::findMember(int index) const
{
	short member = -1;
	int one = 1;
	int position = 1 << index;
	member = position & vector;
	member >>= index;

	return member;
}

bool BoolVector::set(int index)
{
	if (!(index < length && index > 0)) return false;
	int one = 1;
	int position = 1 << index;
	vector = vector | position;
	return true;
}

BoolVector::~BoolVector()
{
}
