#include<iostream>
#include<cstring>
#include<fstream>
#include"Biscuit.h"


using namespace std;

const int biscuitPices = 3;
const int lengthOfPiece = 100;

Biscuit::Biscuit(char** pieces, int numOfPieces) : biscuit(NULL), biscuitPieces(0)
{
	int length = 0;
	biscuitPieces = numOfPieces;
	this->biscuit = new char*[biscuitPieces];
	for (int j = 0; j < numOfPieces; j++)
	{
		length = strlen(pieces[j]) + 1;

		this->biscuit[j] = new char[length];
	}

	for (int i = 0; i < numOfPieces; i++)
	{
		length = strlen(pieces[i]) + 1;
		strcpy_s(this->biscuit[i], length, pieces[i]);
	}
}

Biscuit& Biscuit::operator=(const Biscuit &other)
{
	if (this == &other)
	{
		return *this;
	}

	int length = 0;
	for (int i = 0; i < other.biscuitPieces; i++)
	{
		length = strlen(other.biscuit[i]) + 1;
		strcpy_s(this->biscuit[i], length, other.biscuit[i]);
		this->biscuitPieces = other.biscuitPieces;
		biscuit[i][length] = '\0';
	}

	return *this;
}

Biscuit::Biscuit() : biscuitPieces(biscuitPices)
{
	biscuit = new char*[biscuitPieces];
	for (int i = 0; i < biscuitPieces; i++)
	{
		biscuit[i] = new char[lengthOfPiece];
	}
}

void Biscuit::printBiscuit()
{
	for (int i = 0; i < biscuitPieces; i++)
	{
		cout << biscuit[i] << " ";
	}
}

void Biscuit::writeToBinary(ofstream& jarInf) const
{
	int length = 0;
	int i = 0;
	jarInf.write((const char*)&biscuitPieces, sizeof(biscuitPieces));
	for (; i < biscuitPieces; i++)
	{
		length = strlen(biscuit[i]);
		jarInf.write((const char*)&length, sizeof(length));
		jarInf.write((const char*)biscuit[i], sizeof(char)*length);
	}
}

void Biscuit::readFromBinary(ifstream& jarInf)
{
	int nOfPieces = 0;
	int lengthCurPiece = 0;
	jarInf.read((char*)&nOfPieces, sizeof(nOfPieces));
	for (int i = 0; i < nOfPieces; i++)
	{
		jarInf.read((char*)&lengthCurPiece, sizeof(int));
		jarInf.read(biscuit[i], sizeof(char)*lengthCurPiece);
		biscuit[i][lengthCurPiece] = '\0';
	}
}

Biscuit::~Biscuit()
{
	for (int i = 0; i < biscuitPieces; i++)
	{
		delete[] biscuit[i];
	}

	delete[] biscuit;
}