#include "Book.hpp"


Book::Book()
	:_name("Random book title"), _price(15)
{ }

Book::Book(int i)
	: _price(15)
{ 
	_name = "Random book title " + std::to_string(i);
}

Book::~Book() {}

Book::Book(const Book &src)
{
	this->_name = src._name;
	this->_price = src._price;
}

Book &Book::operator=(const Book &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_price = src._price;
	}
	return (*this);
}

std::string Book::getName() const{
	return _name;
}


int Book::getPrice() const {
	return _price;
}

void Book::addDiscount()
{
	_price -= 5;
	std::cout << "5eur discount added!" << std::endl;
}