#include<iostream>
#include<cstring>
#include<fstream>
#include"Biscuit.h"
#include"Jar.h"

using namespace std;
const int lengthOfPiece = 100;
const int biscuitPices = 3;
Jar::Jar(ifstream& jarInf) : count(0), capacity(1), biscuits(NULL)
{
	Biscuit biscuit;

	jarInf.open("jar.dat", ios::in);

	if (!jarInf)
	{
		cout << "Empty JAR!\n";
		return;
	}

	while (!jarInf.eof())
	{
		biscuit.readFromBinary(jarInf);
		if (!jarInf.eof())
		{
			addBiscuit(biscuit);
		}
	}

	jarInf.close();
}

void Jar::printBiscuits()
{
	if (count)
	{
		for (int i = 0; i < count; i++)
		{
			biscuits[i].printBiscuit();
			cout << endl;
		}

		cout << endl;
	}
	else
	{
		cout << "Empty JAR!";
	}
}

Jar Jar::addBiscuit(const Biscuit& biscuit)
{
	if (count == 0)
	{
		biscuits = new Biscuit[capacity + 1];
	}

	if (count < capacity)
	{
		biscuits[count] = biscuit;
		++count;
	}
	else
	{
		Biscuit* arr = new Biscuit[capacity * 2];
		for (int i = 0; i < capacity; i++)
		{
			arr[i] = biscuits[i];
		}

		arr[capacity] = biscuit;
		count++;
		capacity *= 2;
		delete[] biscuits;
		biscuits = arr;
	}

	return *this;
}

void Jar::writeToBin()
{
	ofstream jarInf;
	jarInf.open("jar.dat", ios::out | ios::binary);
	if (!jarInf)
	{
		return;
	}

	for (int i = 0; i < count; i++)
	{
		biscuits[i].writeToBinary(jarInf);
	}

	jarInf.close();
}

void Jar::eatBiscuit()
{
	count--;
	if (count<0)
	{
		count = 0;
	}
}

Jar::~Jar()
{
}