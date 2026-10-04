#include "PmergeMe.hpp"
#include "Colors.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>

void describe(const std::string &description) {
	std::cout << "\n✓ " << description << std::endl;
}

void it(const std::string& testName, bool condition, const std::string& errorMsg = "") {
	if (condition) {
		std::cout << GREEN << "PASS: " << testName << std::endl;
	} else {
		std::cout << RED << "FAIL: " << testName << " - " << errorMsg << std::endl;
		assert(false);
	}
}


// ============ TESTS ============

void testVectorContainer() {
	
}

void testDequeContainer() {
	describe("PmergeMe with std::deque<int>");
	
}

void testDuplicates() {
	describe("PmergeMe with duplicates");
}

int main() {
	std::cout << "========== PMERGEME TESTS ==========" << std::endl;
	
	try {
		testVectorContainer();
		testDequeContainer();
		testDuplicates();
		
		std::cout << "\n========== ALL TESTS PASSED ==========" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
