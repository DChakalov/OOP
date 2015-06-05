#ifndef BISCUIT_H
#define	BISCUIT_H
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Biscuit
{
private:
	char** biscuit;
	int biscuitPieces;
public:
	Biscuit();
	Biscuit(char**, int);
	Biscuit& Biscuit::operator=(const Biscuit&);
	void printBiscuit();
	~Biscuit();
	void writeToBinary(ofstream&) const;
	void readFromBinary(ifstream&);
};

#endif