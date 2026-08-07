#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	
	private:
		unsigned int			_n;
		std::vector<int>		_v;

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
};

Span::Span() {}

Span::Span(unsigned int n)
	:_n(n)
{
	_v.insert(_v.begin(), static_cast<size_t>(n), '0');
}

Span::Span(const Span &src)
{
	
}
#endif