#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "cstdlib"

Base *generate(void)
{
	int randNum = rand();
	if (randNum % 3 == 0)
		return new C();
	else if (randNum % 2 == 0)
		return new B();
	else
		return new A();
}

void identify(Base *p)
{
	
}

void identify(Base &p)
{
	
}