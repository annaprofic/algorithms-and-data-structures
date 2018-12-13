#include <iostream>
#include "linkedlist.hxx"

int main(int argc, char *argv[]) { 
    linkedlist list; 
    std::string arg;
    int el = 0; 

    while (std::cin >> arg) { 
        switch ( arg[0] ) { 

            case 'F': 
                std::cin >> arg; 
                el = stoi(arg); 
                std::cout << "Push front: " << el << std::endl; 
                list.push_front(el); 
                break;  
            case 'B': 
                std::cin >> arg; 
                el = stoi(arg); 
                std::cout << "Push back: " << el << std::endl; 
                list.push_back(el); 
                break;  
            case 'f' :  
                if (!list.empty()) { 
                    std::cout << "Pop front: " << list.pop_front()  << std::endl;    
                }
                else 
                    std::cout << "EMPTY" << std::endl;  
                break; 
            case 'b' :  
                if (!list.empty()) { 
                    std::cout << "Pop back: " << list.pop_back()  << std::endl;    
                } 
                else 
                    std::cout << "EMPTY" << std::endl;  
                break; 
            case 'C': 
                std::cin >> arg; 
                el = stoi(arg); 
                std::cout << "Find " << el; 
                if (list.find(el) == nullptr)
                    std::cout << " : false" << std::endl;  
                else 
                    std::cout << " : true" << std::endl;
                break;
            case 'S':
                std::cout << "Size: " << list.size() << std::endl; 
                break; 
        }
    }

}