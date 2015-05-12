#pragma once
#include "IIntSet.h"
#include <string>

class UnionIntSet : public IIntSet
{
public:
	UnionIntSet(IIntSet *first, IIntSet *second);
	~UnionIntSet();

	void Add(int elem);
	bool Contains(int elem);
	char *ToString();

	IIntSet* Union(IIntSet &other);

protected:
	int *ToArray();

private:
	IIntSet *first;
	IIntSet *second;
};

