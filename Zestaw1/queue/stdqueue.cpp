#include <iostream>
#include <queue> 

int main(int argc, char *argv[]) { 
    std::string arg;
    int el = 0; 

    std::queue<int>queue; 

    while (std::cin >> arg) { 
        switch ( arg[0] ) { 

            case 'A': // push
                std::cin >> arg; 
                el = stoi(arg); 
                std::cout << "Push: " << el << std::endl; 
                queue.push(el); 
                break;  
            case 'D' :  // pop
                if ( queue.empty()) { 
                    std::cout << "Queue is empty" << std::endl; 
                } else { 
                    std::cout << "Pop: " << queue.front()  << std::endl;  
                    queue.pop();    
                }
                break; 
            case 'S': //size
                std::cout << "Size: " << queue.size() << std::endl;
                break;
            case 'F':
                std::cin >> arg; 
                break; 
        }
    }
}