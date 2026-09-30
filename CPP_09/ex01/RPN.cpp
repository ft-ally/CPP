#include "RPN.hpp"

RPN::RPN() : _s() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN& RPN::operator=(const RPN &src) {
	if (this != &src)
		_s = src._s;
	return *this;
}

RPN::~RPN() {}

bool RPN::checkNum(char c) {
	return (c >= '0' && c <= '9');
}

bool RPN::checkSign(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}


void RPN::operation(char operand) {
	if (_s.size() < 2)
		throw std::runtime_error("Error, bad input\n");
	int last = _s.top();
	_s.pop();

	int first = _s.top();
	_s.pop();
	
	switch(operand) {
		case '+': _s.push(first + last); break;
		case '-': _s.push(first - last); break;
		case '*': _s.push(first * last); break;
		case '/':
			if (last == 0)
				throw std::runtime_error("Error, bad input\n");
			_s.push(first / last); break;
	}
	
}

RPN::RPN(std::string line) {
	for (char c : line) {
		if (c == ' ')
			continue;
		else if (checkNum(c))
			_s.push(c - '0');
		else if (checkSign(c))
			operation(c);
		else
			throw std::runtime_error("Error, bad input\n");
	}
	if (_s.size() == 1)
		std::cout << _s.top() << std::endl;
	else
		throw std::runtime_error("Error, bad input\n");
}
