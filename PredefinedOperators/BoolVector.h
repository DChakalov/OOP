#ifndef BOOLVECTOR_H
#define BOOLVECTOR_H

class BoolVector
{
	public:
		BoolVector(): vector(0), length(32) {}
		BoolVector(int*, int);
		~BoolVector();
		int operator[](int) const;
		bool set(int);
		bool clear(int);
		int findMember(int) const;
	private:
		int vector;
		short length;
};

#endif