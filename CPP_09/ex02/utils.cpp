
void validateInput(int argc, char **argv) {
	if (argc < 2)
			throw std::runtime_error("Error, no input\n");
	for (int i = 1; i < argc; i++) {
		try {
			int num = std::stoi(argv[i]);
			
		} catch (const std::exception& e) {
			throw std::runtime_error(std::string("Error, bad input\n"));
		}
	}
}

void convertInput(int argc, char**argv, std::vector<int> &v, std::deque<int> &d) {
	for (int i = 1; i < argc; i++) {
		int num = std::stoi(argv[i]);
		v.push_back(num);
		d.push_back(num);
	}
}
