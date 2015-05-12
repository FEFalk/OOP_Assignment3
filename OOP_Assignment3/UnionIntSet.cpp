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

bool UnionIntSet::ContainsInBoth(int elem)
{
	if (first->Contains(elem) && second->Contains(elem))
		return true;

	return false;
}

IIntSet *UnionIntSet::Union(IIntSet &other)
{
	return new UnionIntSet((IIntSet *)this, &other);
}

char *UnionIntSet::ToString()
{
	std::string newString;
	int *unionArray=ToArray();
	for (int i = 0; first->GetSize() + second->GetSize();i++)
	{
		newString.append(std::to_string(unionArray[i]));
		newString.append(", ");
	}

	char *ret = new char[newString.size() + 1];
	stdext::checked_array_iterator<char *> chkd_test_array(ret, newString.size() + 1);
	std::copy(newString.begin(), newString.end(), chkd_test_array);
	chkd_test_array[newString.size()] = '\0';

	return ret;
}

int *UnionIntSet::ToArray()
{
	int *firstArray = first->ToArray();
	int *secondArray = second->ToArray();

	int *newArray = new int[first->GetSize() + second->GetSize()];

	int i = 0, j = 0;

	while (i != first->GetSize() || j != second->GetSize())
	{
		if (firstArray[i] <= secondArray[j] && i<first->GetSize())
		{
			newArray[i + j] = firstArray[i];
			i++;
		}
		else if (!ContainsInBoth(secondArray[j]))
		{
			newArray[i + j] = secondArray[j];
			j++;
		}
		else
			j++;
	}
}