#include <iostream>
#include <ctime>
#include <random>
#include <chrono>

int main(int argc, char const *argv[]) {

    if(argc != 2) {
		std::cerr << "Usage:\n\t" << argv[0] << " number\n\n";
		return 1;
	}

	int number_of = std::stoi(argv[1]);
    unsigned n = number_of * 5;

    for(int i = 0; i < number_of; i++) {
        n -= (rand()%2) + (rand()%3);
        if(n <= 0) n = 1;
        std::cout << n << std::endl;
        //n -= (rand()%2) + 3;
    }
	return 0;
}