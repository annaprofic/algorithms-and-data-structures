#include <iostream>
#include <chrono>
#include <random>
#include <ctime>


int main(int argc, const char *argv[]) {
    
    srand(time(NULL));
    
	if(argc != 2) {
		std::cerr << "Usage:\n\t" << argv[0] << " number maximal\n\n";
		return 1;
	}

	int number_of = std::stoi(argv[1]);
    unsigned n = 0;
    
    for (int i = 0; i < number_of - 1; i++) {
        n += (rand()%3) + 1;
        std::cout << n << std::endl;
        n += (rand()%3) + 4;
    }
    std::cout << rand() % 1000 << std::endl;
	return 0;
}