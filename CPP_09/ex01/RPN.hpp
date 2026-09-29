#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN {
	private:
		std::stack<int> _s;
	
	public:
		RPN(std::string line);
		bool checkNum(char c); //must be 0-9
		bool checkSign(char c);// must be + - / *
		void push(int n);
		void operation(char operand);
};

bool RPN::checkNum(char c) {
	return (c >= '0' && c <= '9');
}

bool RPN::checkSign(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::push(int n) {
	_s.push(n);
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
		if (checkNum(c))
			push(c - '0');
		else if (checkSign(c))
			operation(c);
	}
	if (_s.size() == 1)
		std::cout << _s.top() << std::endl;
	else
		throw std::runtime_error("Error, bad input\n");
}

#endif
