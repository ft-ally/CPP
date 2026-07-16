#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:
	std::string _str;

	public:
	Data() = delete;
	Data(std::string str);
	Data(const Data &src);
	Data &operator=(const Data &src);
	~Data();

	std::string getString() const;
};

#endif

