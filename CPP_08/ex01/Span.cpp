#include "Span.hpp"


const char* Span::noMaxFoundException::what() const noexcept
{
	return "No max found!";
}

const char* Span::noSpanFoundException::what() const noexcept
{
	return "No span found!";
}

const char* Span::overLimitException::what() const noexcept
{
	return "Container is full!";
}

Span::Span() 
	:_nMax(0)
{}

Span::Span(unsigned int N)
	:_nMax(N)
{
	_v.reserve(N);
}

Span::Span(const Span &src)
{
	if (!_v.empty())
		_v.clear();
	_nMax = src._nMax;
	std::copy(src._v.begin(), src._v.end(), std::back_inserter(_v));
}

Span& Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_nMax = src._nMax;
		if (!_v.empty())
			_v.clear();
		std::copy(src._v.begin(), src._v.end(), std::back_inserter(_v));
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v.size() >= _nMax)
		throw overLimitException();
	_v.push_back(n);
	std::cout << "Addded " << n << " to vector. Span size: " << _v.size() << std::endl;
}



size_t Span::shortestSpan()
{
	size_t shortest = UINT_MAX;
	int diff = 0;
	
	if (_v.size() < 2)
		throw noSpanFoundException();
	int prev = _v.front();
	for (auto it = _v.begin() + 1; it != _v.end(); ++it)
	{
		diff = abs(prev - *it);
		if (static_cast<unsigned int>(diff) < shortest)
			shortest = static_cast<unsigned int>(diff);
		prev = *it;
	}
	return shortest;
}

size_t Span::longestSpan()
{
	size_t longest = 0;
	int diff = 0;
	if (_v.size() <2)
		throw noSpanFoundException();
	int prev = _v.front();

	for (auto it = _v.begin() + 1; it != _v.end(); ++it)
	{
		diff = abs(prev - *it);
		if (static_cast<unsigned int>(diff) > longest)
			longest = static_cast<unsigned int>(diff);
		prev = *it;
	}
	return longest;
}
