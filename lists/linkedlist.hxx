#ifndef LINKEDLIST_HXX
#define LINKEDLIST_HXX
#include <iostream>
 
class linkedlist { 

    struct Node {       
        int x;          
        Node* prev;     
        Node* next;     
    };
    private:
        Node main; 
        using position_t = Node*;

    public:
        linkedlist() {
            main.x = 0;
            main.prev = &main;
            main.next = &main;
        }
        void push_front(int x);                     // Wstawia element na początek listy
        int pop_front();                            // Usuwa element z początku listy i zwraca jego wartość
        void push_back(int x);                      // Wstawia element na koniec listy
        int pop_back();                             // Usuwa element z końca listy  i zwraca jego wartość
        position_t find(int x);                     // Wyszukuje element o wartości `x` i zwraca jego pozyc lub `nullptr`
        position_t erase(position_t pos);           // Usuwa element z pozycji pos i zwraca pozycję za usuwanym elementem
        position_t insert(position_t pos, int x);   // Wstawia element x przed pozycję pos i zwraca pozycję x
        int size();                                 // Zwraca liczbę elementów w liście
        bool empty();                               // Zwraca `true` gdy lista jest pusta
};

void linkedlist::push_front(int x) {
    Node *p = new Node(); 
    p->x = x;
    p->next = main.next; 

    main.next = p; 
    p->next->prev = p; 
    p->prev = &main; 
    main.x++; 
}

int linkedlist::pop_front() {
    int x = main.next->x; 
    main.next = main.next->next; 
    main.next->prev = &main; 
    main.x--;
    return x; 
}

void linkedlist::push_back(int x) {
    Node *p = new Node(); 
    p->x = x; 
    p->next = &main;
    main.prev->next = p; 
    p->prev = main.prev; 
    main.prev = p;
    main.x++; 
}

int linkedlist::pop_back() {
    int x = main.prev->x; 
    main.prev = main.prev->prev; 
    main.prev->next = &main; 
    main.x--;
    return x; 
}

linkedlist::position_t linkedlist::find(int x) {
    for ( Node* i = main.next; i != &main; i = i->next){ 
        if ( i->x == x ){  
            return i; 
        }
    }
    return nullptr; 
}

linkedlist::position_t linkedlist::erase(position_t pos) {
    for ( Node* i = main.next; i != &main; i = i->next){ 
        if ( i == pos ){  
            i->next->prev = i->prev; 
            i->prev->next = i-> next;
            main.x--;
            return pos; 
        }
    }
    return nullptr; 
}

linkedlist::position_t linkedlist::insert(position_t pos, int x) {
    for ( Node* i = main.next; i != &main; i = i->next){ 
        if ( i == pos ){  
            Node *p = new Node(); 
            p->x = x;
            p->next = i; 
            i->prev->next = p; 
            p->prev = i->prev; 
            i->prev = p; 
            main.x++; 
            return p;
        }
    }
    return nullptr; 
}

int linkedlist::size() {
    return main.x; 
}

bool linkedlist::empty() {
    if (main.x == 0) { 
        return true; 
    }
    return false; 
}

#endif