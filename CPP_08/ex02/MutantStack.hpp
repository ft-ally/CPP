#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <stack>

template <typename T>
class Mutant : public std::stack<T>
{
	public:
		Mutant();
		Mutant(const Mutant<T> &src);
		Mutant& operator=(const Mutant<T> &src);
		~Mutant();

		//returns iterator
		typedef typename std::stack<T>::iterator iterator;

		iterator begin();
		iterator end();

};

template <typename T>Mutant<T>::Mutant()
	: std::stack<T>
{}

template <typename T> Mutant<T>::Mutant(const Mutant &src) 
	: std::stack<T>(other)
{

}

template <typename T> Mutant<T>& Mutant<T>::operator=(const Mutant &src)
{

}


#endif