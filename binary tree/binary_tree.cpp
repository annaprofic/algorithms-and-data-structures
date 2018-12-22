#include <iostream>
#include "binary_tree.hpp"

int main(int argc, char *argv[]) { 
    std::string arg; 
    std::cin >> arg; 
    int size = stoi(arg); 
    int* data = new int[size]; 
    int el = 0; 
    BinaryTree bt; 
    for (int i = 0; i < size; i++){
        std::cin >> arg; 
        el = stoi(arg); 
        data[i] = el; 
    }
    for (int i = 0; i < size; i++) { 
        bt.insert(data[i]); 
    }
    bt.print_inorder(bt.root); 
    std::cout << bt.size() << " " << bt.depth(bt.root) << " " << bt.minimum() << " " << bt.maximum() << std::endl; 
    for (int i = 1; i < 11; i++) { 
        if (bt.search(bt.root, i) != nullptr) std::cout << "Yes" << std::endl; 
        else std::cout << "Nos" << std::endl; 
    }
}