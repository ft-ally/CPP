#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
			: std::stack<T>() {};
		MutantStack(const MutantStack<T> &src)
			: std::stack<T>(src) {};
		MutantStack& operator=(const MutantStack<T> &src)
			{
				std::stack<T>::operator=(src);
				return *this;
			};
		~MutantStack() {};

		typedef typename std::deque<T>::iterator iterator;
		iterator begin() {
			return (this->c.begin());
		};
		iterator end() {
			return (this->c.end());
		};

};


#endif