#pragma once
#include "IIntSet.h"
#include "Structs.h"
#include <iterator>
#include <string>
#include <vector>


class IntervalIntSet : public IIntSet
{
public:
	IntervalIntSet();
	~IntervalIntSet();

	void Add(int elem);
	bool Contains(int elem);
	bool Contains(int elem, int index);
	void MergeIntervals(std::vector<Interval>::iterator it);
	char *ToString();
	

	IIntSet* Union(IIntSet &other);

private:
	std::vector<Interval> intervalArray;

protected:
	int *ToArray();
};

