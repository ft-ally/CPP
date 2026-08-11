#ifndef MUTANT_STACK
#define MUTANT_STACK

class Mutant
{
	public:
		Mutant();
		Mutant(const Mutant &src);
		Mutant& operator=(const Mutant &src);
		~Mutant();
};

#endif