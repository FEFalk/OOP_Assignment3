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
	int *firstArray = first->ToArray();
	int *secondArray = second->ToArray();
	int i, j;

	while (firstArray[i] != 0 && secondArray[j] != 0)
	{
		if (firstArray[i] >= secondArray[j]){
			newString.append(std::to_string(firstArray[i]));
			newString.append(", ");
			i++;
		}
		else
		{
			newString.append(std::to_string(secondArray[j]));
			newString.append(", ");
			j++;
		}
	}

	char *ret = new char[newString.size() + 1];
	stdext::checked_array_iterator<char *> chkd_test_array(ret, newString.size() + 1);
	std::copy(newString.begin(), newString.end(), chkd_test_array);
	chkd_test_array[newString.size()] = '\0';

	return ret;
}

int *UnionIntSet::ToArray()
{

}