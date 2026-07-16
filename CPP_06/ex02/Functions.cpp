#include "Functions.hpp"

Base *generate(void)
{
	int randNum = rand() % 3;
	if (randNum == 0)
		return new A();
	else if (randNum == 1)
		return new B();
	else
		return new C();
}


void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Type: A" <<std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "Type: B" <<std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "Type: C" <<std::endl;
		return;
	}
}

void identify(Base &p)
{
	try 
	{
		A cast = dynamic_cast<A&>(p);
		std::cout << "Type: A" <<std::endl;
		return;
	}
	catch (std::bad_cast &e)
	{}
	try
	{
		B cast = dynamic_cast<B&>(p);
		std::cout << "Type: B" <<std::endl;
		return;
	}
	catch (std::bad_cast &e)
	{}
	try
	{
		C cast = dynamic_cast<C&>(p);
		std::cout << "Type: C" <<std::endl;
		return;
	}
	catch (std::bad_cast &e)
	{}
}