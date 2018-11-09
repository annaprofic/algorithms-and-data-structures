/* 
 * Copyright (C) Andrzej Görlich <agoerlich@netmail.if.uj.edu.pl> - All Rights Reserved
 * Compilation: g++ -std=c++11 -O2 -o genList.x genList.cxx
 */
 
#include <iostream>
#include <string>
#include <random>

constexpr auto maximal = 1000000;

auto main(int argc, const char *argv[]) -> int {

	if(argc != 2) {
		std::cerr << "Please set ouput size\n";
		return 1;
	}

	auto number	 = std::stoi(argv[1]);								// Output size

	if(number <= 0) {
		std::cerr << "Incorrect ouput size\n";
		return 1;
	}

	std::random_device rd;  										// "True" random number as seed
	std::default_random_engine generator{rd()};
	std::uniform_int_distribution<> ranVal{1, maximal};
	std::uniform_real_distribution<> ranType{};

	std::cout << number << std::endl;
	for (auto i = 0; i < number; ++i)
	{
		auto x	= ranType(generator);

		if(x < 0.4)
			std::cout << "A " << ranVal(generator) << std::endl;	// 40% chance for add
		else if(x < 0.6)
			std::cout << "F " << ranVal(generator) << std::endl;	// 20% chance for find
		else if(x < 0.9)
			std::cout << "D\n";										// 30% chance for delete
		else
			std::cout << "S\n";										// 10% chance for size
	}

	return 0;
}
