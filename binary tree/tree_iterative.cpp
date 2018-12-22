#include <iostream>
#include "binary_tree.hpp"
#include <stack>

void print_inorder(BinaryTree::Node *root) { 
    std::stack<BinaryTree::Node *> stack; 
    BinaryTree::Node *node = root; 
  
    while (node != nullptr || stack.empty() == false) { 
        while (node != nullptr) { //jak najbardziej lewe dzieci 
            stack.push(node); 
            node = node->left; 
        } 
        node = stack.top(); 
        stack.pop(); 
  
        std::cout << node->x << " " <<std::flush; 
        node = node->right; 
  
    } 
} 

int main(int argc, char *argv[]) { 
    std::string arg; 
    int size = atoi(argv[1]);   
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
    print_inorder(bt.get_root()); 
}
  