#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	
	private:
		unsigned int		_nMax;
		std::vector<int>	_v;

	public:
		Span(); 
		Span(unsigned int n);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		
		void addNumber(int n); //add a single number to a span
		
		unsigned int shortestSpan();
		unsigned int longestSpan();
		

		class noSpanFoundException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		class overLimitException : public std::exception
		{
			public:
				const char *what() const noexcept override; 
		};

		class noMaxFoundException : public std::exception
		{
			public:
				const char *what() const noexcept override; 
		};
};

Span::Span() 
	:_nMax(0)
{}

Span::Span(unsigned int n)
	:_nMax(n)
{
	_v.reserve(n);
}

Span::Span(const Span &src)
{
	
}

void Span::addNumber(int n)
{
	if (!_nMax)
		throw noMaxFoundException();
	if (_v.size() >= _nMax)
		throw overLimitException();
	_v.push_back(n);
}

unsigned int Span::shortestSpan()
{
	int shortest = ;
	int diff = 0;
	int prev = _v.front();

	for (auto it = _v.begin() + 1; it != _v.end(); ++it)
	{
		diff = abs(prev - *it);
		if (diff < shortest)
			shortest = diff;
		prev = *it;
	}
}

unsigned int Span::longestSpan()
{

}
#endif