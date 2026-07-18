#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class array_Template>

class Array {
	private:
		T*		_elements;

	public:
		Array(); //create an empty array
		Array(unsigned int n); //create an array of n elements init by default
		Array(const Array &src);
		Array&operator=(const Array *src);
		
		size_t size();
};

#endif


//  You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.