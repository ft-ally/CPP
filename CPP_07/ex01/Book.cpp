#include "Book.hpp"


Book::Book(){ }

Book::~Book() {}

Book::Book(const Book &src)
{

}

Book &Book::operator=(const Book &src)
{

}

std::string Book::getName() const{
	return _name;
}


int Book::getPrice() const {
	return _price;
}