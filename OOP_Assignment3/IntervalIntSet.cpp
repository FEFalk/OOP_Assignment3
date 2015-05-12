#include "IntervalIntSet.h"


IntervalIntSet::IntervalIntSet()
{

}
IntervalIntSet::~IntervalIntSet()
{

}

void IntervalIntSet::Add(int elem)
{
	auto it = intervalArray.begin();

	for (; it != intervalArray.end(); ++it)
	{
		//Om elem finns inom någon intervall, break
		if (Contains(elem, it-intervalArray.begin()))
			break;
		


		//Om elem är precis bakom start så ändrar vi intervallets start-punkt
		if (elem == it->start - 1)
		{
			it->start = elem;
			break;
		}

		//Om elem är mindre än start-punkten 
		else if (elem < it->start)
		{
			intervalArray.insert(it, Interval(elem, elem));
			break;
		}

		//Om elem är precis framför destination så ändrar vi intervallets slut-punkt
		else if (elem == it->destination + 1)
		{
			if (it != intervalArray.end()-1){
				if (elem == (it + 1)->start - 1)
				{
					MergeIntervals(it);
				}
			}
			else
			{
				it->destination = elem;
			}
			break;
		}
	}
	if (it == intervalArray.end())
		intervalArray.push_back(Interval(elem, elem));
}

bool IntervalIntSet::Contains(int elem)
{
	//If "elem" exists in-between an interval, return true
	for (unsigned i = 0; i < intervalArray.size(); i++)
	{
		if (Contains(elem, i))
			return true;
	}
	return false;
}

bool IntervalIntSet::Contains(int elem, int index)
{
	return (elem > intervalArray[index].start && elem <= intervalArray[index].destination);
}

void IntervalIntSet::MergeIntervals(std::vector<Interval>::iterator it)
{
	it->destination = (it + 1)->destination;
	intervalArray.erase(it+1);
}

char *IntervalIntSet::ToString()
{
	std::string newString;
	
	
	for (unsigned i = 0; i < intervalArray.size(); i++)
	{
		newString.append("[");
		newString.append(std::to_string(intervalArray[i].start));
		newString.append("..");
		newString.append(std::to_string(intervalArray[i].destination));
		newString.append("] ");
	}

	char *ret= new char[newString.size()+1];
	stdext::checked_array_iterator<char *> chkd_test_array(ret, newString.size()+1);
	std::copy(newString.begin(), newString.end(), chkd_test_array);
	chkd_test_array[newString.size()] = '\0';

	return ret;
}

IIntSet *IntervalIntSet::Union(IIntSet &other)
{
	return &other;
}

int *IntervalIntSet::ToArray()
{
	int j = 0;
	int *newArray = new int[];
	for (unsigned  i = 0; i < intervalArray.size(); i++)
	{
		for (int n = intervalArray[i].start; n <= intervalArray[i].destination; n++)
		{
			j++;
			newArray = (int *)realloc(newArray, sizeof(int)*j);
			newArray[j-1] = n;
			individualSize = j;
		}
	}
	return newArray;
}

int IntervalIntSet::GetSize()
{
	return individualSize;
}