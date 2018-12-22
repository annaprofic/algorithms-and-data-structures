#include <iostream>
#include <cmath> 

class BinaryTree { 
    
    public: 
        struct Node { 
            Node* left; 
            Node* right; 
            int x; 
        }; 
    
        void insert(int x);  // wstawia element ‘x’ do drzewa
        Node* get_root(); 
        Node* search(Node* node, int x); 
        Node* search_recursive(Node* node, int x);  // sprawdza czy element należy do drzewa, zwraca wskaźnik do węzła lub nullptr.
        int size(); // zwraca liczbę węzłów
        int minimum(); // zwraca wartość najmniejszego elementu
        int maximum(); // zwraca wartość największego elementu
        int depth(Node* node); // zwraca wysokość drzewa
        void print_inorder(Node* node); 
        void print_preorder(Node* node); 
        void print_postorder(Node* node); // wypisuje zawartość wszystkich węzłów odpowiednio w porządku: inorder, preorder i postorder. 
        
        Node* root; 
        int nodes_number; 
        bool done; 

        BinaryTree(): nodes_number(0) {
            root = nullptr; 
        }
}; 

BinaryTree::Node* BinaryTree::get_root(){ 
    return root; 
}

int BinaryTree::size(){ 
    return nodes_number; 
}

void BinaryTree::insert(int x){ 

    Node* node = new Node(); 
    node->x = x; 
    node->left = nullptr; 
    node->right = nullptr; 

    if (root == nullptr) { 
        root = node; 
        nodes_number++; 
    }
    else { 
        Node* iterator = root; 
        Node* parent = nullptr; 

        while(iterator != nullptr) {
            parent = iterator; 
            if (x < iterator->x) iterator = iterator->left; 
            else iterator = iterator->right; 
        }  
        iterator = new Node(); 
        iterator->left = nullptr; 
        iterator->right = nullptr; 
        iterator->x = x; 
        nodes_number++; 
        if (x < parent->x) parent->left = iterator; 
        else if (x > parent->x) parent->right = iterator; 
    }
}

BinaryTree::Node* BinaryTree::search(Node* node,int x){
    while (node != nullptr && x != node->x) { 
        if (x < node->x) node = node->left; 
        if (x > node->x) node = node->right; 
    }
    return node; 
}

BinaryTree::Node* BinaryTree::search_recursive(Node* node, int x){
    if (node == nullptr || x == node->x) return node; 
    if (x < node->x) return search_recursive(node->left, x); 
    else return search_recursive(node->right, x); 
}

int BinaryTree::depth(Node* node){ 

    if(node == nullptr) return 0; 

    int left = depth(node->left); 
    int right = depth(node->right); 

    return 1 + std::max(left, right); 
}

int BinaryTree::maximum(){ 
    Node* node = root; 
    while(node->right != nullptr) node = node->right;
    return node->x; 
}

int BinaryTree::minimum(){ 
    Node* node = root; 
    while(node->left != nullptr) node = node->left;
    return node->x; 
}

void BinaryTree::print_inorder(Node* node){  
    if (node != nullptr) {
        print_inorder(node->left);
        std::cout << node->x <<std::endl;   
        print_inorder(node->right ); 
    }
}

void BinaryTree::print_preorder(Node* node){ 
    if (node != nullptr) {
        std::cout << node->x <<std::endl;
        print_inorder(node->left);
        print_inorder(node->right ); 
    }
}

void BinaryTree::print_postorder(Node* node){ 
    if (node != nullptr) {
        print_inorder(node->left);   
        print_inorder(node->right); 
        std::cout << node->x <<std::endl;
    }
}

