#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN {
	private:
		std::stack<int> _s;
	
	public:
		RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
		~RPN();

		RPN(std::string line);
		bool checkNum(char c); //must be 0-9
		bool checkSign(char c);// must be + - / *
		void operation(char operand);
}; 

#endif
