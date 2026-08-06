#include "Array.hpp"

#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define RED "\033[31m"

#define RESET "\033[0m"

int main()
{
	unsigned int size = 5;
	Array<int> *arrayA = new Array<int>(size);
		std::cout << PURPLE << "===Test: Create Int Array===" << RESET << std::endl;
		std::cout << "Contents of Array A: " << std::endl;
		
	try {
		(*arrayA).getArray();
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "Size of Array A: " << (*arrayA).size() << std::endl;
	try {
		std::cout << "Array A, index 1: " << (*arrayA)[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try { 
		std::cout << "Array A, index 8: " << (*arrayA)[8] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "Array A, index -2: " << (*arrayA)[-2] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	delete arrayA;

	std::cout << std::endl << PURPLE << "===Test: Create string array===" << RESET << std::endl;
	Array<std::string> *arrayB = new Array<std::string>(size);
	try {
		std::cout << "Contents of Array B: " << std::endl;
		(*arrayB).getArray();
	}
	catch (std::exception &e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "Size of Array B: " << (*arrayB).size() << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "Array B, index 2: " << (*arrayB)[2] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "Array B, index 12: " << (*arrayB)[12] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "Array B, index -12: " << (*arrayB)[-12] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	delete arrayB;
	
	std::cout << std::endl << PURPLE << "==Test: Construction with no parameter==" << RESET << std::endl;
	Array<char> *arrayC = new Array<char>();
	try {
		std::cout << "Contents of Array C: " << std::endl;
		(*arrayC).getArray();
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << "Size of Array C: " << (*arrayC).size() << std::endl;
	try {
		std::cout << "Array C, index 12: " << (*arrayC)[12] << std::endl;
	}
	catch (std::exception &e){ 
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	//Add test for copy operator
}