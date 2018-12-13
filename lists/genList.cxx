/* 
 * Copyright (C) Andrzej Görlich <agoerlich@netmail.if.uj.edu.pl> - All Rights Reserved
 * Compilation: g++ -std=c++11 -O2 -o genList.x genList.cxx
 */
 
#include <iostream>
#include <string>
#include <random>

constexpr auto maximal = 1000;

auto main(int argc, const char *argv[]) -> int {

	if(argc != 2) {
		std::cerr << "Missing ouput size\n";
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

		if(x < 0.2)
			std::cout << "F " << ranVal(generator) << std::endl;	// 20% chance for push_front()
		else if(x < 0.4)
			std::cout << "B " << ranVal(generator) << std::endl;	// 20% chance for push_back()
		else if(x < 0.6)
			std::cout << "C " << ranVal(generator) << std::endl;	// 20% chance for contains()
		else if(x < 0.7)
			std::cout << "f\n";										// 10% chance for pop_front()
		else if(x < 0.9)
			std::cout << "b\n";										// 20% chance for pop_back()
		else
			std::cout << "S\n";										// 10% chance for size
	}

	return 0;
}
