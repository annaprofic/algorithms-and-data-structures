#ifndef CURSORLIST_HXX
#define CURSORLIST_HXX
#include <iostream>

using position_t = int; 

class CursorList { 
    
    struct node {       // Zagnieżdżona klasa węzła
        int x;          // Element przechowywany przez węzeł listy
        int next;       // Indeks kolejnego węzła
    };

    private: 
        node *arr;        // Tablica węzłów
        int head;         // Indeks pierwszego węzła
        int size_;        // Ew. rozmiar listy
        int free;         // Ew. indeks pierwszego nieużytego elementu tablicy
        int max_size;

    public: 
        CursorList(int s): head(-1), size_(0), free(0), max_size(s) { 
            arr = new node[s];
            for ( int i = 0; i < s; i++){
                arr[i].next = i+1;
                arr[i].x = 0; 
            }
            arr[s-1].next = -1;
        }
        ~CursorList(){ 
            delete arr; 
        }

        void push_front(int x);                     // Wstawia element na początek listy
        int pop_front();                            // Usuwa element z początku listy i zwraca jego wartość
        void push_back(int x);                      // Wstawia element na koniec listy
        int pop_back();                             // Usuwa element z końca listy  i zwraca jego wartość
        position_t find(int x);                     // Wyszukuje element o wartości `x` i zwraca jego poz lub `nullptr`
        position_t erase(position_t pos);           // Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
        position_t insert(position_t pos, int x);   // Wstawia element x przed pozycję pos i zwraca pozycję x
        int size();                                 // Zwraca liczbę elementów w liście
        bool empty();                               // Zwraca `true` gdy lista jest pusta      

        
        //void print();  
        //void printWholeArray(); 
};

void CursorList::push_front(int x) { 
    if (size_ < max_size){
        arr[free].x = x;
        int saved_free = arr[free].next; 
        arr[free].next = head; 
        head = free; 
        free = saved_free;
        size_ ++;
    }
}

void CursorList::push_back(int x) {
    if (size_ == 0) {
        head = free; 
        arr[head].x = x; 
        free = arr[free].next;
        arr[head].next = -1;
        size_++;
    } else if (size_ < max_size) { 
        int x_pos = free; 
        arr[free].x = x; 
        int saved_free = arr[free].next; 
        free = saved_free; 
        for( int i = head; i != -1; i = arr[i].next) { 
            if (arr[i].next == -1) { 
                arr[i].next = x_pos; 
                arr[x_pos].next = -1;
            }
        }
        size_++;
    }
}

int CursorList::pop_front() { 
    int deleted = arr[head].x; 
    int saved_head = arr[head].next;
    arr[head].next = free; 
    free = head; 
    head = saved_head;
    size_ --; 
    return deleted; 

}

int CursorList::pop_back() { 
    if (size_ == 1) { 
        
        int deleted = arr[head].x;
        arr[head].x = 0; 
        arr[head].next = free; 
        free = head; 
        head = -1; 
        size_ --;
        return deleted; 
    }
    if (size_ > 1 && size_ < max_size){
        int saved_free = free;
        for (int i = head, j = arr[i].next; i != -1; i = arr[i].next, j = arr[j].next) { 
            if (arr[j].next == -1) { 
                int deleted = arr[j].x; 
                arr[i].next = -1; 
                arr[j].next = saved_free; 
                free = j; 
                size_ --;
                return deleted; 
            }
        }
    }
    return -1; 
}

position_t CursorList::erase(position_t pos) { 
    if (head == pos) { 
        pop_front(); 
        return -1;
    }
    if (head != pos && size_ < max_size){ 
        for (int i = head; i != -1; i = arr[i].next) { 
            if (arr[i].next == pos){ 
                arr[i].next = arr[pos].next;
                arr[pos].next = free; 
                free = pos; 
                size_ --; 
                return arr[i].next; 
            }
        }
    }
    return -1;
}

position_t CursorList::insert(position_t pos, int x) { 
    if (head == pos) { 
        push_front(x); 
        return head; 
    }
    if (head != pos && size_ < max_size) { 
        int saved_free = arr[free].next; 
        int x_pos = free;
        arr[free].x = x; 
        for (int i = head; i != -1; i = arr[i].next) { 
            if (arr[i].next == pos) { 
                arr[free].next = arr[i].next; 
                arr[i].next = free; 
                free = saved_free; 
                size_ ++; 
                return x_pos; 
            }
        }
    }
    return -1; 
}

position_t CursorList::find(int x) { 
    if (!empty()) { 
        for (int i = head; i != -1; i = arr[i].next){ 
            if (arr[i].x == x){ 
                return i; 
            }
        }
    }
    return -1; 
}

int CursorList::size() { 
    return size_;
}

bool CursorList::empty() { 
    if (head == -1) { 
        return true; 
    }
    return false; 
}

// void CursorList::print() {
//     for(int i = head; i != -1; i = arr[i].next) {
//         std::cout << arr[i].x << " " << std::flush;
//     }
//     std::cout << std::endl;
// }
// void CursorList::printWholeArray() {

//      std::cout << "\nHead: " << head << "\nFree: " << free << std::endl;
//      for(int i = 0; i < max_size; i++) {
//           std::cout << "[" << arr[i].x << "|" << arr[i].next << "] " << std::flush;
//      }
//      std::cout << std::endl;
// }

#endif