#include "BasicIntSet.h"

BasicIntSet::BasicIntSet()
{
	basicSetArray = NULL;
}

BasicIntSet::BasicIntSet(int size)
{
	basicSetArray = (int *) realloc(basicSetArray, size * sizeof(int));
}

BasicIntSet::~BasicIntSet()
{
	delete basicSetArray;
}

void BasicIntSet::Add(int elem)
{
	if (!Contains(elem))
	{
		size++;
		basicSetArray = (int *) realloc(basicSetArray, size * sizeof(int));
		basicSetArray[size - 1] = 0;
	}
	else
		return;

	for (int i = 0; i < size; i++)
	{
		//Om vi nått slutet av arrayen
		if (i == size-1)
		{
			//Om arrayen är tom
			if (basicSetArray[size-1]==0 && size==1)
				basicSetArray[size-1] = elem;
			//Om elem ska sättas in före eller efter
			else if (elem>basicSetArray[size - 2])
				basicSetArray[size-1] = elem;
			else
				PushNumberAt(elem, size - 2);
			break;
		}
				
		if (elem > basicSetArray[i] && elem < basicSetArray[i + 1])
		{
			PushNumberAt(elem, i + 1);
		}
	}
}

bool BasicIntSet::Contains(int elem)
{
	for (int i = 0; i < size; i++)
	{
		if(basicSetArray[i] == elem)
			return true;
	}
	return false;
}

void BasicIntSet::PushNumberAt(int elem, int index)
{
	for (int i = size-1; i > index; i--)
	{
		basicSetArray[i] = basicSetArray[i - 1];
	}
	basicSetArray[index] = elem;
}

char *BasicIntSet::ToString()
{
	std::string newString;


	for (int i = 0; i < size; i++)
	{
		newString.append(std::to_string(basicSetArray[i]));
		if (i!=size-1)
			newString.append(", ");
	}

	char *ret = new char[newString.size() + 1];
	stdext::checked_array_iterator<char *> chkd_test_array(ret, newString.size() + 1);
	std::copy(newString.begin(), newString.end(), chkd_test_array);
	chkd_test_array[newString.size()] = '\0';

	return ret;
}

int *BasicIntSet::ToArray()
{
	return basicSetArray;
}

IIntSet *BasicIntSet::Union(IIntSet &other)
{
	return new UnionIntSet((IIntSet *)this, &other);
}

int BasicIntSet::GetSize()
{
	return size;
}