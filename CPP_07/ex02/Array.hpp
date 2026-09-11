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
		Array();
		Array(unsigned int n);
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
	_size = src._size;
	_arr = new T[_size];
	for (int i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] _arr;
		_arr = new T[src._size];
		_size = src._size;
		for (int i = 0; i < src._size; i++)
			_arr[i] = src._arr[i];
	}
	return *this;
}

template <typename T> Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T> unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T> T& Array<T>::operator[](int i) const
{
	if (i >= _size || i < 0)
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
