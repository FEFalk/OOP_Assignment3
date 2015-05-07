#include "BasicIntSet.h"

BasicIntSet::BasicIntSet()
{
	BasicSetArray = new int;
}
BasicIntSet::BasicIntSet(int size)
{
	realloc(BasicSetArray, size);
}

BasicIntSet::~BasicIntSet()
{
	delete BasicSetArray;
}

void BasicIntSet::Add(int elem)
{
	if (Contains)
	{
		size++;
		BasicSetArray[size] = elem;
	}
	

}
bool BasicIntSet::Contains(int elem)
{
	for (int i = 0; i < size; i++)
	{
		BasicSetArray[i] == elem;
		return true;
	}
	return false;
}