#include <iostream>
#include <vector>
#include<iterator>
#include <algorithm> 
#include <chrono> 

void get_data(std::vector<int>& data) { 
    int el = 0;
	while(std::cin >> el) {
		data.push_back(el);
    }
}

void sort (std::vector<int>& data){ 
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(data.begin(), data.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
}

void print_sorted_data(std::vector<int>& data){ 
    
    for(auto& it : data){
	    std::cout << it << std::endl;
    }    
}

int main ( int argc, char *argv[]) { 
    std::vector<int> data;
    get_data(data); 
    sort(data); 
    //print_sorted_data(data);
}