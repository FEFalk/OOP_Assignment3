#include <iostream>

#include "BasicIntSet.h"
#include "IntervalIntSet.h"
#include "UnionIntSet.h"

using namespace std;

void main()
{
	IIntSet *s1 = new BasicIntSet();
        s1->Add(10);
        s1->Add(12);
		s1->Add(20);

        IIntSet *s2 = new IntervalIntSet();
        s2->Add(20);
        s2->Add(21);
        s2->Add(22);
        s2->Add(100);
        s2->Add(101);
        s2->Add(102);

		IIntSet *s5 = new IntervalIntSet();
		s5->Add(20);
		s5->Add(21);
		s5->Add(22);
		s5->Add(3);
		s5->Add(1);
		s5->Add(5);

		cout << s2->ToString();
		cout << endl << s1->ToString() << endl;

	IIntSet *s3;
	s3 = s1->Union(*s2);

	IIntSet *s4;
	s4 = s3->Union(*s5);
	
	cout << s3->ToString() << endl;

	cout << s4->ToString() << endl;

	return;
}

