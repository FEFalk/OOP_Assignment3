#include "UnionIntSet.h"


UnionIntSet::UnionIntSet(IIntSet *first, IIntSet *second)
{
	this->first = first;
	this->second = second;

	size = first->GetSize();
	int *secondArray = second->ToArray();

	for (int i = 0; i < second->GetSize(); i++)
	{
		if (!ContainsInBoth(secondArray[i]))
			size++;
	}
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
	if (!Contains(elem))
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

int UnionIntSet::GetSize()
{
	return size;
}

char *UnionIntSet::ToString()
{
	std::string newString;
	int *unionArray=ToArray();
	for (int i = 0; i < size; i++)
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

	int *newArray = new int[size];

	int i = 0, j = 0, n = 0;

	while (i < first->GetSize() || j < second->GetSize())
	{
		if (firstArray[i] <= secondArray[j] && i<first->GetSize())
		{
			newArray[n] = firstArray[i];
			i++;
			n++;
		}
		else if (!ContainsInBoth(secondArray[j]) && j<second->GetSize())
		{
			newArray[n] = secondArray[j];
			j++;
			n++;
		}
		else
			j++;
		
	}
	return newArray;
}