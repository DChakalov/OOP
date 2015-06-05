#include<iostream>
#include<cstring>
#include<fstream>
#include"Biscuit.h"
using namespace std;

class Jar
{
private:
	int count;
	int capacity;
	Biscuit* biscuits;
public:
	Jar(ifstream& jarInf);
	~Jar();
	Jar addBiscuit(const Biscuit&);
	void printBiscuits();
	void eatBiscuit();
	void writeToBin();
};
