#include <iostream> 
#include <string>
template <typename T, int N>
class Stack {

    private: 
        T data[N]; 
        T head; 
             
    public:

        Stack() { 
            head = -1; 
        }

        void push (T x) { 
            if (head < N - 1) {     // sprawdzamy czy jest jeszcze miejsce na stosie 
                data[head ++] = x;  // jezeli jest - wrzucamy element na stos 
            } 
            else {    
                std::cerr << "Stack is full." << std::endl;
            }
        }

        T pop() { 
            if (head == -1) { 
                std::cerr << "Stack is empty." << std::endl;
            } 
                head --;
                return data[head];
        }

        T& top() { 
            return data[head];
        }

        T size() { 
            T size = head + 1;
            return size;
        }

        bool empty() { 
            if (head == -1) { 
                return true; 
            } 
            else { 
                return false; 
            }
        }
};


int main(int argc, const char *argv[]) { 
    std::string arg;
    int el = 0; 

    Stack<int, 1000000> stack; 

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
                    std::cout << "Pop: " << stack.pop()  << std::endl;    
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