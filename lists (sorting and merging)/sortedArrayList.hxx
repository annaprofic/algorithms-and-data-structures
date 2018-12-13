#ifndef SORTEDARRAYLIST_HXX
#define SORTEDARRAYLIST_HXX
#include <iostream>


class SortedArrayList {

    private:
        int max_size, size_;
        int *arr;

    public: 
        SortedArrayList(int s): max_size(s), size_(0) { 
            arr = new int[s];
            for ( int i = 0; i < s; i++){
                arr[i] = 0; 
            }
        }
        ~SortedArrayList(){ 
            delete arr; 
        }

        void push(int x);   // Wstawia element 'x'
        int pop();          // Zwraca i usuwa pierwszy (najmniejszy) element
        int erase(int i);   // Usuwa element na pozycji 'i' i zwraca jego wartość
        int find(int x);    // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
        int size() const;   // Zwraca liczbę elementów w liście
        void remove(int x); // Usuwa wszystkie elementy równe 'x'
        static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);
                            // Scala dwie posortowane listy i zwraca posortowaną listę
        void unique();      // Usuwa sąsiadujące duplikaty
        void print();       // Wypisuje elementy listy w porządku rosnącym
        
}; 

void SortedArrayList::push(int x) { 

    if (size_ == max_size){ 
        std::cout << "List is full" << std::endl;
    }
    else { 
        int i = size_ - 1; 
        for (i = size_ - 1; x < arr[i] && i >= 0; i --) {
            arr[i + 1] = arr[i]; 
        }
        arr[i + 1] = x; 
        size_ ++; 
    } 
}

void SortedArrayList::unique() {

    for (int i = 0; i < size_-1; i++) { 
        if (arr[i] == arr[i+1]) { 
            for (int j = i; j < size_-1; j++){
                arr[j] = arr[j+1];
            }
            size_--; 
            i--;     
        } 
    }        

}

int SortedArrayList::pop() { 
    int del = arr[0]; 
    for (int i = 1; i < size_; i++) { 
        arr[i-1] = arr[i]; 
    } 
    size_ --; 
    return del; 
    
}       

int SortedArrayList::find(int x) { 
    for(int i = 0; i < size_; i++ ) {
        if((arr[i]) == x) {
            return i; 
        }
    }
    return -1; 
}  

void SortedArrayList::remove(int x){
    int pos = 0; 
    while((pos = find(x)) != -1 ){
        for (int i = pos; i < size_; i++){
            arr[i] = arr[i+1]; 
        }
        size_--;   
    }  
}
            
int SortedArrayList::erase(int x) { 
    if (!(size_ == 0) && x < size_ && x >= 0) {
        for (int i = x; i < size_; i ++) { 
            arr[i] = arr[i + 1]; 
        }  
        size_ --;  
        return x + 1;
    } 
    return -1;
}       

int SortedArrayList::size() const {
    return size_; 
} 

void SortedArrayList::print() {   
    for(int i = 0; i < size_; i++) {
        std::cout <<  arr[i] << " " << std::flush;
    }
    std::cout << std::endl;

}

SortedArrayList SortedArrayList::merge(const SortedArrayList& a, const SortedArrayList& b){
    SortedArrayList new_list(a.size() + b.size());  

    if (a.size() + b.size() == 0){ 
        std::cout << "List is empty." << std::endl; 
    } 

    else {
        for (int i = 0; i < a.size(); i++) { 
            new_list.push(a.arr[i]); 
        }

        for (int i = 0; i < b.size(); i++) { 
            new_list.push(b.arr[i]); 
        }
    }
    return new_list; 
}
                                                     

#endif