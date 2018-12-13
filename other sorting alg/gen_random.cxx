/* 
 * Copyright (C) Andrzej Görlich <agoerlich@netmail.if.uj.edu.pl> - All Rights Reserved
 * Compilation: g++ -std=c++11 -O2 -o genRandom.x genRandom.cxx
 */

#include <iostream>
#include <string>
#include <random>
#include <chrono>

auto main(int argc, char const *argv[]) -> int
{
	if(argc != 3) {
		std::cerr << "Usage:\n\t" << argv[0] << " number maximal\n\n";
		return 1;
	}

	auto number	 = std::stoi(argv[1]);
	auto maximal = std::stoi(argv[2]);

	if((number <= 0) || (maximal <= 1)) {
		std::cerr << "Arguments out of range\n\n";
		return 1;
	}

//	std::default_random_engine generator(
//		std::chrono::system_clock::now().time_since_epoch().count());

	std::random_device rd;  										// "True" random number as seed
	std::default_random_engine generator{rd()};
	std::uniform_int_distribution<int> distribution(1, maximal);

	for (auto i = 0; i < number; i++)
		std::cout << distribution(generator) << std::endl;

	return 0;
}
