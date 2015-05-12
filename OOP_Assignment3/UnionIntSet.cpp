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
void UnionIntSet::Add(int elem)
{
	//We want to add to both because of Union. So when separated they still contain the new elem.
	if (Contains(elem))
	{
		first->Add(elem);
		second->Add(elem);
	}
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
	int *firstArray = first->ToArray();
	int *secondArray = second->ToArray();
	int i=0, j=0;

	while (i!=first->GetSize() || j!=second->GetSize())
	{
		if (firstArray[i] <= secondArray[j] && i<first->GetSize())
		{
			newString.append(std::to_string(firstArray[i]));
			newString.append(", ");
			i++;
		}
		else if (!ContainsInBoth(secondArray[j]))
		{
			newString.append(std::to_string(secondArray[j]));
			newString.append(", ");
			j++;
		}
		else
			j++;
	}
	first->ToArray();

	char *ret = new char[newString.size() + 1];
	stdext::checked_array_iterator<char *> chkd_test_array(ret, newString.size() + 1);
	std::copy(newString.begin(), newString.end(), chkd_test_array);
	chkd_test_array[newString.size()] = '\0';

	return ret;
}