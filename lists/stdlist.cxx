#include <iostream>
#include <string>
#include <list>

int main() { 
    std::string line; 
    int element = 0; 
    std::list<int> list;
    while (std::cin >> line) { 
        switch (line.at(0)) {
            case 'F': 
                std::cin >> line; 
                element = stoi(line); 
                std::cout << "Push front: " << element << std::endl; 
                list.push_front(element); 
                break;  
            case 'B': 
                std::cin >> line; 
                element = stoi(line); 
                std::cout << "Push back: " << element << std::endl; 
                list.push_back(element); 
                break;  
            case 'f': 
                if (!list.empty()) { 
                    std::cout << "Pop front: " << list.front()  << std::endl;    
                    list.pop_front();
                }
                else 
                    std::cout << "EMPTY" << std::endl;
                break; 
            case 'b':  
                if (!list.empty()) { 
                    std::cout << "Pop back: " << list.back()  << std::endl;    
                    list.pop_back();
                }
                else 
                    std::cout << "EMPTY" << std::endl;
                break;
            case 'C': {
                std::cin >> line; 
                element = stoi(line); 
                std::cout << "Find " << element; 
                std::list<int>::iterator i;
                std::string check; 
                 for (i = list.begin(); i != list.end(); i++) {
                    if (*i == element) {
                        std::cout << " : true" << std::endl;
                        check = "ok"; 
                    }
                }
                if (!(check == "ok"))
                    std::cout <<  " : false" << std::endl; 
                break;
            }
            case 'S': 
                std::cout << "Size: " << list.size() << std::endl; 
                break; 
            
        }
    }
}