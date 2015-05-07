

class IIntSet
{
public:
	/* The constructor */
	IIntSet() {}

        /* Returns whether this set includes the element 'elem' or not. */
        virtual bool Contains(int elem) = 0;

        /* Add the element 'elem' to this set. After the call, Contains(elem) will
         * return true. */
        virtual void Add(int elem) = 0;

        /* Return a set that is the union of this set and 'other'. All elements contained
         * in either this set or in 'other' will be contained in the resulting set. */
        IIntSet* Union(IIntSet &other);

        /* Return an array of integers that contains all the individual values in this set. */
        char* ToString();
};
