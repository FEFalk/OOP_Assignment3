

class IIntSet
{
public:
	/* The constructor */
	IIntSet() {}

        /* Returns whether this set includes the element 'elem' or not. */
        bool Contains(int elem) = 0;

        /* Add the element 'elem' to this set. After the call, Contains(elem) will
         * return true. */
        void Add(int elem) = 0;

        /* Return a set that is the union of this set and 'other'. All elements contained
         * in either this set or in 'other' will be contained in the resulting set. */
        IIntSet* Union(IIntSet &other);

        /* Return an array of integers that contains all the individual values in this set. */
        char* ToString();

};


void main()
{
	IIntSet *s1 = new BasicIntSet();
        s1->Add(10);
        s1->Add(12);

        IIntSet *s2 = new IntervalSet();
        s2->Add(20);
        s2->Add(21);
        s2->Add(22);
        s2->Add(100);
        s2->Add(101);
        s2->Add(102);

	IIntSet *s3;
	s3 = s1.Union(s2); 


        cout << s3.ToString();
}

