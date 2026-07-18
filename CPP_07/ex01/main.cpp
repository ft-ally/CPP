
#include "iter.tpp"
#include "Book.hpp"
#include "Colors.hpp"

static void addBookDiscount(Book &book)
{
	book.addDiscount();
}

static void printBook(Book &book)
{
	std::cout << "Book title: " << book.getName()
	<< " Book price: " << book.getPrice() << std::endl;
}

static void addTen(int &x)
{
	x += 10;
	std::cout << "Added 10 to element" << std::endl;
}

static void printChar(const char &c)
{
	std::cout << c << std::endl;
}

static void printInt(const int &i)
{
	std::cout << i << std::endl;
}

int main()
{
	const size_t size = 5;
	int intArr[size] = {1, 2, 3, 4, 5};
	char charArr[size] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << PURPLE << "====TEST 1: Int array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter to print every element, const overload" << RESET << std::endl;
	iter(static_cast<const int*>(intArr), size, printInt);
	std::cout << CYAN << std::endl << "Test: use iter to add 10 to each element" << RESET << std::endl;
	iter(intArr, size, addTen);
	std::cout << CYAN << std::endl << "Test: use iter to print every element, const overload" << RESET << std::endl;
	iter(static_cast<const int*>(intArr), size, printInt);

	std::cout << std::endl << PURPLE << "====TEST 2: Char array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter to print every element, const overload" << RESET << std::endl;
	iter(static_cast<const char*>(charArr), size, printChar);
	
	std::cout << PURPLE << std::endl << "====TEST 3: Shelf (array of book elements)====" << std::endl << RESET;
	Book shelf[size];
	
	for (int i = 0; i < 5; i++)
		shelf[i] = Book(i + 1);

	std::cout << CYAN << "Test: use iter to print every Book, const overload" << std::endl << RESET;
	iter(shelf, size, printBook);
	
	std::cout << std::endl << CYAN << "Test: use iter to add a discount to every book" << std::endl << RESET;
	iter(shelf, size, addBookDiscount);

	std::cout << std::endl << CYAN <<"Test: use iter to print every Book, const overload" << std::endl << RESET;
	iter(shelf, size, printBook);

}