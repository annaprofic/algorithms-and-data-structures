#ifndef SortedLinkedList_HXX
#define SortedLinkedList_HXX
#include <iostream>
 
class SortedLinkedList { 

    struct Node {       
        int x;          
        Node* prev;     
        Node* next;     
    };
    private:
        Node main; 
        using position_t = Node*;

    public:
        SortedLinkedList() {
            main.x = 0;
            main.prev = &main;
            main.next = &main;
        }
    
        void push(int x);   // Wstawia element 'x'
        int pop();          // Zwraca i usuwa pierwszy (najmniejszy) element
        int erase(int i);   // Usuwa element na pozycji 'i' i zwraca jego wartość
        int find(int x);    // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
        int size () const;         // Zwraca liczbę elementów w liście
        void remove(int x); // Usuwa wszystkie elementy równe 'x'
        static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);
                            // Scala dwie posortowane listy i zwraca posortowaną listę
        void unique();      // Usuwa sąsiadujące duplikaty
        void print();       // Wypisuje elementy listy w porządku rosnącym
};

void SortedLinkedList::push(int x) {

    switch (size()){

        case 0: {
            Node *p = new Node(); 
            p->x = x;
            p->next = main.next; 

            main.next = p; 
            p->next->prev = p; 
            p->prev = &main; 
            main.x++; 
            break; 
        }

        default: 
            Node *i = new Node(); 
            for (i = main.next; i != &main; i = i->next) { 
                if (x < i->x ){ 
                   break;     
                }
            }
            Node *p = new Node(); 
            p->x = x;
            p->next = i; 
            i->prev->next = p; 
            p->prev = i->prev; 
            i->prev = p;
            main.x++; 
            break; 
    }
}

int SortedLinkedList::pop() {
    int x = main.next->x; 
    main.next = main.next->next; 
    main.next->prev = &main; 
    main.x--;
    return x; 
}

int SortedLinkedList::find(int x) {
    int it = 0; 
    for ( Node* i = main.next; i != &main; i = i->next, it++){ 
        if ( i->x == x ){ 
            return it; 
        }
    }
    return -1; 
}

int SortedLinkedList::erase(int pos) {
    int it = 0; 
    for ( Node* i = main.next; i != &main; i = i->next, it++){       
        if ( it == pos ){  
            i->next->prev = i->prev; 
            i->prev->next = i-> next;
            main.x--;
            return i->x; 
        }
    }
    return -1; 
}

void SortedLinkedList::remove(int x) { 
    int pos = 0;  
    while((pos = find(x)) != -1) { 
        erase(pos); 
    }
}

void SortedLinkedList::unique(){ 
    for ( Node* i = main.next; i != &main; i = i->next){   
        if (i->x == i->next->x) {
            i->next->prev = i->prev; 
            i->prev->next = i-> next;
            main.x--; 
        }   
    }
}

void SortedLinkedList::print() { 
    for ( Node* i = main.next; i != &main; i = i->next){ 
        std::cout << i->x << " " << std::flush; 
    }
    std::cout << std::endl;
}

int SortedLinkedList::size() const {
    return main.x; 
}

SortedLinkedList SortedLinkedList::merge(const SortedLinkedList& a, const SortedLinkedList& b){
    SortedLinkedList new_list;    
    if (a.size() + b.size() == 0){ 
        std::cout << "List is empty." << std::endl; 
    } 
    else {
        for (Node* i = a.main.next; i != &a.main; i = i->next) { 
            new_list.push(i->x); 
        }

        for (Node* i = b.main.next; i != &b.main; i = i->next) { 
            new_list.push(i->x); 
        }
    }
    return new_list; 
}
    


#endif