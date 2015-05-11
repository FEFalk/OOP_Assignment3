#include "UnionIntSet.h"


UnionIntSet::UnionIntSet(IIntSet *first, IIntSet *second)
{
	this->first = first;
	this->second = second;
}


UnionIntSet::~UnionIntSet()
{
}


bool UnionIntSet::Contains(int elem)
{
	if (first->Contains(elem) || second->Contains(elem))
		return true;

	return false;
}

char *UnionIntSet::ToString()
{
	std::string newString;

	newString.append(first->ToString);
	newString.append(second->ToString);

	for (int i = 0; i < intervalArray.size(); i++)
	{
		if (first->Contains)
		newString.append("[");
		newString.append(std::to_string(intervalArray[i].start));
		newString.append("..");
		newString.append(std::to_string(intervalArray[i].destination));
		newString.append("] ");
	}

	char *ret = new char[newString.size() + 1];
	stdext::checked_array_iterator<char *> chkd_test_array(ret, newString.size() + 1);
	std::copy(newString.begin(), newString.end(), chkd_test_array);
	chkd_test_array[newString.size()] = '\0';

	return ret;
}