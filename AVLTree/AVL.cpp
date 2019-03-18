#include <iostream>
#include <fstream>

struct Node {
     std::string key;
     Node* left;
     Node* right;
     int height;

     Node(std::string key) {
          this->key = key;
          this->left = nullptr;
          this->right = nullptr;
          this->height = 1;
     }
};

class AVLTree {
     private:
          Node* root;
          int numberOfNodes;

          int getHeight(Node* node) {
               if(node == nullptr) return 0;
               return node->height;
          }

          int depth(Node *node) {
               if (node == nullptr)
                    return 0;
               else {
                    int leftHeight = depth(root->left);
                    int rightHeight = depth(root->right);

                    if (leftHeight > rightHeight) return leftHeight + 1;
                    else return rightHeight + 1;
               }
          }
     public:
          AVLTree(): root(nullptr), numberOfNodes(0) { }

          int depth() {
               return depth(this->root);
          }

          int size() {
               return numberOfNodes;
          }

          int getBalance(Node * node) {
               if(node != nullptr)
                    return getHeight(node->left) - getHeight(node->right);
               return 0;
          }

          Node* rightRotate(Node* node) {
               Node* nodeLeft = node->left;
               Node* temp = nodeLeft->right;

               nodeLeft->right = node;
               node->left = temp;
               
               node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
               nodeLeft->height = std::max(getHeight(nodeLeft->left), getHeight(nodeLeft->right)) + 1;

               return nodeLeft;
          }

          Node* leftRotate(Node* node) {
               Node* nodeRight = node->right;
               Node* temp = nodeRight->left;

               nodeRight->left = node;
               node->right = temp;

               node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
               nodeRight->height = std::max(getHeight(nodeRight->left), getHeight(nodeRight->right)) + 1;

               return nodeRight;
          }
          
          Node* search(std::string s) {
               return search(root, s);
          }

          Node *search(Node *node, std::string x) {
               if (node == nullptr)
                    return node;
               int compare = x.compare(node->key);
               if (compare == 0)
                    return node;
               if (compare < 0)
                    return search(node->left, x);
               else
                    return search(node->right, x);
          }

          void setRoot(Node* newRoot) {
               this->root = newRoot;
          }

          Node* insert(Node* node, std::string x) {
               if (node == nullptr) {
                    node = new Node(x);
                    numberOfNodes++;
                    return node;
               }
               
               if (node->key.compare(x) <= 0) 
                    node->right = insert(node->right, x);
               else node->left = insert(node->left, x);

               node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

               int balance = getBalance(node);

               if(balance > 1) {
                    if(x.compare(node->left->key) > 0) 
                         node->left = leftRotate(node->left); // left left rotate 
                    return rightRotate(node); // left right rotate
               }
               if(balance < -1) {
                    if(x.compare(node->right->key) < 0)
                         node->right = rightRotate(node->right); // right right rotate
                    return leftRotate(node); // right left rotate
               }
               return node;
          }

          void printInOrder(Node* node) {
               if(node != nullptr) {
                    printInOrder(node->left);
                    std::cout << node->key << std::endl;
                    printInOrder(node->right);
               }
          }

          void printInOrder() {
               printInOrder(root);
          }


};

int main(){ 
     std::ios_base::sync_with_stdio(false);
     Node* root = nullptr;
     AVLTree d;
     std::string new_word;
     std::ifstream file;
     file.open("words6.txt"); 
     
     while(file >> new_word) {
          root = d.insert(root, new_word);
     }
     std::cout << std::endl << "Dictionary of " << d.size() << " words" << std::endl;

     d.setRoot(root);
     file.close();
     std::cout << "Check word: ";
     while(std::cin >> new_word) {
          if (new_word == "q") break;
          Node* result = d.search(root, new_word);
          if (result == nullptr)
               std::cout << "No :(" << std::endl;
          else 
               std::cout << "Yes!" << std::endl;
          std::cout << "Check word: ";
     }

     return 0;
}
