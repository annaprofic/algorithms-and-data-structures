#include <iostream> 

class Queue { 

    private: 
        int head; 
        int tail;
        int *buff; 
        int elements; 
        int size_b; 


    public: 
        Queue(int fullsize): head(0), tail(0), elements(0), size_b(fullsize) { 
            buff = new int[fullsize]; 
        }

        void push( int x) { 

            if ( size() == size_b) { 
                std::cout << "Queue is full!" << std::endl;
            }

            if (tail == size_b) {       // cyklicznosc bufora - kiedy tail (koniec) jest rowny rozmiarowi tablicy przypisujemy go na 0; 
                tail = 0;
            }

            buff[tail] = x;             // wstawiamy element do kolejki 
            elements ++;                // ilosc elementow sie zwiekszyla
            tail ++;                    // ziwekszamy tail 

        }

        int pop() { 

            if (empty() == true){       // sprawdzamy czy kolejka jest pusta 
                std::cout << "Queue is empty!" << std::endl;
                return -1;              // zwracamy blad 
            }  
            elements --;                // po zdejmowaniu elementa zwracamy blad 
            return buff[head ++];       //  przechodzimy do nastepnego head ziekszamy o 1
            
        }

        int& front() { 
            return buff[head]; 
        }

        int size() { 
            return elements; 
        }

        bool empty() { 
            if (elements == 0) 
                return true; 
            return false; 
        }

}; 


int main(int argc, char *argv[]) { 

    std::string arg;
        int el = 0; 

        Queue queue(1000000); 

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
                        std::cout << "Pop: " << queue.pop()  << std::endl;    
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