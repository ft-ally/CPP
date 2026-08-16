#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <limits.h>
#include <algorithm>
#include <iostream>
class Span {
	
	private:
		unsigned int		_nMax;
		std::vector<int>	_v;

	public:
		Span(); 
		Span(unsigned int N);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		
		void addNumber(int n);
		template <typename it> void addNumbers(it begin, it end);
	
		size_t shortestSpan();
		size_t longestSpan();
		

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

template <typename it> void Span::addNumbers(it begin, it end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

#endif