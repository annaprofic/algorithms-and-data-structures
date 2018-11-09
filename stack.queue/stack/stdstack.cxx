#include <iostream> 
#include <string>
#include <stack> 



int main(int argc, char *argv[]) { 
    std::string arg;
    int el = 0; 

    std::stack<int>stack; 

    while (std::cin >> arg) { 
        switch ( arg[0] ) { 

            case 'A': // push
                std::cin >> arg; 
                el = stoi(arg); 
                std::cout << "Push: " << el << std::endl; 
                stack.push(el); 
                break;  
            case 'D' :  // pop
                if ( stack.empty()) { 
                    std::cout << "Stack is empty" << std::endl; 
                } else { 
                    std::cout << "Pop: " << stack.top()  << std::endl;  
                    stack.pop();  
                }
                break; 
            case 'S': //size
                std::cout << "Size: " << stack.size() << std::endl;
                break;
             case 'F':
                std::cin >> arg; 
                break; 
        }
    }
}