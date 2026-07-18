#ifndef BOOK_HPP
#define BOOK_HPP

#include "iostream"

class Book {
	private:
	std::string _name;
	int			_price;

	public:
	Book();
	Book(int i);
	~Book();
	Book(const Book &src);
	Book &operator=(const Book &src);
	std::string getName() const;
	int getPrice() const;
	void addDiscount();
};



#endif