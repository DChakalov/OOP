#include<iostream>
#include<cstring>
#include"Biscuit.h"
#include"Jar.h"
using namespace std;

const int biscuitPices = 3;
const int lengthOfPiece = 100;
enum choices{ END, EAT_BISCUIT, ADD_BISCUIT };
void CreateThenAdd(Jar& jar);

int main()
{
	ifstream jarInf;
	Jar jar(jarInf);

	int choice = 0;

	cout << "2 - Add Coockie\n"
		<< "1 - Eat Coockie\n"
		<< "0 - Update Jar\n\n";

	cout << "Enter choice:";
	cin >> choice;

	while (choice >= END && choice <= ADD_BISCUIT && cin)
	{
		switch (choice)
		{
			case END: jar.writeToBin(); return 0;
			case EAT_BISCUIT: jar.eatBiscuit(); break;
			case ADD_BISCUIT: CreateThenAdd(jar); break;
		}

		cout << "\nEnter choice:";
		cin >> choice;
	}
}

void CreateThenAdd(Jar& jar)
{
	char** multiArr = new char*[biscuitPices];
	for (int i = 0; i < biscuitPices; i++)
	{
		multiArr[i] = new char[lengthOfPiece];
		cin >> multiArr[i];
	}

	Biscuit biscuit(multiArr, biscuitPices);
	jar.addBiscuit(biscuit);

	for (int i = 0; i < biscuitPices; i++)
	{
		delete[] multiArr[i];
	}

	delete[] multiArr;
}