#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define PINK "\033[95m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		const char *what() const noexcept override;
};


const char* NotFoundException::what() const noexcept
{
	return "Occurence not found";
}

template <typename T> typename T::iterator easyfind(T &container, int n)
{
	auto it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif