#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <type_traits>

template <typename T>

class Array {
	private:
		T		*_arr;
		int _size;

	public:
		Array(); //create an empty array
		Array(unsigned int n); //create an array of n elements init by default
		Array(const Array &src);
		Array &operator=(const Array &src);
		~Array();

		T& operator[](int i) const;
		unsigned int size() const;
		void getArray() const;
		
		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

template <typename T> Array<T>::Array()
	:_arr(nullptr), _size(0)
{};

template <typename T> Array<T>::Array(unsigned int n)
	:_arr(new T[n]()), _size(static_cast<int>(n))
{
	for (unsigned int i = 0; i < n; i++)
	{
		if constexpr(std::is_same_v<T, std::string>)
			_arr[i] = std::string("str_") + std::to_string(i);
		else
			_arr[i] = static_cast<T>(rand() % n);
	}
}

template <typename T> Array<T>::Array(const Array &src)
{
	_arr = new T[src.size()];
	for (int i = 0; i < src.size(); i++)
		_arr[i] = src._arr[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] _arr;
		_arr = new T[src._size];

		for (int i = 0; i < src._size; i++)
			_arr[i] = src._arr[i];
	}
	return *this;
}

template <typename T> Array<T>::~Array()
{
	if (this->size())
		delete[] _arr;
}

template <typename T> unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T> T& Array<T>::operator[](int i) const
{
	if (i >= _size || i <= 0)
		throw OutOfBoundsException();
	else
		return _arr[i];
}

template <typename T> void Array<T>::getArray() const
{
	for (int i = 0; i < _size; i++)
	{
		std::cout << _arr[i] << std::endl;
	}
	if (!_size)
		std::cout << "Array is empty.. so sad" << std::endl;
}

template <typename T> const char* Array<T>::OutOfBoundsException::what() const noexcept
{
	return ("Index is out of bounds!");
}
#endif
	
	
	
	//https://www.youtube.com/watch?v=mQqzP9EWu58
	//c++ at cimpile time supplies 
//  You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.