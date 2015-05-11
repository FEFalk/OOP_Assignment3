#pragma once
#include "IIntSet.h"
#include "UnionIntSet.h"
#include <string>
#include <cstdlib>

class BasicIntSet: public IIntSet
{
public:
	BasicIntSet();
	BasicIntSet(int size);
	~BasicIntSet();

	void Add(int elem);
	bool Contains(int elem);
	char *ToString();
	
	IIntSet* Union(IIntSet &other);

private:
	void PushNumberAt(int elem, int index);
	int *basicSetArray;
	int size;
};

