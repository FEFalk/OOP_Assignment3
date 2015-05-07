#pragma once
#include "IIntSet.h"
#include <cstdlib>

class BasicIntSet:IIntSet
{
public:
	BasicIntSet();
	BasicIntSet(int size);
	~BasicIntSet();

	void Add(int elem);
	bool Contains(int elem);

private:
	int *BasicSetArray;
	int size;
};

