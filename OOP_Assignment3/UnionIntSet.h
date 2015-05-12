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
	int GetSize(){ return 0; };

	IIntSet* Union(IIntSet &other);


private:
	bool ContainsInBoth(int elem);
	IIntSet *first;
	IIntSet *second;

protected:
	int *ToArray(){ return 0; };
};

